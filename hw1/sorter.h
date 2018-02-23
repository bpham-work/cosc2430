#ifndef SORTER_H
#define SORTER_H

#include <iostream>

#include "comparator.h"

class Sorter {
    public:
        static void selectionSort(string* records, const int& arrSize, Comparator& comparator);
        static void insertionSort(string* records, const int& arrSize, Comparator& comparator);
    private:
        static void swap(string* records, int index1, int index2);
};

void Sorter::selectionSort(string* records, const int& arrSize, Comparator& comparator) {
    for (int i = 0; i < arrSize; i++) {
        int minIndex = i;
        for (int k = i; k < arrSize; k++) {
            string record1 = records[k];
            string minRecord = records[minIndex];
            int comp = comparator.compare(record1, minRecord);
            if (comp < 0) minIndex = k;
        }
        swap(records, i, minIndex);
    }
}

void Sorter::insertionSort(string* records, const int& arrSize, Comparator& comparator) {
    for (int i = 1; i < arrSize; i++) {
        int k = i;
        while (k > 0 && comparator.compare(records[k], records[k-1]) < 0) {
            swap(records, k, k-1);
            k--;
        }
    }
}

void Sorter::swap(string* records, int index1, int index2) {
    string temp = records[index1];
    records[index1] = records[index2];
    records[index2] = temp;
}

#endif
