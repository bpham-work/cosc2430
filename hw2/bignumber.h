#ifndef BIG_NUMBER_H
#define BIG_NUMBER_H

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include "stack.h"
using namespace std;

class BigNumber {
    bool isNegative = false;
    string num = "0";
    public:
        BigNumber();
        BigNumber(string num);
        BigNumber(string num, bool isNeg);
        string getNum();
        bool isNeg();
        void setNeg(bool isNeg);
        int size();
        bool isZero();
        bool absGte(BigNumber& num2);
        bool absGt(BigNumber& num2);
        BigNumber clone(bool isNeg = false);
        string toString();
        BigNumber operator+(BigNumber& num2);
        BigNumber operator-(BigNumber& num2);
        BigNumber operator*(BigNumber& num2);
        BigNumber operator/(BigNumber& num2);
        BigNumber operator--(int num2);
    private:
        void dumpDigits(Stack<int>& digits, int& carryover, string& sum);
        void dumpDigitsSub(Stack<int>& digits, bool borrow, string& diff);
};

BigNumber::BigNumber() {}

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

bool BigNumber::isZero() { return num == "0"; }

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
			int num1Digit = num1Digits.pop();
			int num2Digit = num2Digits.pop();
            if (num1Digit > num2Digit) {
                return true;
            } else if (num1Digit < num2Digit) {
				return false;
			}
        }
        if (isEqual) {
            return true;
        }
        return false;
    }
}

bool BigNumber::absGt(BigNumber& num2) {
    if (num.size() > num2.size()) {
        return true;
    } else if (num.size() < num2.size()) {
		return false;
    } else {
        Stack<int> num1Digits;
        Stack<int> num2Digits;
        for (int i = num.size()-1; i >= 0; i--) num1Digits.push(num[i]-48);
        for (int i = num2.size()-1; i >= 0; i--) num2Digits.push(num2.getNum()[i]-48);

        while (!num1Digits.isEmpty() && !num2Digits.isEmpty()) {
			int num1Digit = num1Digits.pop();
			int num2Digit = num2Digits.pop();
            if (num1Digit > num2Digit) {
                return true;
            } else if (num1Digit < num2Digit) {
				return false;
			}
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

BigNumber BigNumber::clone(bool isNeg) {
    return BigNumber(num, isNeg);
}

string BigNumber::toString() {
    if (isNegative) return "-" + num;
    return num;
}

BigNumber BigNumber::operator+(BigNumber& num2) {
    if (isNegative && !num2.isNeg() && num2.absGte(*this)) {
        BigNumber num1PositiveClone = this->clone();
        BigNumber result = num2 - num1PositiveClone;
        return result;
    } else if (!isNegative && num2.isNeg() && this->absGte(num2)) {
        BigNumber num2PositiveClone = num2.clone();
        BigNumber result = *this - num2PositiveClone;
        return result;
    } else if (!isNegative && num2.isNeg() && !(this->absGte(num2))) {
        return num2 + *this;
    } else if (isNegative && num2.isNeg()) {
        BigNumber num2PositiveClone = num2.clone();
        return *this - num2PositiveClone;
    } else if (isNegative && !num2.isNeg()) {
        BigNumber num1PositiveClone = this->clone();
        BigNumber result = num1PositiveClone - num2;
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
    if (num2.isNeg()) {
        BigNumber num2PositiveClone = num2.clone();
        return *this + num2PositiveClone;
    }
	else if ((isNegative && !num2.isNeg()) || (num == "0" && !num2.isNeg())) {
        BigNumber num1PositiveClone = this->clone();
        BigNumber result = num1PositiveClone + num2;
        result.setNeg(true);
        return result;
    } else if (!isNegative && !num2.isNeg() && num2.absGt(*this)) {
		BigNumber result = num2 - *this;
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

BigNumber BigNumber::operator*(BigNumber& num22) {
	string num1 = this->getNum();
	string num2 = num22.getNum();
	int n1 = num1.size();
    int n2 = num2.size();
    if (n1 == 0 || n2 == 0)
       return BigNumber();
 
    // will keep the result number in vector
    // in reverse order
    vector<int> result(n1 + n2, 0);
 
    // Below two indexes are used to find positions
    // in result. 
    int i_n1 = 0; 
    int i_n2 = 0; 
 
    // Go from right to left in num1
    for (int i=n1-1; i>=0; i--)
    {
        int carry = 0;
        int n1 = num1[i] - '0';
 
        // To shift position to left after every
        // multiplication of a digit in num2
        i_n2 = 0; 
         
        // Go from right to left in num2             
        for (int j=n2-1; j>=0; j--)
        {
            // Take current digit of second number
            int n2 = num2[j] - '0';
 
            // Multiply with current digit of first number
            // and add result to previously stored result
            // at current position. 
            int sum = n1*n2 + result[i_n1 + i_n2] + carry;
 
            // Carry for next iteration
            carry = sum/10;
 
            // Store result
            result[i_n1 + i_n2] = sum % 10;
 
            i_n2++;
        }
 
        // store carry in next cell
        if (carry > 0)
            result[i_n1 + i_n2] += carry;
 
        // To shift position to left after every
        // multiplication of a digit in num1.
        i_n1++;
    }
 
    // ignore '0's from the right
    int i = result.size() - 1;
    while (i>=0 && result[i] == 0)
       i--;
 
    // If all were '0's - means either both or
    // one of num1 or num2 were '0'
    if (i == -1)
       return BigNumber();
 
    // generate the result string
    string s = "";
    while (i >= 0)
        s += std::to_string(result[i--]);
	BigNumber res(s);

    if ((isNegative && !num22.isNeg()) || (!isNegative && num22.isNeg())) {
        res.setNeg(true);
    } else {
        res.setNeg(false);
    }
    return res; 
}

BigNumber BigNumber::operator/(BigNumber& num2) {
    BigNumber result = this->clone();
    BigNumber divisorClone = num2.clone();
    cout << result.toString() << " / " << divisorClone.toString() << endl;
    int quotient = 0;
    bool resultNeg = false;
	BigNumber largestDivisor = num2.clone();
	BigNumber temp = num2.clone();
    int power = 1;
    int multiple = 1;
	while (result.absGte(largestDivisor)) {
        BigNumber m(to_string(multiple));
		temp = largestDivisor * m;
		if (temp.absGte(result)) break;
		else {
            largestDivisor = temp;
            multiple *= 10;
        }
	}
    while (!result.isNeg()) {
		cout << largestDivisor.toString() << endl;
        result = result - largestDivisor;
        quotient++;
        cout << "RESULT: " << result.toString() << endl;
        //cout << "QUOTIENT: " << quotient << endl;
    }
    multiple /= 10;
    quotient--;
    cout << "QUOTIENT: " << quotient << endl;
    cout << "MULTIPLE: " << multiple << endl;
    quotient *= multiple;

   	//string ans;
	//string number = num;
   
    //// Find prefix of number that is larger
    //// than divisor.
    //int idx = 0;
    //int temp = number[idx] - '0';
    //while (temp < divisor)
    //   temp = temp * 10 + (number[++idx] - '0');
    // 
    //// Repeatedly divide divisor with temp. After 
    //// every division, update temp to include one 
    //// more digit.
    //while (number.size() > idx)
    //{
    //    // Store result in answer i.e. temp / divisor
    //    ans += (temp / divisor) + '0';
    //     
    //    // Take next digit of number
    //    temp = (temp % divisor) * 10 + number[++idx] - '0';
    //}
    // 
    //// If divisor is greater than number
    //if (ans.length() == 0)
    //    return BigNumber(); 

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
