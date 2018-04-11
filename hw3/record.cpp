#include "record.h"
#include <iostream>
using namespace std;

Record::Record() {}
Record::Record(string unparsed_record) {
    record_str = unparsed_record;
    int start = 1;
    int end = 0;
    int length = 0;
    string field;
    while (start < unparsed_record.size() - 1) {
        end = unparsed_record.find(",", start);
        if (end == -1) {
            end = unparsed_record.size() - 1;
        }
        length = end - start;
        field = unparsed_record.substr(start, length);
        attrs.push_back(field);
        start = end + 1;
    }
}

vector<string> Record::get_attrs() {
    return attrs;
}
