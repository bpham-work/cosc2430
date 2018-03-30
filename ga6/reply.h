#ifndef REPLY_H
#define REPLY_H

#include "message.h"

class Reply : public Message {
    public:
        Reply();
        Reply(string name, string type, string value);
};

#endif
