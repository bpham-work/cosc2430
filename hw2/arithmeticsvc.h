#ifndef ARITHMETIC_SVC_H
#define ARITHMETIC_SVC_H

#include "parser.h"
#include "bignumber.h"
#include "stack.h"
#include <iostream>
#include <string>
using namespace std;

class ArithmeticSvc {
    Parser parser;
    public:
        ArithmeticSvc();
        string evaluate(string exp);
    private:
        bool isOperator(string& elem);
        BigNumber doMath(string& op, BigNumber& num1, BigNumber& num2);
};

ArithmeticSvc::ArithmeticSvc() {
    parser = Parser();
}

string ArithmeticSvc::evaluate(string exp) {
    string postfix = parser.parse(exp);
    int index = 0;
    Stack<BigNumber> nums;
    while (index < postfix.size()) {
        int firstComma = postfix.find(",", index);
        string elem;
        if (firstComma != -1) {
            int length = firstComma - index;
            elem = postfix.substr(index, length);
            index += (length + 1);
            if (!isOperator(elem)) {
                BigNumber num(elem);
                nums.push(num);
            } else {
                BigNumber result = doMath(elem, nums.pop(), nums.pop());
                nums.push(result);
            }
        } else {
            elem = postfix.substr(index);
            BigNumber result = doMath(elem, nums.pop(), nums.pop());
            nums.push(result);
            break;
        }
    }
    return nums.peek().toString();
}

bool ArithmeticSvc::isOperator(string& elem) {
    return elem == "+" || elem == "-" || elem == "*" || elem == "/";
}

BigNumber ArithmeticSvc::doMath(string& op, BigNumber& num1, BigNumber& num2) {
    if (op == "+")
        return num2 + num1;
    else if (op == "-")
        return num2 - num1;
    else if (op == "*")
        return num2 * num1;
    else
        return num2 / num1;
}

#endif
