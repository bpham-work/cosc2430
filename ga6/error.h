#ifndef ERROR_H
#define ERROR_H

#include "message.h"

class Error : public Message {
    public:
        Error();
        Error(string name, string type, string value);
};

#endif
