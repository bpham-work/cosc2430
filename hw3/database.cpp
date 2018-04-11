#include "db.h"
#include "record.h"
#include "splitter.h"
#include <string>
#include <iostream>
#include <fstream>
#include <chrono>
using namespace std;

void print(vector<string> v) {
    for (vector<string>::iterator it = v.begin(); it != v.end(); it++)
        cout << *it << endl;
}

void write(vector<string>& v, ofstream& outfile) {
    for (vector<string>::iterator it = v.begin(); it != v.end(); it++)
        outfile << *it << endl;
    outfile << endl; 
}

string getArg(string input) {
    return input.substr(input.find("=")+1);
}

string getOp(string& record) {
    return record.substr(0, record.find(" "));
}

string parseRecord(string& record) {
    return record.substr(4);
}

vector<string> parseFields(string& fields) {
    fields.erase(0, fields.find("{")+1);
    fields.erase(fields.size()-1, 1);
    return util::split(fields, ',');
}

int main(int argc, char* argv[]) {
    auto ws = chrono::system_clock::now();
    string input = getArg(argv[1]);
    string output = getArg(argv[2]);
    ifstream infile(input);
    ofstream outfile(output);
    Database db;

    string record;
    while (getline(infile, record)) {
        string op = getOp(record);
        //auto start = chrono::system_clock::now();
        //cout << record << ": ";
        if (op == "add") {
            string parsed = parseRecord(record);
            db.add(parsed);
        } else if (op == "get") {
            vector<string> fields = parseFields(record);
            db.get(fields, outfile);
            //print(results);
            //write(results, outfile);
        } else {
            vector<string> fields = parseFields(record);
            db.remove(fields);
        } 
        //auto end = chrono::system_clock::now();
        //auto elapsed = chrono::duration_cast<chrono::microseconds>(end - start);
        //cout << elapsed.count() << endl;
    }
    infile.close();
    outfile.close();

    auto we = chrono::system_clock::now();
    auto e = chrono::duration_cast<chrono::milliseconds>(we - ws);
    cout << "Total: " << e.count() << endl;
    return 0;
}
