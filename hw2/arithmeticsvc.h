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
    cout << postfix << endl;
    int index = 0;
    Stack<BigNumber> nums;
    while (index < postfix.size()) {
        int firstComma = postfix.find(",", index);
        string elem = "";
        if (firstComma != -1) {
            int length = firstComma - index;
            elem = postfix.substr(index, length);
            index += (length + 1);
            if (!isOperator(elem)) {
                BigNumber num(elem);
                nums.push(num);
            } else {
                BigNumber second = nums.pop();
                BigNumber first = nums.pop();
                BigNumber result = doMath(elem, second, first);
                nums.push(result);
            }
        } else {
            elem = postfix.substr(index);
            BigNumber second = nums.pop();
            BigNumber first = nums.pop();
            BigNumber result = doMath(elem, second, first);
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
    cout << num2.toString() << " " << op << " " << num1.toString() << endl;
    BigNumber result;
    if (op == "+")
        result = num2 + num1;
    else if (op == "-")
        result = num2 - num1;
    else if (op == "*")
        result = num2 * num1;
    else
        result = num2 / num1;
    cout << num2.toString() << " " << op << " " << num1.toString() << " = " << result.toString() << endl;
    return result;
}

#endif
