#include "sqstype.h"
#include "request.h"

Request::Request() {}
Request::Request(string name, string type, string value): Message(name, type, value, REQUEST) {}

