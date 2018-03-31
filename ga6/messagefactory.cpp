#include "messagefactory.h"
#include "sqstype.h"
#include "message.h"
#include "reply.h"
#include "request.h"
#include "error.h"
#include "info.h"
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <string>
using namespace std;

MessageFactory::MessageFactory() {
    srand(time(NULL));
}

Message MessageFactory::generate(int day) {
    int sqsType = getRand(3);
    string messageType = getRandomMessageType();
    string name = "";
    string value = getRandomMessageValue(messageType, day);
    switch (sqsType) {
        case 0:
            name = "REQUEST-" + getRandomString();
            return Request(name, messageType, value);
        case 1:
            name = "REPLY-" + getRandomString();
            return Reply(name, messageType, value);
        case 2:
            name = "ERROR-" + getRandomString();
            return Error(name, messageType, value);
        default:
            name = "INFO-" + getRandomString();
            return Info(name, messageType, value);
    }
}

int MessageFactory::getRand(int hi) {
    return rand() % (hi + 1);
}

string MessageFactory::getRandomMessageType() {
    int messageType = getRand(3);
    switch (messageType) {
        case 0:
            return "number";
        case 1:
            return "binary";
        default:
            return "string";
    }
}

string MessageFactory::getRandomString() {
    string possible = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijkelmnopqrstuvwxyz0123456789-_.";
    string result = "";
    for (int i = 0; i < 6; i++) {
        int randomIndex = rand() % (possible.size() - 1);
        result += possible[randomIndex];
    }
    return result;
}

string MessageFactory::getRandomMessageValue(string messageType, int day) {
    if (messageType == "number") {    
        // number data type
        return to_string(getRand(100));
    } else if (messageType == "binary") {
        // binary data type
        return "0000 0000 0000 0000";
    } else {
        // string data type
        return "Message created on day " + to_string(day);
    }
}
