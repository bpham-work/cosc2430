#include "db.h"
#include "splitter.h"

#include <vector>
#include <set>
#include <map>
#include <iostream>
#include <string>
#include <utility>
#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;

vector<set<int>> Database::getMatchingAttrSets(vector<string>& fields) {
    vector<set<int>> sets;
    for (vector<string>::iterator it = fields.begin(); it != fields.end(); it++) {
        sets.push_back(attr_map[*it]);
    }
    return sets;
}

set<int> Database::intersects(vector<string>& fields) {
    set<int> intersect;
    set<int> temp;
    for (int i = 0; i < fields.size(); i++) {
        temp.clear();
        if (i == 0) {
            intersect = attr_map[fields[i]];
        } else {
            set_intersection(attr_map[fields[i]].begin(), attr_map[fields[i]].end(), intersect.begin(), intersect.end(), inserter(temp, temp.begin()));
            intersect = temp;
        }
    }
    return intersect;
}

void Database::remove(vector<string>& fields) {
    set<int> intersect = intersects(fields);
    for (set<int>::iterator it = intersect.begin(); it != intersect.end(); it++) {
        //for (int i = 0; i < fields.size(); i++) {
        //    attr_map[fields[i]].erase(*it);
        //}
        records.erase(*it);
    }
}

vector<string> Database::get(vector<string>& fields) {
    vector<string> result;
    set<int> intersect = intersects(fields);
    for (set<int>::iterator it = intersect.begin(); it != intersect.end(); it++) {
        result.push_back(records[*it]);
    }
    return result;
}

void Database::get(vector<string>& fields, ofstream& outfile) {
    set<int> intersect = intersects(fields);
    for (set<int>::iterator it = intersect.begin(); it != intersect.end(); it++) {
        outfile << records[*it] << endl;
    }
    outfile << endl;
}

void Database::add(string& recordStr) {
    records[index] = recordStr;
    vector<string> attrs = parseAttrs(recordStr);
    for (int i = 0; i < attrs.size(); i++) {
        attr_map[attrs[i]].insert(index);
    }
    index++;
}

vector<string> Database::parseAttrs(string& unparsed) {
    unparsed.erase(0, 1);
    unparsed.erase(unparsed.size()-1, 1);
    return util::split(unparsed, ',');
}
