#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <cctype>

using namespace std;

// Helper function to check if a character is an operator
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

// Function to get the precedence of operators
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

// Function to perform infix to postfix conversion
string infixToPostfix(const string &infix) {
    stack<char> operators;
    string postfix;
    
    for (char c : infix) {
        if (isalnum(c)) {
            postfix += c;
        } else if (c == '(') {
            operators.push(c);
        } else if (c == ')') {
            while (!operators.empty() && operators.top() != '(') {
                postfix += operators.top();
                operators.pop();
            }
            operators.pop();  // Pop the '('
        } else if (isOperator(c)) {
            while (!operators.empty() && precedence(operators.top()) >= precedence(c)) {
                postfix += operators.top();
                operators.pop();
            }
            operators.push(c);
        }
    }
    
    while (!operators.empty()) {
        postfix += operators.top();
        operators.pop();
    }
    
    return postfix;
}

// Function to generate three-address code from postfix expression
void generateTAC(const string &postfix) {
    stack<string> operands;
    int tempVarCount = 1;

    for (char c : postfix) {
        if (isalnum(c)) {
            string operand(1, c);
            operands.push(operand);
        } else if (isOperator(c)) {
            string operand2 = operands.top(); operands.pop();
            string operand1 = operands.top(); operands.pop();
            string tempVar = "t" + to_string(tempVarCount++);
            cout << tempVar << " = " << operand1 << " " << c << " " << operand2 << endl;
            operands.push(tempVar);
        }
    }
}

int main() {
    string infixExpression;
    cout << "Enter an arithmetic expression: ";
    getline(cin, infixExpression); // Corrected input reading

    string postfixExpression = infixToPostfix(infixExpression);
    cout << "Postfix Expression: " << postfixExpression << endl;

    cout << "Three Address Code:" << endl;
    generateTAC(postfixExpression);

    return 0;
}


