#ifndef SORTER_H
#define SORTER_H

#include <iostream>

#include "comparator.h"

class Sorter {
    public:
        static void selectionSort(string* records, const int& arrSize, Comparator& comparator);
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
        string temp = records[i];
        records[i] = records[minIndex];
        records[minIndex] = temp;
    }
}

#endif
