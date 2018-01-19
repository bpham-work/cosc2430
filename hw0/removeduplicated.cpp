#include <iostream>
#include <fstream>
#include <set>
#include "ArgumentManager.h"
using namespace std;

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cout << "Usage: removeduplicated input=input1.txt output=output1.txt" << endl;
        return -1;
    }
    ArgumentManager am(argc, argv);
    const string input = am.get("input");
    const string output = am.get("output");
    cout << "input=" << input << " output=" << output << endl;
    
    // Store records in a set because they natively only insert values if
    // they do not already exist
    set<string> allRecords;

    // Read records from ifs;
    ifstream ifs(input);
    char letter;
    string inputRecord;
    while (ifs.get(letter)) {
        // Skip characters that are spaces or line breaks
        if (letter != ' ' && letter != '\n') {
            // Build record with input characters
            inputRecord += letter;

            // } marks the end of the record, add to the set
            if (letter == '}') {
                allRecords.insert(inputRecord);
                inputRecord = string();
            }
        }
    }

    // output unique records
    std::ofstream ofs(output);
    for (set<string>::iterator record = allRecords.begin(); record != allRecords.end(); ++record) {
        cout << *record << endl;
        ofs << *record << endl;
    }
    
    ifs.close();
    ofs.close();
    return 0;
}
