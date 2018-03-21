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
    //string result1 = svc.evaluate("(+1+2)*(+1000+2000)");
    //cout << result1 << endl;
    //string result2 = svc.evaluate("((1+2)*(1000+2000))*(1+10000)");
    //cout << result2 << endl;
    //string result3 = svc.evaluate("((-1))-(-1)");
    //cout << result3 << endl;

    ////string result4 = svc.evaluate("9999999999999999999999/9999999999999999999999");
    ////cout << result4 << endl;

    //string result5 = svc.evaluate("0*00000000000000000+0000000000000001");
    //cout << result5 << endl;

    //string result6 = svc.evaluate("(1000000000000000-1)");
    //cout << result6 << endl;
    return 0;
}
