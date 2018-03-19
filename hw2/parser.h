#ifndef PARSER_H
#define PARSER_H

#include "stack.h"
#include <iostream>
#include <sstream>
using namespace std;

class Parser {
    public:
        Parser();
        string parse(string& expression);
        bool isValid(string& expression);
    private:
        int parse(string& exp, int start, stringstream& stream);
        bool isOperator(char character);
        bool isNegativeOperator(int i, string& exp);
        bool isOperand(char character);
        bool isOperandOrCloseParen(char character);
        bool isOperandOrOpenParen(char character);
        bool isParenthesis(char character);
        int priority(char character);
};

Parser::Parser() {}

string Parser::parse(string& exp) {
    if (!isValid(exp)) throw invalid_argument("Invalid expression");
    stringstream stream;
    parse(exp, 0, stream);
    return stream.str();
}

int Parser::parse(string& exp, int i, stringstream& stream) {
    Stack<char> operandStack;
    while (i < exp.length() && exp[i] != ')') {
        if (isParenthesis(exp[i])) {
            i = parse(exp, i+1, stream);
        } else if (isOperand(exp[i]) || isNegativeOperator(i, exp)) {
            stream << exp[i];
        } else if (isOperator(exp[i])) {
            stream << ',';
            while (!operandStack.isEmpty() &&
                    priority(exp[i]) < priority(operandStack.peek())) {
                stream << operandStack.pop();
                stream << ',';
            }
            operandStack.push(exp[i]);
        }
        i++;
    }
    while (!operandStack.isEmpty()) {
        stream << ',';
        stream << operandStack.pop();
    }
    return i;
}

bool Parser::isNegativeOperator(int i, string& exp) {
    if (exp[i] == '-') {
        if (i == 0 || exp[i-1] == '(') {
            return true;
        }
    }
    return false;
}

bool Parser::isValid(string& exp) {
    Stack<char> parenStack;
    if (exp.length() == 0) return false;
    for (int i = 0; i < exp.length(); i++) {
        if (exp[i] == '-' && isOperand(exp[i+1])) {
            continue;
        }
        if (isOperator(exp[i]) &&
                (i == 0 ||
                 i == exp.length()-1 ||
                 !isOperandOrCloseParen(exp[i-1]) ||
                 !isOperandOrOpenParen(exp[i+1]))) {
            return false;
        } else if (exp[i] == '(') {
            parenStack.push('(');
        } else if (exp[i] == ')') {
            if (!parenStack.isEmpty() && parenStack.peek() == '(') {
                parenStack.pop();
            } else {
                return false;
            }
        }
    }
    if (!parenStack.isEmpty()) return false;
    return true;
}

bool Parser::isOperator(char character) {
    return character == '+' ||
        character == '-' ||
        character == '*';
}

bool Parser::isOperand(char character) {
    return !isOperator(character) && !isParenthesis(character);
}

bool Parser::isOperandOrCloseParen(char character) {
    return isOperand(character) || character == ')';
}

bool Parser::isOperandOrOpenParen(char character) {
    return !isOperator(character) || character == '(';
}

bool Parser::isParenthesis(char character) {
    return character == '(' ||
        character == ')';
}

int Parser::priority(char character) {
    int priority = 0;
    switch (character) {
        case '*':
            priority = 1;
            break;
        default:
            priority = 0;
    }
    return priority;
}

#endif
