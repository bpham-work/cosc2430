#ifndef MESSAGE_H
#define MESSAGE_H

#include <string>
#include <ctype.h>
#include "sqstype.h"
using namespace std;

class Message {
    string name;
    string type;
    string value;
    string datetime;
    public:
        SqsType sqsType;
        int daysPassed = 0;
        Message();
        Message(string name, string type, string value, SqsType sqsType);
        virtual bool isExpired();
        bool isValid(string toValidate);
        void incrementDaysPassed();
        string toString();
    private:
        string getCurrentDatetime();
};

#endif
