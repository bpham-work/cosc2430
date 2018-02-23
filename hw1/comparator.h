#ifndef COMPARATOR_H
#define COMPARATOR_H

#include <string>

class Comparator {
    string* keys;
    int numOfKeys;
    public:
        Comparator(string keys[], int numOfKeys);
        int compare(string record1, string record2);
    private:
        string getAttrVal(string record, string key);
};

Comparator::Comparator(string keys[], int numOfKeys) : keys(keys), numOfKeys(numOfKeys) {}

int Comparator::compare(string record1, string record2) {
    int compareResults[numOfKeys];
    for (int i = 0; i < numOfKeys; i++) {
        string key = keys[i];
        string val1 = this->getAttrVal(record1, key);
        string val2 = this->getAttrVal(record2, key);
        compareResults[i] = val1.compare(val2);
    }
    for (int i = 0; i < numOfKeys; i++) {
        if (compareResults[i] != 0) return compareResults[i];
    }
    return 0;
}

string Comparator::getAttrVal(string record, string key) {
    int start_pos = record.find(key) + key.size() + 1;
    int end_pos = record.find(",", start_pos);
    end_pos = end_pos == -1 ? record.size() : end_pos;
    int length = end_pos - start_pos;
    return record.substr(start_pos, length);
}

#endif
