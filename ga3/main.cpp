#include <iostream>
#include "linkedlist.h"
#include "piglatinconverter.h"

int main() {
    PigLatinConverter converter;
    cout << converter.convert("eye") << endl;
    cout << converter.convert("There") << endl;
    cout << converter.convert("by") << endl;
    cout << converter.convert("1234") << endl;
    return 0;
}
