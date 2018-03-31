#include <string>
#include <iostream>
#include <ctype.h>
#include <stdexcept>
#include <stdio.h>
#include <time.h>
#include "message.h"
using namespace std;

Message::Message() {}
Message::Message(string name, string type, string value, SqsType sqsType): name(name), type(type), value(value), sqsType(sqsType) {
    if (!isValid(name) || !isValid(type) || (type == "string" && !isValid(value))) {
        throw invalid_argument("Message created with invalid name or value");
    }
    datetime = getCurrentDatetime();
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

string Message::getCurrentDatetime() {
    time_t rawtime;
    struct tm* timeinfo;
    char buffer [80];

    time (&rawtime);
    timeinfo = localtime (&rawtime);

    strftime (buffer,80,"%c",timeinfo);
    return string(buffer);
}

