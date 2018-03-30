#include "info.h"
#include "sqstype.h"

Info::Info() {}
Info::Info(string name, string type, string value): Message(name, type, value, INFO) {}

