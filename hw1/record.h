#ifndef RECORD_H
#define RECORD_H

#include <string>
#include <iostream>
using namespace std;

class Record {
    string original;
    string compareString;
    public:
        Record();
        Record(string record, string* keys, int numOfKeys);
        string getCompString();
        string getRecord();
        int compare(Record& comp);
    private:
        string getAttrVal(string record, string key);
};

Record::Record() {}

Record::Record(string record, string* keys, int numOfKeys) : original(record) {
    for (int i = 0; i < numOfKeys; i++) {
        compareString += this->getAttrVal(record, keys[i]) + " ";
    }
    cout << compareString << endl;
}

string Record::getAttrVal(string record, string key) {
    int start_pos = record.find(key) + key.size() + 1;
    int end_pos = record.find(",", start_pos);
    end_pos = end_pos == -1 ? record.size()-1 : end_pos;
    int length = end_pos - start_pos;
    return record.substr(start_pos, length);
}

string Record::getCompString() { return compareString; }
string Record::getRecord() { return original; }
int Record::compare(Record& comp) {
    return compareString.compare(comp.getCompString());
}

#endif
