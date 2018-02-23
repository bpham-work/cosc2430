#ifndef SORTER_H
#define SORTER_H

#include <iostream>

#include "comparator.h"

class Sorter {
    public:
        static void selectionSort(string* records, const int& arrSize, Comparator& comparator);
        static void insertionSort(string* records, const int& arrSize, Comparator& comparator);
        static void quickSort(string* records, const int& arrSize, Comparator& comparator);
    private:
        static void quickSort(string* records, int lo, int hi, Comparator& comparator);
        static int partition(string* records, int lo, int hi, Comparator& comparator);
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

void Sorter::quickSort(string* records, const int& arrSize, Comparator& comparator) {
    quickSort(records, 0, arrSize-1, comparator);
}

void Sorter::quickSort(string* records, int lo, int hi, Comparator& comparator) {
    if (lo >= hi) return;
    int partitionIndex = partition(records, lo, hi, comparator);
    quickSort(records, lo, partitionIndex - 1, comparator);
    quickSort(records, partitionIndex + 1, hi, comparator);
}

int Sorter::partition(string* records, int lo, int hi, Comparator& comparator) {
    int part = lo;
    int left = lo + 1;
    int right = hi;
    while (left <= hi && right >= lo) {
        while (comparator.compare(records[left], records[part]) < 0) left++;
        while (comparator.compare(records[right], records[part]) > 0) right--;
        if (left >= right) {
            swap(records, right, part);
            return right;
        }
        swap(records, left, right);
        left++;
        right--;
    }
    return right;
}

void Sorter::swap(string* records, int index1, int index2) {
    string temp = records[index1];
    records[index1] = records[index2];
    records[index2] = temp;
}

#endif
