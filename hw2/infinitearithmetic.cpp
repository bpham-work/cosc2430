#include <iostream>
#include <fstream>
#include <string>
#include <exception>

#include "parser.h"
#include "arithmeticsvc.h"
#include "bignumber.h"

using namespace std;

int main(int argc, char* argv[]) {
    string file(argv[1]);
    file = file.substr(file.find("=")+1);
    ifstream instream(file);
    string line;
    ArithmeticSvc svc;
    while (!instream.eof()) {
        getline(instream, line);
        try {
            string result = svc.evaluate(line);
            cout << line << "=" << result << endl;
        } catch (exception& e) {
            cout << "INVALID: " << line << endl;
            continue;
        }
    }
    return 0;
}
