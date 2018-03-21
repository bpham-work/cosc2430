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
        BigNumber(string num, bool isNeg);
        string getNum();
        bool isNeg();
        void setNeg(bool isNeg);
        int size();
        bool isZero();
        bool absGte(BigNumber& num2);
        BigNumber clone();
        BigNumber operator+(BigNumber& num2);
        BigNumber operator-(BigNumber& num2);
        BigNumber operator*(BigNumber& num2);
        BigNumber operator/(BigNumber& num2);
        BigNumber operator--(int num2);
    private:
        void dumpDigits(Stack<int>& digits, int& carryover, string& sum);
        void dumpDigitsSub(Stack<int>& digits, bool borrow, string& diff);
};

BigNumber::BigNumber(string num) {
    if (num[0] == '-' || num[0] == '+') {
        isNegative = num[0] == '-' ? true : false;
        num.erase(0, 1);
    }
    num.erase(0, min(num.find_first_not_of('0'), num.size()-1));
    this->num = num;
}

BigNumber::BigNumber(string num, bool isNeg): num(num), isNegative(isNeg) {}

string BigNumber::getNum() {
    return num;
}

bool BigNumber::isNeg() {
    if (num == "0") return false;
    return isNegative;
}

void BigNumber::setNeg(bool isNeg) { isNegative = isNeg; }

int BigNumber::size() {
    return num.size();
}

bool BigNumber::isZero() { return num == "0";  }

bool BigNumber::absGte(BigNumber& num2) {
    if (num.size() > num2.size()) {
        return true;
    } else if (num.size() < num2.size()) {
        return false;
    } else {
        Stack<int> num1Digits;
        Stack<int> num2Digits;
        for (int i = num.size()-1; i >= 0; i--) num1Digits.push(num[i]-48);
        for (int i = num2.size()-1; i >= 0; i--) num2Digits.push(num2.getNum()[i]-48);
        bool isEqual = true;
        while (!num1Digits.isEmpty() && !num2Digits.isEmpty()) {
            if (num1Digits.peek() != num2Digits.peek()) {
                isEqual = false;
            }
            if (num1Digits.pop() > num2Digits.pop()) {
                return true;
            }
        }
        if (isEqual) {
            return true;
        }
        return false;
    }
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

void BigNumber::dumpDigitsSub(Stack<int>& digits, bool borrow, string& diff) {
    while (!digits.isEmpty()) {
        int digit = digits.pop();
        if (borrow) {
            if (digit == 0) {
                digit = 9;
                borrow = true;
            } else {
                digit -= 1;
                borrow = false;
            }
        }
        diff.insert(0, to_string(digit));
    }
}

BigNumber BigNumber::clone() {
    return BigNumber(num, isNegative);
}

BigNumber BigNumber::operator+(BigNumber& num2) {
    if (isNegative && !num2.isNeg() && num2.absGte(*this)) {
        this->setNeg(false);
        BigNumber result = num2 - *this;
        return result;
    } else if (isNegative && !num2.isNeg()) {
        this->setNeg(false);
        BigNumber result = *this - num2;
        result.setNeg(true);
        return result;
    } else {
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
}

BigNumber BigNumber::operator-(BigNumber& num2) {
    if (isNegative && num2.isNeg()) {
        this->setNeg(false);
        num2.setNeg(false);
        BigNumber result = *this + num2;
        result.setNeg(true);
        return result;
    } else if ((isNegative && !num2.isNeg()) || (num == "0" && !num2.isNeg())) {
        this->setNeg(false);
        BigNumber result = *this + num2;
        result.setNeg(true);
        return result;
    } else {
        Stack<int> num1Digits;
        Stack<int> num2Digits;
        for (int i = 0; i < num.length(); i++) num1Digits.push(num[i]-48);
        for (int i = 0; i < num2.size(); i++) num2Digits.push(num2.getNum()[i]-48);
        string diff = "";
        bool borrow = false;
        while (!num1Digits.isEmpty() && !num2Digits.isEmpty()) {
            int digit1 = num1Digits.pop();
            int digit2 = num2Digits.pop();
            if (borrow) {
                digit1 -= 1;
            }
            if (digit1 < digit2) {
                digit1 += 10;
                borrow = true;
            } else {
                borrow = false;
            }
            int digit3 = digit1 - digit2;
            diff.insert(0, to_string(digit3));
        }
        dumpDigitsSub(num1Digits, borrow, diff);
        dumpDigitsSub(num2Digits, borrow, diff);
        BigNumber result(diff);
        return result;
    }
}

BigNumber BigNumber::operator*(BigNumber& num2) {
    BigNumber counter(num2.getNum(), false);
    BigNumber result("0");
    while (counter.getNum() != "0") {
        result = result + *this;
        counter = (counter--);
    }
    if ((isNegative && !num2.isNeg()) || (!isNegative && num2.isNeg())) {
        result.setNeg(true);
    }
    return result; 
}

BigNumber BigNumber::operator/(BigNumber& num2) {
    BigNumber result(num, false);
    BigNumber positiveClone2(num2.getNum(), false);
    int quotient = 0;
    bool resultNeg = false;
    while (result.absGte(num2)) {
        cout << "RESULT: " << result.getNum() << endl;
        cout << "num2: " << num2.getNum() << endl;
        result = result - positiveClone2;
        quotient++;
    }

    if ((isNegative && !num2.isNeg()) || (!isNegative && num2.isNeg())) {
        resultNeg = true;
    }
    return BigNumber(to_string(quotient), resultNeg); 
}

BigNumber BigNumber::operator--(int num2) {
    BigNumber decrement("1");
    return *this - decrement;
}

#endif
