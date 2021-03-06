#include "gtest/gtest.h"
#include "parser.h"
#include "stack.h"
#include <string>

namespace {
    TEST(Parser, ParseNoPriority) {
        Parser parser;
        string expression = "1+1";

        string result = parser.parse(expression);

        ASSERT_EQ("1,1,+", result);
    }

    TEST(Parser, ParseParenPlus) {
        Parser parser;
        string expression = "(+1+1)";

        string result = parser.parse(expression);

        ASSERT_EQ("1,1,+", result);
    }

    TEST(Parser, ParseMultiplyFirst) {
        Parser parser;
        string expression = "2*3+1";

        string result = parser.parse(expression);

        ASSERT_EQ("2,3,*,1,+", result);
    }

    TEST(Parser, ParseMultiplyLast) {
        Parser parser;
        string expression = "2+3*1";

        string result = parser.parse(expression);

        ASSERT_EQ("2,3,1,*,+", result);
    }
    
    TEST(Parser, ParseParenFirst) {
        Parser parser;
        string expression = "(2+3)-1";

        string result = parser.parse(expression);

        ASSERT_EQ("2,3,+,1,-", result);
    }
    
    TEST(Parser, ParseParenLast) {
        Parser parser;
        string expression = "2+(3-1)";

        string result = parser.parse(expression);

        ASSERT_EQ("2,3,1,-,+", result);
    }

    TEST(Parser, ParseParenWithMultiplyFirst) {
        Parser parser;
        string expression = "(2+3)*1";

        string result = parser.parse(expression);

        ASSERT_EQ("2,3,+,1,*", result);
    }
    
    TEST(Parser, ParseParenWithMultiplyLast) {
        Parser parser;
        string expression = "2*(3-1)";

        string result = parser.parse(expression);

        ASSERT_EQ("2,3,1,-,*", result);
    }

    TEST(Parser, ParseNestedParenFirst) {
        Parser parser;
        string expression = "((1+1)+2+3)-1";

        string result = parser.parse(expression);

        ASSERT_EQ("1,1,+,2,+,3,+,1,-", result);
    }
    
    TEST(Parser, ParseNestedParenLast) {
        Parser parser;
        string expression = "2+(3-1+(2+2))";

        string result = parser.parse(expression);

        ASSERT_EQ("2,3,1,-,2,2,+,+,+", result);
    }

    TEST(Parser, ParseNestedParenWithMultiplyFirst) {
        Parser parser;
        string expression = "((1+1)*2*3)-1";

        string result = parser.parse(expression);

        ASSERT_EQ("1,1,+,2,*,3,*,1,-", result);
    }
    
    TEST(Parser, ParseNestedParenWithMultiplyLast) {
        Parser parser;
        string expression = "2+(3*1*(2+2))";

        string result = parser.parse(expression);

        ASSERT_EQ("2,3,1,*,2,2,+,*,+", result);
    }
    
    TEST(Parser, ParseNestedParenWithMultiplyFirst2) {
        Parser parser;
        string expression = "((1*1)+2-3)-1";

        string result = parser.parse(expression);

        ASSERT_EQ("1,1,*,2,+,3,-,1,-", result);
    }
    
    TEST(Parser, ParseNestedParenWithMultiplyLast2) {
        Parser parser;
        string expression = "2+(3+1-(2*2))";

        string result = parser.parse(expression);

        ASSERT_EQ("2,3,1,+,2,2,*,-,+", result);
    }

    TEST(Parser, ParseMultiDigit) {
        Parser parser;
        string expression = "100+1";

        string result = parser.parse(expression);

        ASSERT_EQ("100,1,+", result);
    }

    TEST(Parser, ParseNegativeDigit1) {
        Parser parser;
        string expression = "-100+1";

        string result = parser.parse(expression);

        ASSERT_EQ("-100,1,+", result);
    }

    TEST(Parser, ParseNegativeDigit2) {
        Parser parser;
        string expression = "1+(-100)";

        string result = parser.parse(expression);

        ASSERT_EQ("1,-100,+", result);
    }

    TEST(Parser, IsValid1) {
        Parser parser;
        string exp = "1+1";

        bool result = parser.isValid(exp);

        ASSERT_TRUE(result);
    }

    TEST(Parser, IsValid2) {
        Parser parser;
        string exp = "(1+1)*1";

        bool result = parser.isValid(exp);

        ASSERT_TRUE(result);
    }
    
    TEST(Parser, IsValid3) {
        Parser parser;
        string exp = "(-1+1)";

        bool result = parser.isValid(exp);

        ASSERT_TRUE(result);
    }

    TEST(Parser, IsValid4) {
        Parser parser;
        string exp = "(+1+1)";

        bool result = parser.isValid(exp);

        ASSERT_TRUE(result);
    }

    TEST(Parser, InvalidMinus1) {
        Parser parser;
        string exp = "(1+-1)";

        bool result = parser.isValid(exp);

        ASSERT_FALSE(result);
    }

    TEST(Parser, InvalidMinus2) {
        Parser parser;
        string exp = "(1-+1)";

        bool result = parser.isValid(exp);

        ASSERT_FALSE(result);
    }

    TEST(Parser, UnmatchingParensIsNotValid1) {
        Parser parser;
        string exp = "(1+1(";

        bool result = parser.isValid(exp);

        ASSERT_FALSE(result);
    }

    TEST(Parser, UnmatchingParensIsNotValid2) {
        Parser parser;
        string exp = ")1+1)";

        bool result = parser.isValid(exp);

        ASSERT_FALSE(result);
    }
    
    TEST(Parser, UnmatchingParensIsNotValid3) {
        Parser parser;
        string exp = ")1+1(";

        bool result = parser.isValid(exp);

        ASSERT_FALSE(result);
    }

    TEST(Parser, InvalidOperators1) {
        Parser parser;
        string exp = "1+*1";

        bool result = parser.isValid(exp);

        ASSERT_FALSE(result);
    }

    TEST(Parser, InvalidOperators2) {
        Parser parser;
        string exp = "1+1+";

        bool result = parser.isValid(exp);

        ASSERT_FALSE(result);
    }

    TEST(Parser, ValidOperators6) {
        Parser parser;
        string exp = "+1+1";

        bool result = parser.isValid(exp);

        ASSERT_TRUE(result);
    }

    TEST(Parser, EmptyExpIsInvalid) {
        Parser parser;
        string exp = "";

        bool result = parser.isValid(exp);

        ASSERT_FALSE(result);
    }

    TEST(Parser, NoOperatorsIsInvalid) {
        Parser parser;
        string exp = "1";

        bool result = parser.isValid(exp);

        //ASSERT_FALSE(result);
    }

    TEST(Parser, ThrowInvalidArgument) {
        Parser parser;
        string exp = "(*1+1)";

        EXPECT_THROW({
                parser.parse(exp);
        }, std::invalid_argument);
    }

    TEST(Parser, testderp) {
        Parser parser;
        string exp = "321531355*5667867893-13135450/50+6567*653";

        string result = parser.parse(exp);

        ASSERT_EQ("321531355,5667867893,*,13135450,50,/,-,6567,653,*,+", result);
    }

    TEST(Parser, testderp2) {
        Parser parser;
        string exp = "5*3-6/2+6*6";

        string result = parser.parse(exp);

        ASSERT_EQ("5,3,*,6,2,/,-,6,6,*,+", result);
    }

    TEST(Parser, testderp3) {
        Parser parser;
        string exp = "1353135+233541354/(2+2*2)+3514351354351873238-(3131359-5631)";

        string result = parser.parse(exp);

        ASSERT_EQ("1353135,233541354,2,2,2,*,+,/,+,3514351354351873238,+,3131359,5631,-,-", result);
    }
}
