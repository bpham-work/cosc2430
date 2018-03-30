#include "sqstype.h"
#include "error.h"

Error::Error() {}
Error::Error(string name, string type, string value): Message(name, type, value, ERROR) {}
