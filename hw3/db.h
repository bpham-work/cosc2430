#ifndef DB_H
#define DB_H

#include "record.h"

#include <unordered_map>
#include <map>
#include <set>
#include <string>
using namespace std;

class Database {
    unordered_map<string, set<int>> attr_map;
    map<int, string> records;
    int index = 0;
    public:
        void remove(vector<string> fields);
        void add(string recordStr);
        vector<string> get(vector<string> fields);
        set<int> intersects(vector<string> fields);
        vector<set<int>> getMatchingAttrSets(vector<string> fields);
};

#endif
