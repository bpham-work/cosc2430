#include "db.h"
#include "record.h"

#include <vector>
#include <set>
#include <map>
#include <iostream>
#include <string>
#include <utility>
#include <iostream>
#include <algorithm>
using namespace std;

vector<set<int>> Database::getMatchingAttrSets(vector<string> fields) {
    vector<set<int>> sets;
    for (vector<string>::iterator it = fields.begin(); it != fields.end(); it++) {
        sets.push_back(attr_map[*it]);
    }
    return sets;
}

set<int> Database::intersects(vector<string> fields) {
    vector<set<int>> sets = getMatchingAttrSets(fields);
    set<int> intersect;
    if (sets.size() > 0) {
        intersect = sets[0];
        if (sets.size() > 1) {
            for (vector<set<int>>::iterator it = sets.begin(); it != sets.end(); it++) {
                set_intersection(it->begin(), it->end(), intersect.begin(), intersect.end(), inserter(intersect, intersect.begin()));
            }
        }
    }
    return intersect;
}

void Database::remove(vector<string> fields) {
    set<int> intersect = intersects(fields);
    vector<set<int>> sets = getMatchingAttrSets(fields);
    for (set<int>::iterator it = intersect.begin(); it != intersect.end(); it++) {
        for (vector<set<int>>::iterator sit = sets.begin(); sit != sets.end(); sit++) {
            sit->erase(*it);
        }
        records.erase(*it);
    }
}

vector<string> Database::get(vector<string> fields) {
    vector<string> result;
    set<int> intersect = intersects(fields);
    for (set<int>::iterator it = intersect.begin(); it != intersect.end(); it++) {
        result.push_back(records[*it]);
    }
    return result;
}

void Database::add(string recordStr) {
    Record record(recordStr);
    records.insert(make_pair(index, recordStr));
    for (int i = 0; i < record.get_attrs().size(); i++) {
        attr_map[record.get_attrs()[i]].insert(index);
    }
    index++;
}
