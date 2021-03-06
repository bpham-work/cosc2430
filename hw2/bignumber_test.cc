#include "gtest/gtest.h"
#include "bignumber.h"
#include <iostream>
using namespace std;

namespace {
    TEST(BigNumber, ValidPositiveNum) {
        BigNumber num("1");

        string result = num.getNum();

        ASSERT_EQ("1", result);
        ASSERT_FALSE(num.isNeg());
    }

    TEST(BigNumber, ValidNegativeNum) {
        BigNumber num("-100001");

        string result = num.getNum();

        ASSERT_EQ("100001", result);
        ASSERT_TRUE(num.isNeg());
    }

    TEST(BigNumber, RemoveLeadingZeros) {
        BigNumber num("00001");

        string result = num.getNum();

        ASSERT_EQ("1", result);
        ASSERT_FALSE(num.isNeg());
    }

    TEST(BigNumber, RemovePositiveSign) {
        BigNumber num("+1");

        string result = num.getNum();

        ASSERT_EQ("1", result);
        ASSERT_FALSE(num.isNeg());
    }

    TEST(BigNumber, RemoveNegativeSign) {
        BigNumber num("-1");

        string result = num.getNum();

        ASSERT_EQ("1", result);
        ASSERT_TRUE(num.isNeg());
    }

    TEST(BigNumber, AddEqualLengthPositiveNumbers) {
        BigNumber num1("1");
        BigNumber num2("1");

        BigNumber result = num1 + num2;

        ASSERT_EQ("2", result.getNum());
        ASSERT_FALSE(result.isNeg());
    }

    TEST(BigNumber, AddEqualLengthPositiveNumbersWithCarryover) {
        BigNumber num1("9");
        BigNumber num2("1");

        BigNumber result = num1 + num2;

        ASSERT_EQ("10", result.getNum());
        ASSERT_FALSE(result.isNeg());
    }

    TEST(BigNumber, AddUnequalLengthPositiveNumbers) {
        BigNumber num1("1");
        BigNumber num2("12");

        BigNumber result = num1 + num2;

        ASSERT_EQ("13", result.getNum());
        ASSERT_FALSE(result.isNeg());
    }

    TEST(BigNumber, AddUnequalLengthPositiveNumbers2) {
        BigNumber num1("12");
        BigNumber num2("1");

        BigNumber result = num1 + num2;

        ASSERT_EQ("13", result.getNum());
        ASSERT_FALSE(result.isNeg());
    }

    TEST(BigNumber, AddUnequalLengthPositiveNumbersWithCarryover) {
        BigNumber num1("1");
        BigNumber num2("19");

        BigNumber result = num1 + num2;

        ASSERT_EQ("20", result.getNum());
        ASSERT_FALSE(result.isNeg());
    }

    TEST(BigNumber, AddUnequalLengthPositiveNumbersWithCarryover2) {
        BigNumber num1("19");
        BigNumber num2("1");

        BigNumber result = num1 + num2;

        ASSERT_EQ("20", result.getNum());
        ASSERT_FALSE(result.isNeg());
    }

    TEST(BigNumber, AddNegativeNumbers1) {
        BigNumber num1("-2");
        BigNumber num2("1");

        BigNumber result = num1 + num2;

        ASSERT_EQ("1", result.getNum());
        ASSERT_TRUE(result.isNeg());
    }

    TEST(BigNumber, AddNegativeNumbers2) {
        BigNumber num1("-2");
        BigNumber num2("5");

        BigNumber result = num1 + num2;

        ASSERT_EQ("3", result.getNum());
        ASSERT_FALSE(result.isNeg());
    }

    TEST(BigNumber, AddNegativeNumbers3) {
        BigNumber num1("-1");
        BigNumber num2("1");

        BigNumber result = num1 + num2;

        ASSERT_EQ("0", result.getNum());
        ASSERT_FALSE(result.isNeg());
    }

    TEST(BigNumber, AddNegativeNumbers4) {
        BigNumber num1("11");
        BigNumber num2("-1");

        BigNumber result = num1 + num2;

        ASSERT_EQ("10", result.getNum());
        ASSERT_FALSE(result.isNeg());
    }

    TEST(BigNumber, AddNegativeNumbers5) {
        BigNumber num1("1");
        BigNumber num2("-10");

        BigNumber result = num1 + num2;

        ASSERT_EQ("9", result.getNum());
        ASSERT_TRUE(result.isNeg());
    }

    TEST(BigNumber, SubtractEqualLengthPositiveNumbers) {
        BigNumber num1("2");
        BigNumber num2("1");

        BigNumber result = num1 - num2;

        ASSERT_EQ("1", result.getNum());
        ASSERT_FALSE(result.isNeg());
    }

    TEST(BigNumber, SubtractUnequalLengthPositiveNumbers) {
        BigNumber num1("14");
        BigNumber num2("1");

        BigNumber result = num1 - num2;

        ASSERT_EQ("13", result.getNum());
        ASSERT_FALSE(result.isNeg());
    }

    TEST(BigNumber, SubtractUnequalLengthPositiveNumbersWithBorrow1) {
        BigNumber num1("10");
        BigNumber num2("1");

        BigNumber result = num1 - num2;

        ASSERT_EQ("9", result.getNum());
        ASSERT_FALSE(result.isNeg());
    }
    
    TEST(BigNumber, SubtractUnequalLengthPositiveNumbersWithBorrow2) {
        BigNumber num1("1000");
        BigNumber num2("1");

        BigNumber result = num1 - num2;

        ASSERT_EQ("999", result.getNum());
        ASSERT_FALSE(result.isNeg());
    }

    TEST(BigNumber, SubtractEqualLengthNegativeNumber1) {
        BigNumber num1("-1");
        BigNumber num2("1");

        BigNumber result = num1 - num2;

        ASSERT_EQ("2", result.getNum());
        ASSERT_TRUE(result.isNeg());
    }

    TEST(BigNumber, SubtractEqualLengthNegativeNumber2) {
        BigNumber num1("0");
        BigNumber num2("1");

        BigNumber result = num1 - num2;

        ASSERT_EQ("1", result.getNum());
        ASSERT_TRUE(result.isNeg());
    }

    TEST(BigNumber, SubtractUnequalLengthNegativeNumber1) {
        BigNumber num1("-10");
        BigNumber num2("1");

        BigNumber result = num1 - num2;

        ASSERT_EQ("11", result.getNum());
        ASSERT_TRUE(result.isNeg());
    }

    TEST(BigNumber, SubtractOneNegativeNumber1) {
        BigNumber num1("1");
        BigNumber num2("-1");

        BigNumber result = num1 - num2;

        ASSERT_EQ("2", result.getNum());
        ASSERT_FALSE(result.isNeg());
    }

    TEST(BigNumber, SubtractOneNegativeNumber2) {
        BigNumber num1("-1");
        BigNumber num2("1");

        BigNumber result = num1 - num2;

        ASSERT_EQ("2", result.getNum());
        ASSERT_TRUE(result.isNeg());
    }

    TEST(BigNumber, SubtractTwoNegatives1) {
        BigNumber num1("-1");
        BigNumber num2("-1");

        BigNumber result = num1 - num2;

        ASSERT_EQ("0", result.getNum());
        ASSERT_FALSE(result.isNeg());
    }

    TEST(BigNumber, SubtractTwoNegatives2) {
        BigNumber num1("-1");
        BigNumber num2("-3");

        BigNumber result = num1 - num2;

        ASSERT_EQ("2", result.getNum());
        ASSERT_FALSE(result.isNeg());
    }

    TEST(BigNumber, SubtractTwoNegatives3) {
        BigNumber num1("-5");
        BigNumber num2("-3");

        BigNumber result = num1 - num2;

        ASSERT_EQ("2", result.getNum());
        ASSERT_TRUE(result.isNeg());
    }

    TEST(BigNumber, AbsIsGreater1) {
        BigNumber num1("-10");
        BigNumber num2("1");

        ASSERT_TRUE(num1.absGte(num2));
    }

    TEST(BigNumber, AbsIsGreater2) {
        BigNumber num1("10");
        BigNumber num2("1");

        ASSERT_TRUE(num1.absGte(num2));
    }

    TEST(BigNumber, AbsIsNotGreater1) {
        BigNumber num1("1");
        BigNumber num2("10");

        ASSERT_FALSE(num1.absGte(num2));
    }

    TEST(BigNumber, AbsIsNotGreater2) {
        BigNumber num1("1");
        BigNumber num2("-10");

        ASSERT_FALSE(num1.absGte(num2));
    }

    TEST(BigNumber, Multiply1) {
        BigNumber num1("1");
        BigNumber num2("2");

        BigNumber result = num1 * num2;

        ASSERT_EQ("2", result.getNum());
        ASSERT_FALSE(result.isNeg());
    }

    TEST(BigNumber, Multiply2) {
        BigNumber num1("100");
        BigNumber num2("2");

        BigNumber result = num1 * num2;

        ASSERT_EQ("200", result.getNum());
        ASSERT_FALSE(result.isNeg());
    }

    TEST(BigNumber, Multiply3) {
        BigNumber num1("6");
        BigNumber num2("6");

        BigNumber result = num1 * num2;

        ASSERT_EQ("36", result.getNum());
        ASSERT_FALSE(result.isNeg());
    }

    TEST(BigNumber, MultiplyWithNegative1) {
        BigNumber num1("3");
        BigNumber num2("-2");

        BigNumber result = num1 * num2;

        ASSERT_EQ("6", result.getNum());
        ASSERT_TRUE(result.isNeg());
    }

    TEST(BigNumber, MultiplyWithNegative2) {
        BigNumber num1("30");
        BigNumber num2("-20");

        BigNumber result = num1 * num2;

        ASSERT_EQ("600", result.getNum());
        ASSERT_TRUE(result.isNeg());
    }

    TEST(BigNumber, MultiplyWithNegative3) {
        BigNumber num1("-20");
        BigNumber num2("20");

        BigNumber result = num1 * num2;

        ASSERT_EQ("400", result.getNum());
        ASSERT_TRUE(result.isNeg());
    }

    TEST(BigNumber, MultiplyTwoNegatives) {
        BigNumber num1("-3");
        BigNumber num2("-2");

        BigNumber result = num1 * num2;

        ASSERT_EQ("6", result.getNum());
        ASSERT_FALSE(result.isNeg());
    }

    TEST(BigNumber, Decrement1) {
        BigNumber num1("1");

        num1 = (num1--);

        ASSERT_EQ("0", num1.getNum());
        ASSERT_TRUE(num1.isZero());
        ASSERT_FALSE(num1.isNeg());
    }

    TEST(BigNumber, Decrement4) {
        BigNumber num1("2");

        num1 = (num1--);
        num1 = (num1--);

        ASSERT_EQ("0", num1.getNum());
        ASSERT_TRUE(num1.isZero());
        ASSERT_FALSE(num1.isNeg());
    }

    TEST(BigNumber, Decrement2) {
        BigNumber num1("0");

        num1 = (num1--);

        ASSERT_EQ("1", num1.getNum());
        ASSERT_TRUE(num1.isNeg());
    }

    TEST(BigNumber, Decrement3) {
        BigNumber num1("-1");

        num1 = (num1--);

        ASSERT_EQ("2", num1.getNum());
        ASSERT_TRUE(num1.isNeg());
    }

    TEST(BigNumber, IsZero) {
        BigNumber num1("0");

        ASSERT_TRUE(num1.isZero());
    }

    TEST(BigNumber, IsNotZero) {
        BigNumber num1("1");

        ASSERT_FALSE(num1.isZero());
    }

    TEST(BigNumber, Divide1) {
        BigNumber num1("20");
        BigNumber num2("5");

        BigNumber result = num1 / num2;

        ASSERT_EQ("4", result.getNum());
        ASSERT_FALSE(result.isNeg());
    }

    TEST(BigNumber, Divide2) {
        BigNumber num1("10");
        BigNumber num2("3");

        BigNumber result = num1 / num2;

        ASSERT_EQ("3", result.getNum());
        ASSERT_FALSE(result.isNeg());
    }

    TEST(BigNumber, DivideOneNegativeNumber1) {
        BigNumber num1("-20");
        BigNumber num2("5");

        BigNumber result = num1 / num2;

        ASSERT_EQ("4", result.getNum());
        ASSERT_TRUE(result.isNeg());
    }

    TEST(BigNumber, DivideOneNegativeNumber2) {
        BigNumber num1("20");
        BigNumber num2("-5");

        BigNumber result = num1 / num2;

        ASSERT_EQ("4", result.getNum());
        ASSERT_TRUE(result.isNeg());
    }

    TEST(BigNumber, DivideOneNegativeNumber1WithRemainder) {
        BigNumber num1("-10");
        BigNumber num2("3");

        BigNumber result = num1 / num2;

        ASSERT_EQ("3", result.getNum());
        ASSERT_TRUE(result.isNeg());
    }

    TEST(BigNumber, DivideOneNegativeNumber2WithRemainder) {
        BigNumber num1("10");
        BigNumber num2("-3");

        BigNumber result = num1 / num2;

        ASSERT_EQ("3", result.getNum());
        ASSERT_TRUE(result.isNeg());
    }

    TEST(BigNumber, DivideTwoNegativeNumbers) {
        BigNumber num1("-20");
        BigNumber num2("-5");

        BigNumber result = num1 / num2;

        ASSERT_EQ("4", result.getNum());
        ASSERT_FALSE(result.isNeg());
    }

    TEST(BigNumber, DivideTwoNegativeNumbersWithRemainder) {
        BigNumber num1("-10");
        BigNumber num2("-3");

        BigNumber result = num1 / num2;

        ASSERT_EQ("3", result.getNum());
        ASSERT_FALSE(result.isNeg());
    }

    TEST(BigNumber, MultiplyTwoLargeNums) {
        BigNumber num1("321531355");
        BigNumber num2("5667867893");

        BigNumber result = num1 * num2;

        ASSERT_EQ("1822397243597285015", result.getNum());
        ASSERT_FALSE(result.isNeg());
    }

    TEST(BigNumber, MultiplyTwoLargeNums2) {
        BigNumber num1("777");
        BigNumber num2("777");

        BigNumber result = num1 * num2;

        ASSERT_EQ("603729", result.getNum());
        ASSERT_FALSE(result.isNeg());
    }

    TEST(BigNumber, MultiplyWithCarryover) {
        BigNumber num1("5");
        BigNumber num2("3");
        
        BigNumber result = num1 * num2;

        ASSERT_EQ("15", result.getNum());
        ASSERT_FALSE(result.isNeg());
    }

    TEST(BigNumber, MultiplyWithCarryover2) {
        BigNumber num1("777");
        BigNumber num2("12");
        
        BigNumber result = num1 * num2;

        ASSERT_EQ("9324", result.getNum());
        ASSERT_FALSE(result.isNeg());
    }

    TEST(BigNumber, DivideWadaHek) {
        BigNumber num1("233541354");
        BigNumber num2("6");
        
        BigNumber result = num1 / num2;

        ASSERT_EQ("38923559", result.getNum());
        ASSERT_FALSE(result.isNeg());
    }

    TEST(BigNumber, SubtractWadaHek) {
        BigNumber num1("1083498");
        BigNumber num2("1679616");
        
        BigNumber result = num1 - num2;

        ASSERT_FALSE(num1.absGt(num2));
        ASSERT_EQ("596118", result.getNum());
        ASSERT_TRUE(result.isNeg());
    }

    TEST(BigNumber, SubtractWadaHek2) {
        BigNumber num1("3");
        BigNumber num2("5");
        
        BigNumber result = num1 - num2;

        ASSERT_FALSE(num1.absGte(num2));
        ASSERT_EQ("2", result.getNum());
        ASSERT_TRUE(result.isNeg());
    }
}

