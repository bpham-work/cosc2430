#include "sqstype.h"
#include "reply.h"

Reply::Reply() {}
Reply::Reply(string name, string type, string value): Message(name, type, value, REPLY) {}

