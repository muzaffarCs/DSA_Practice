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

// Function to convert input expression to postfix expression
string inputToPostfix(string& input) {
    stack<char> Stack;
    string output;
    string num;

    input = "(" + input + ")"; 

    for (int i = 0; i < input.length(); ++i) {
        char ch = input[i];

        if (ch == ' ') continue;

        // If character is a number push it into the output
        if (isdigit(ch)) {
            num += ch;
            if (i + 1 >= input.length() || !isdigit(input[i + 1])) { // for numbers more than 1 digit
                output += num + " ";
                num = "";
            }
        }
        // If character is an opening parenthesis
        else if (ch == '(') {
            Stack.push(ch);
        }
        // If character is a closing parenthesis
        else if (ch == ')') {
            while (!Stack.empty() && Stack.top() != '(') {
                output += Stack.top();
                output += " ";
                Stack.pop();
            }
            Stack.pop(); // Pop '('
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
    }

    // Pop all remaining operators
    while (!Stack.empty()) {
        output += Stack.top();
        output += " ";
        Stack.pop();
    }

    return output;
}

// Function to calculate the postfix expression
int calculatePostfix(const string& postfix) {
    stack<int> stack;
    int i = 0;
    while (i < postfix.length()) {

        if (postfix[i] == ' ') {
            i++;
            continue;
        }

        if (isdigit(postfix[i])) {
            string num;
            while (i < postfix.length() && isdigit(postfix[i])) {
                num += postfix[i++];
            }
            stack.push(stoi(num));
        }

        else if (postfix[i] == '+' || postfix[i] == '-' || postfix[i] == '*' || postfix[i] == '/' || postfix[i] == '^') {
            int a = stack.top();
            stack.pop();
            int b = stack.top();
            stack.pop();
            stack.push(calculation(b, a, postfix[i]));
            i++;
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

        string output = inputToPostfix(input);

        cout << "Postfix Expression: " << output << endl;

        int result = calculatePostfix(output);

        cout << "Result: " << result << endl;
    }
    catch (const exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
