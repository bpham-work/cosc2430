#include <iostream>
#include <fstream>
#include <string>

#include "doublylinkedlist.h"
#include "comparator.h"
#include "sorter.h"
using namespace std;

string* createRecordsFromFile(string& input) {
    DoublyLinkedList<string> list;
    ifstream in_file(input);
    string record;
    while (getline(in_file, record)) {
        list.append(record);
    }
    string* records = list.toArray();
    in_file.close();
    return records;
}

Comparator readAttrKeys(string& attrFile) {
    ifstream in_file(attrFile);
    DoublyLinkedList<string> list;
    string attr;
    while (in_file >> attr) {
        list.append(attr);
    }
    in_file.close();
    return Comparator(list.toArray(), list.size());
}

string getArg(string input) {
    return input.substr(input.find("=")+1);
}

void print(string* arr, int n) {
    for (int i = 0; i < n; i++) cout << arr[i] << endl;
}

int main(int argc, char* argv[]) {
    string input = getArg(argv[1]);
    string attributes = getArg(argv[2]);
    string output = getArg(argv[3]);
    string sortType = getArg(argv[4]);

    string* records = createRecordsFromFile(input);
    Comparator comparator = readAttrKeys(attributes);
    Sorter::quickSort(records, 4, comparator);
    print(records, 4);

    if (sortType == "select") {

    } else if (sortType == "insert") {

    } else if (sortType == "quick") {

    } else if (sortType == "merge") {

    } else if (sortType == "heap") {

    } else {
        cout << "Invalid sort type" << endl;
    }

    return 0;
}
