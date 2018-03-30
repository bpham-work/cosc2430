#ifndef INFO_H
#define INFO_H

#include "message.h"

class Info : public Message {
    public:
        Info();
        Info(string name, string type, string value);
};

#endif
