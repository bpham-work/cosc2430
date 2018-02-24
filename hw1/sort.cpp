#include <iostream>
#include <fstream>
#include <string>

#include "doublylinkedlist.h"
#include "comparator.h"
#include "sorter.h"
using namespace std;

string* createRecordsFromFile(string& input, int& size) {
    DoublyLinkedList<string> list;
    ifstream in_file(input);
    string record;
    while (getline(in_file, record)) {
        list.append(record);
    }
    string* records = list.toArray();
    size = list.size();
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

void writeToFile(string& out, string* records, int& size) {
    ofstream out_file(out);
    for (int i = 0; i < size; i++) {
        out_file << records[i] << endl;
    }
    out_file.close();
}

int main(int argc, char* argv[]) {
    string input = getArg(argv[1]);
    string attributes = getArg(argv[2]);
    string output = getArg(argv[3]);
    string sortType = getArg(argv[4]);

    int size = 0;
    string* records = createRecordsFromFile(input, size);
    Comparator comparator = readAttrKeys(attributes);

    if (sortType == "select") {
        Sorter::selectionSort(records, size, comparator);
    } else if (sortType == "insert") {
        Sorter::insertionSort(records, size, comparator);
    } else if (sortType == "quick") {
        Sorter::quickSort(records, size, comparator);
    } else if (sortType == "merge") {
        Sorter::mergeSort(records, size, comparator);
    } else if (sortType == "heap") {
        Sorter::mergeSort(records, size, comparator);
    } else {
        cout << "Invalid sort type" << endl;
    }
    print(records, size);
    writeToFile(output, records, size);

    return 0;
}
