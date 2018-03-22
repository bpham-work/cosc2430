#include <iostream>
#include <fstream>
#include <string>
#include <exception>

#include "arithmeticsvc.h"

using namespace std;

int main(int argc, char* argv[]) {
    string file(argv[1]);
    file = file.substr(file.find("=")+1);
    ifstream instream(file);
    string line = "";
    ArithmeticSvc svc;
    while (!instream.eof()) {
        getline(instream, line);
        try {
            string result = svc.evaluate(line);
            cout << line << "=" << result << endl;
        } catch (exception& e) {
            //cout << "INVALID: " << line << endl;
            continue;
        }
    }
    //ArithmeticSvc svc;
    //string result = svc.evaluate("321531355*5667867893-13135450/50+6567*653");
    //string result = svc.evaluate("(1000000000000000-1)");
    //cout << result << endl;
    return 0;
}
