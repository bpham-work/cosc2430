#ifndef RECORD_H
#define RECORD_H

#include <vector>
#include <string>
using namespace std;

class Record {
    vector<string> attrs;
    public:
        string record_str;
        Record();
        Record(string unparsed_record);
        vector<string> get_attrs();
};

#endif
