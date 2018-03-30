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
    int messageType = getRandMod3();
    string name = "";
    string value = "";
    switch (messageType) {
        case 0:
            name = "REQUEST-" + getRandomString();
            value = "Request created on day " + to_string(day);
            return Request(name, "type", value);
        case 1:
            name = "REPLY-" + getRandomString();
            value = "Reply created on day " + to_string(day);
            return Reply(name, "type", value);
        case 2:
            name = "ERROR-" + getRandomString();
            value = "Error created on day " + to_string(day);
            return Error(name, "type", value);
        default:
            name = "INFO-" + getRandomString();
            value = "Info created on day " + to_string(day);
            return Info(name, "type", value);
    }
}

int MessageFactory::getRandMod3() {
    return rand() % 4;
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
