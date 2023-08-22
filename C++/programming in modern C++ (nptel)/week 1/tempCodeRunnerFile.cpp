#include <iostream>
#include <stack>
#include <string>
#include <sstream>
using namespace std;

int evaluatePostfix(const string& postfix) {
    stack<int> operandStack;
    istringstream iss(postfix);
    string token;
    
    while (iss >> token) {
        if (isdigit(token[0])) {
            operandStack.push(stoi(token));
        } else {
            int operand2 = operandStack.top();
            operandStack.pop();
            int operand1 = operandStack.top();
            operandStack.pop();
            
            if (token == "+") {
                operandStack.push(operand1 + operand2);
            } else if (token == "-") {
                operandStack.push(operand1 - operand2);
            } else if (token == "*") {
                operandStack.push(operand1 * operand2);
            } else if (token == "/") {
                operandStack.push(operand1 / operand2);
            }
        }
    }
    
    return operandStack.top();
}

int main() {
    string postfixExpression = "3 4 2 * +";
    int result = evaluatePostfix(postfixExpression);
    
    cout << "Postfix Expression: " << postfixExpression << endl;
    cout << "Result: " << result << endl;
    
    return 0;
}