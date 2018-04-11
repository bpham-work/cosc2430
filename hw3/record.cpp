#include "record.h"
#include "splitter.h"
#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;

Record::Record() {}
Record::Record(string unparsed_record) {
    record_str = unparsed_record;
    unparsed_record.erase(0, 1);
    unparsed_record.erase(unparsed_record.size()-1, 1);
    attrs = util::split(unparsed_record, ',');
}

vector<string> Record::get_attrs() {
    return attrs;
}
