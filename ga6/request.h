#ifndef REQUEST_H
#define REQUEST_H

#include "message.h"

class Request : public Message {
    public:
        Request();
        Request(string name, string type, string value);
};

#endif
