#include <iostream>
#include <stack>
#include <string>
#include <cctype>
#include <algorithm> // For reverse()

using namespace std;

// Function to check precedence of operators
int precedence(char op) {
    if (op == '^')
        return 3;
    if (op == '*' || op == '/')
        return 2;
    if (op == '+' || op == '-')
        return 1;
    return 0;
}

// Function to convert input expression to postfix expression
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

int main() {
    string input;

    cout << "\nEnter the Expression: ";
    getline(cin, input);

    string output = inputToPrefix(input);

    cout << "Prefix Expression: " << output << endl;


    return 0;
}
