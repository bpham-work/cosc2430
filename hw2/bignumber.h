#ifndef BIG_NUMBER_H
#define BIG_NUMBER_H

#include <string>
#include <algorithm>
#include "stack.h"
using namespace std;

class BigNumber {
    bool isNegative;
    string num = "0";
    public:
        BigNumber(string num);
        string getNum();
        bool isNeg();
        int size();
        BigNumber operator+(BigNumber& num2);
        BigNumber operator-(BigNumber& num2);
        BigNumber operator*(BigNumber& num2);
    private:
        void dumpDigits(Stack<int>& digits, int& carryover, string& sum);
};

BigNumber::BigNumber(string num) {
    if (num[0] == '-' || num[0] == '+') {
        isNegative = num[0] == '-' ? true : false;
        num.erase(0, 1);
    }
    num.erase(0, min(num.find_first_not_of('0'), num.size()-1));
    this->num = num;
}

string BigNumber::getNum() {
    return num;
}

bool BigNumber::isNeg() {
    return isNegative;
}

int BigNumber::size() {
    return num.size();
}

void BigNumber::dumpDigits(Stack<int>& digits, int& carryover, string& sum) {
    while (!digits.isEmpty()) {
        int digit = digits.pop();
        digit += carryover;
        if (digit > 9) {
            carryover = 1;
            digit %= 10;
        } else {
            carryover = 0;
        }
        sum.insert(0, to_string(digit));
    }
}

BigNumber BigNumber::operator+(BigNumber& num2) {
    Stack<int> num1Digits;
    Stack<int> num2Digits;
    for (int i = 0; i < num.length(); i++) num1Digits.push(num[i]-48);
    for (int i = 0; i < num2.size(); i++) num2Digits.push(num2.getNum()[i]-48);
    string sum = "";
    int carryover = 0;
    while (!num1Digits.isEmpty() && !num2Digits.isEmpty()) {
        int digit1 = num1Digits.pop();
        int digit2 = num2Digits.pop();
        int digit3 = digit1 + digit2 + carryover;
        if (digit3 > 9) {
            carryover = 1;
            digit3 %= 10;
        } else {
            carryover = 0;
        }
        sum.insert(0, to_string(digit3));
    }
    dumpDigits(num1Digits, carryover, sum);
    dumpDigits(num2Digits, carryover, sum);
    if (carryover == 1) {
        sum.insert(0, "1");
    }
    BigNumber result(sum);
    return result;
}

#endif
