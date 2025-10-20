#include <iostream>
#include <stack>
#include <string>
#include <cctype>
#include <cmath>
#include <stdexcept>

using namespace std;

// Function to check precedence of operators
int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

int calculation(int a, int b, char op) {
    switch (op) {
    case '+':
        return a + b;
    case '-':
        return a - b;
    case '*':
        return a * b;
    case '/':
        if (b == 0) throw exception("Division by zero");
        return a / b;
    case '^':
        return static_cast<int>(pow(a, b));
    default:
        throw exception("Invalid operator");
    }
}

// Function to convert input expression to prefix expression
string inputToPrefix(string& input) {

    //reverse the infix expression
    reverse(input.begin(), input.end());

    stack<char> Stack;
    string output;
    string num;

    for (int i = 0; i < input.length(); ++i) {
        char ch = input[i];

        if (ch == ' ') continue;

        // If character is an operand push it into the output
        if (isalnum(ch)) {
            if (isdigit(ch)) {
                num += ch;
                if (i + 1 >= input.length() || !isdigit(input[i + 1])) { // checks for numbers greater than 1 digit
                    output += num + " ";
                    num = "";
                }
            }
            else {
                output += ch;
            }
        }
        // If character is an closing parenthesis
        else if (ch == ')') {
            Stack.push(ch);
        }
        // If character is an operator
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^') {
            while (!Stack.empty() && precedence(Stack.top()) >= precedence(ch)) {
                output += Stack.top();
                output += " ";
                Stack.pop();
            }
            Stack.push(ch);
        }
        // If character is a opening parenthesis
        else if (ch == '(') {
            while (!Stack.empty() && Stack.top() != ')') {
                output += Stack.top();
                output += " ";
                Stack.pop();
            }
            Stack.pop();
        }
    }

    // Pop all remaining operators
    while (!Stack.empty()) {
        output += Stack.top();
        output += " ";
        Stack.pop();
    }

    // reverse the output 
    reverse(output.begin(), output.end());

    return output;
}

// Function to calculate the prefix expression
int calculatePrefix(const string& prefix) {
    stack<int> stack;

    for (int i = prefix.length() - 1; i >= 0; --i) {

        if (prefix[i] == ' ') {
            i--;
            continue;
        }

        if (isdigit(prefix[i])) {
            string num;
            while (i < prefix.length() && isdigit(prefix[i])) {
                num += prefix[i--];
            }
            stack.push(stoi(num));
        }

        else if (prefix[i] == '+' || prefix[i] == '-' || prefix[i] == '*' || prefix[i] == '/' || prefix[i] == '^') {
            int a = stack.top();
            stack.pop();
            int b = stack.top();
            stack.pop();
            stack.push(calculation(a, b, prefix[i]));
            i--;
        }
    }

    return stack.top();
}

// Function to validate the input given by the user
bool val_Input(const string& expr) {
    int bracketCount = 0;
    char prevChar = '\0';

    if (expr.empty() || (expr[0] == '+' || expr[0] == '-' || expr[0] == '*' || expr[0] == '/' || expr[0] == '^' || expr[0] == ')')) {
        return false; // Expression starts with an operator, which is invalid
    }

    for (char ch : expr) {
        if (isdigit(ch) || ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^' ||
            ch == '(' || ch == ')' || isspace(ch)) {

            if (ch == '(') bracketCount++;
            if (ch == ')') {
                bracketCount--;
                if (bracketCount < 0)
                    return false; // Found closing bracket without matching opening
            }

            if ((ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^') &&
                (prevChar == '+' || prevChar == '-' || prevChar == '*' || prevChar == '/' || prevChar == '^' || prevChar == '(')) {
                return false; // Found consecutive operator in the expression
            }

            if (!isspace(ch)) prevChar = ch;
        }
        else {
            return false;
        }
    }

    // Return true if all brackets are balanced and the last char is not an operator 
    return bracketCount == 0 && !(prevChar == '+' || prevChar == '-' || prevChar == '*' || prevChar == '/' || prevChar == '^');
}

int main() {
    string input;
    try
    {
        cout << "\nEnter the Expression: ";
        getline(cin, input);

        // Validate the input expression
        while (!val_Input(input)) {
            cout << "\nInvalid expression: Contains invalid characters or syntax.\n";
            cout << "Enter the Expression: ";
            getline(cin, input);
        }

        string output = inputToPrefix(input);

        cout << "Prefix Expression: " << output << endl;

        int result = calculatePrefix(output);

        cout << "Result: " << result << endl;
    }
    catch (const exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
