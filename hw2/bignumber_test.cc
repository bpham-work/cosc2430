#include "gtest/gtest.h"
#include "bignumber.h"

namespace {
    TEST(BigNumber, ValidPositiveNum) {
        BigNumber num("100001");

        string result = num.getNum();

        ASSERT_EQ("100001", result);
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

    TEST(BigNumber, AddUnequalLengthPositiveNumbersWithCarryover) {
        BigNumber num1("1");
        BigNumber num2("19");

        BigNumber result = num1 + num2;

        ASSERT_EQ("20", result.getNum());
        ASSERT_FALSE(result.isNeg());
    }
}
