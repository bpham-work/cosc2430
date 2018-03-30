#include <string>
#include <iostream>
#include <ctype.h>
#include <stdexcept>
#include "message.h"
using namespace std;

Message::Message() {}
Message::Message(string name, string type, string value, SqsType sqsType): name(name), type(type), value(value), sqsType(sqsType) {
    if (!isValid(name) || !isValid(value)) {
        cout << value << endl;
        throw invalid_argument("Message created with invalid name or value");
    }
}

bool Message::isExpired() {
    return false;
}

string Message::toString() {
    return "Name: " + name + " Type: " + type + " Value: " + value;
}

bool Message::isValid(string toValidate) {
    string copyStr = string(toValidate);
    for (int i = 0; i < copyStr.size(); i++) {
        copyStr[i] = tolower(copyStr[i]);
    }
    if (copyStr.find("..") != -1) {
        return false;
    } else if (copyStr.size() > 256) {
        return false;
    } else if (copyStr.find("aws.") == 0 || copyStr.find("amazon.") == 0) {
        // Check if starts with aws. or amazon. Don't need to check casing variation because tolower
        return false;
    }
    for (int i = 0; i < copyStr.size(); i++) {
        if (copyStr[i] >= 97 && copyStr[i] <= 122) {
            // Check if character is a-z. Don't need to check A-Z because tolower
            continue;
        } else if (copyStr[i] >= 48 && copyStr[i] <= 57) {
            // Check if character is 0-9
            continue;
        } else if (copyStr[i] == ' '|| copyStr[i] == '_' || copyStr[i] == '-' || copyStr[i] == '.') {
            continue;
        } else {
            return false;
        }
    }
    return true;
}

void Message::incrementDaysPassed() {
    daysPassed++;
}

//#include "gtest/gtest.h"
//
//namespace {
//    class MessageTestImpl : public Message {
//        public:
//            MessageTestImpl(string name, string type, string value, SqsType sqsType): Message(name, type, value, sqsType) {}
//        bool expired = false;
//        bool isExpired() { return expired; }
//    };
//
//    TEST(Message, NameStartingWithAwsIsNotValid) {
//        ASSERT_THROW(MessageTestImpl("aws.d", "string", "string", REQUEST), invalid_argument);
//    }
//
//    TEST(Message, NameStartingWithAwsMixedCaseIsNotValid) {
//        ASSERT_THROW(MessageTestImpl("aWs.d", "string", "string", REQUEST), invalid_argument);
//    }
//
//    TEST(Message, NameStartingWithAmazonIsNotValid) {
//        ASSERT_THROW(MessageTestImpl("amazon.d", "string", "string", REQUEST), invalid_argument);
//    }
//
//    TEST(Message, NameStartingWithAmazonMixedCaseIsNotValid) {
//        ASSERT_THROW(MessageTestImpl("aMaZoN.d", "string", "string", REQUEST), invalid_argument);
//    }
//
//    TEST(Message, NameWithConsecutiveDotsIsNotValid) {
//        ASSERT_THROW(MessageTestImpl("valid..d", "string", "string", REQUEST), invalid_argument);
//    }
//
//    TEST(Message, NameWithInvalidChars) {
//        ASSERT_THROW(MessageTestImpl("*&^sdfsdf", "string", "string", REQUEST), invalid_argument);
//    }
//
//    TEST(Message, LongNameIsNotValid) {
//        ASSERT_THROW(
//                MessageTestImpl("G8lAIN9HitRoxEwntspk7aKi2fqFvw5PpX6pl190ROpQXPV9GtWi7rru36SrvkTeZeHUAq1kaU92uRBr8IWGq43YqUcdk3qEOQppewYupZhZu4Nk9UV7AFHozYb0rePuGcmESlNvjxdsLkS4TgBgA7VigbTFNFhHul8GDQcAZxJlsVnsJK1cFBlui7frrqnMPHQVJcL1F4LEaSdz9iAIz4qsZMurCmifHPDfUtO6zBVn6yeyczyGvP1WUcllVV3xv"
//                    , "string", "string", REQUEST), invalid_argument);
//    }
//
//    TEST(Message, ValidName) {
//        MessageTestImpl("nAmE_.-", "string", "string", REQUEST);
//        SUCCEED();
//    }
//
//    TEST(Message, ValueStartingWithAwsIsNotValid) {
//        ASSERT_THROW(MessageTestImpl("string", "string", "aws.d", REQUEST), invalid_argument);
//    }
//
//    TEST(Message, ValueStartingWithAwsMixedCaseIsNotValid) {
//        ASSERT_THROW(MessageTestImpl("string", "string", "aWs.d", REQUEST), invalid_argument);
//    }
//
//    TEST(Message, ValueStartingWithAmazonIsNotValid) {
//        ASSERT_THROW(MessageTestImpl("string", "string", "amazon.d", REQUEST), invalid_argument);
//    }
//
//    TEST(Message, ValueStartingWithAmazonMixedCaseIsNotValid) {
//        ASSERT_THROW(MessageTestImpl("string", "string", "aMaZoN.d", REQUEST), invalid_argument);
//    }
//
//    TEST(Message, ValueWithConsecutiveDotsIsNotValid) {
//        ASSERT_THROW(MessageTestImpl("string", "string", "valid..d", REQUEST), invalid_argument);
//    }
//
//    TEST(Message, ValueWithInvalidChars) {
//        ASSERT_THROW(MessageTestImpl("string", "string", "*&^sdfsdf", REQUEST), invalid_argument);
//    }
//
//    TEST(Message, LongValueIsNotValid) {
//        ASSERT_THROW(
//                MessageTestImpl("name", "string", "G8lAIN9HitRoxEwntspk7aKi2fqFvw5PpX6pl190ROpQXPV9GtWi7rru36SrvkTeZeHUAq1kaU92uRBr8IWGq43YqUcdk3qEOQppewYupZhZu4Nk9UV7AFHozYb0rePuGcmESlNvjxdsLkS4TgBgA7VigbTFNFhHul8GDQcAZxJlsVnsJK1cFBlui7frrqnMPHQVJcL1F4LEaSdz9iAIz4qsZMurCmifHPDfUtO6zBVn6yeyczyGvP1WUcllVV3xv"
//                    , REQUEST), invalid_argument);
//    }
//}
