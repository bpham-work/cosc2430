#include <iostream>
#include "linkedlist.h"
#include "piglatinconverter.h"

int main() {
    PigLatinConverter converter;

    cout << "Enter word to be converted into pig latin. Enter exit to end program" << endl;

    string input;
    while (true) {
        cout << "Input: ";
        cin >> input;

        if (input == "exit") break;

        cout << "Pig latin: " << converter.convert(input) << endl;
    }

    return 0;
}
