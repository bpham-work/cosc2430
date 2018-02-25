#include <iostream>
#include <fstream>
#include <string>
#include <chrono>

#include "doublylinkedlist.h"
#include "comparator.h"
#include "sorter.h"
#include "record.h"
using namespace std;

Record* createRecordsFromFile(string& input, int& size, DoublyLinkedList<string>& attrs) {
    string* keys = attrs.toArray();
    DoublyLinkedList<Record> list;
    ifstream in_file(input);
    string recordFromFile;
    while (getline(in_file, recordFromFile)) {
        Record record(recordFromFile, keys, attrs.size());
        list.append(record);
    }
    Record* records = list.toArray();
    size = list.size();
    in_file.close();
    return records;
}

DoublyLinkedList<string> readAttrKeys(string& attrFile) {
    ifstream in_file(attrFile);
    DoublyLinkedList<string> list;
    string attr;
    while (in_file >> attr) {
        list.append(attr);
    }
    in_file.close();
    return list;
}

string getArg(string input) {
    return input.substr(input.find("=")+1);
}

void print(Record* arr, int n) {
    for (int i = 0; i < n; i++) cout << arr[i].getRecord() << endl;
}

void writeToFile(string& out, Record* records, int& size) {
    ofstream out_file(out);
    for (int i = 0; i < size; i++) {
        out_file << records[i].getRecord() << endl;
    }
    out_file.close();
}

int main(int argc, char* argv[]) {
    string input = getArg(argv[1]);
    string attributes = getArg(argv[2]);
    string output = getArg(argv[3]);
    string sortType = getArg(argv[4]);
    int size = 0;
    auto read_start = chrono::system_clock::now();
    DoublyLinkedList<string> attrs = readAttrKeys(attributes);
    Record* records = createRecordsFromFile(input, size, attrs);
    auto read_end = chrono::system_clock::now();
    auto read_elapsed = chrono::duration_cast<chrono::milliseconds>(read_end - read_start);
    cout << "READ: " << read_elapsed.count() << endl;

    auto sort_start = chrono::system_clock::now();
    if (sortType == "select") {
        Sorter::selectionSort(records, size);
    } else if (sortType == "insert") {
        Sorter::insertionSort(records, size);
    } else if (sortType == "quick") {
        Sorter::quickSort(records, size);
    } else if (sortType == "merge") {
        Sorter::mergeSort(records, size);
    } else if (sortType == "heap") {
        Sorter::heapSort(records, size);
    } else {
        cout << "Invalid sort type" << endl;
        return -1;
    }
    auto sort_end = chrono::system_clock::now();
    auto sort_elapsed = chrono::duration_cast<chrono::milliseconds>(sort_end - sort_start);
    cout << "SORT: " << sort_elapsed.count() << endl;
    //print(records, size);
    
    auto write_start = chrono::system_clock::now();
    writeToFile(output, records, size);
    auto write_end = chrono::system_clock::now();
    auto write_elapsed = chrono::duration_cast<chrono::milliseconds>(write_end - write_start);
    cout << "WRITE: " << write_elapsed.count() << endl;

    return 0;
}
