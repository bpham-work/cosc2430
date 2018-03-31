#ifndef MESSAGE_FACTORY_H
#define MESSAGE_FACTORY_H

#include "message.h"
#include <string>

class MessageFactory {
    public:
        MessageFactory();
        Message generate(int day);
    private:
        int getRand(int max);
        string getRandomString();
        string getRandomMessageValue(string messageType, int day);
        string getRandomMessageType();
};

#endif
