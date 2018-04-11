#include "db.h"
#include "record.h"
#include <vector>
#include <string>
#include <iostream>
using namespace std;

void print(vector<string> v) {
    for (vector<string>::iterator it = v.begin(); it != v.end(); it++)
        cout << *it << endl;
}

int main() {
    Database db;
    db.add("{id:1234567,first:Mary,last:Green,DOB:1996-10-03,GPA:4.0}");
    db.add("{id:1234568,first:Peter,last:White,DOB:1997-05-22,GPA:3.8}");
    db.add("{id:1654238,first:Nick,last:Park,DOB:1995-08-18,GPA:4.0}");
    db.add("{id:1234587,first:Katy,last:Green,DOB:1995-08-18,GPA:4.0}");
    vector<string> vec;
    vector<string> vec2;
    vec.push_back("GPA:4.0");
    vec2.push_back("first:Mary");
    print(db.get(vec));
    db.remove(vec2);
    db.add("{id:1234567,first:Mary,last:Green,DOB:1996-10-03,GPA:4.0}");
    
    vector<string> v3;
    v3.push_back("last:Green");
    v3.push_back("GPA:4.0");
    print(db.get(v3));
    return 0;
}
