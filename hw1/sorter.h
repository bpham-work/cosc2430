#ifndef SORTER_H
#define SORTER_H

#include <iostream>

#include "comparator.h"

class Sorter {
    public:
        static void selectionSort(string* records, const int& arrSize, Comparator& comparator);
        static void insertionSort(string* records, const int& arrSize, Comparator& comparator);
        static void quickSort(string* records, const int& arrSize, Comparator& comparator);
        static void mergeSort(string* records, const int& arrSize, Comparator& comparator);
    private:
        static void quickSort(string* records, int lo, int hi, Comparator& comparator);
        static int partition(string* records, int lo, int hi, Comparator& comparator);
        static void mergeSort(string* records, string* aux, const int& lo, const int& hi, Comparator& comparator);
        static void merge(string* records, string* aux, const int& lo, const int& hi, Comparator& comparator);
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
    cout << "NEW PARTITION" << endl;
    while (left <= hi && right >= lo) {
        int leftComp = comparator.compare(records[left], records[part]);
        cout << "COMPARE LEFT" << endl;
        cout << records[left] << endl;
        cout << records[part] << endl;
        cout << part << endl;
        while (left < hi && leftComp < 0) {
            cout << "COMPARE LEFT" << endl;
            cout << records[left] << endl;
            cout << records[part] << endl;
            cout << "LEFT: " << left << endl;
            cout << "PART: " << part << endl;
            left++;
            if (left <= hi)
            leftComp = comparator.compare(records[left], records[part]);
        }
        int rightComp = comparator.compare(records[right], records[part]);
        cout << "COMPARE RIGHT" << endl;
        cout << records[right] << endl;
        cout << records[part] << endl;
        cout << part << endl;
        while (right > lo && rightComp > 0) {
            cout << "COMPARE RIGHT" << endl;
            cout << records[right] << endl;
            cout << records[part] << endl;
            cout << part << endl;
            right--;
            rightComp = comparator.compare(records[right], records[part]);
        }
        if (left >= right) {
            cout << "CROSSED" << endl;
            cout << "PART: " << part << endl;
            swap(records, right, part);
            return right;
        }
        swap(records, left, right);
        left++;
        right--;
    }
    return right;
}

void Sorter::mergeSort(string* records, const int& arrSize, Comparator& comparator) {
    string aux[arrSize];
    mergeSort(records, aux, 0, arrSize-1, comparator);
}

void Sorter::mergeSort(string* records, string* aux, const int& lo, const int& hi, Comparator& comparator) {
    if (lo >= hi) return;
    int mid = (lo + hi) / 2;
    mergeSort(records, aux, lo, mid, comparator);
    mergeSort(records, aux, mid+1, hi, comparator);
    merge(records, aux, lo, hi, comparator);
}

void Sorter::merge(string* records, string* aux, const int& lo, const int& hi, Comparator& comparator) {
    for (int i = lo; i <= hi; i++) aux[i] = records[i];
    int mid = (lo + hi) / 2;
    int left = lo;
    int right = mid + 1;
    int insert = lo;
    while (insert <= hi) {
        if (left > mid) {
            records[insert] = aux[right++];
        } else if (right > hi) {
            records[insert] = aux[left++];
        } else if (comparator.compare(aux[left], aux[right]) <= 0) {
            records[insert] = aux[left++];
        } else {
            records[insert] = aux[right++];
        }
        insert++;
    }
}

void Sorter::swap(string* records, int index1, int index2) {
    cout << "SWAPPING" << endl;
    cout << index1 << endl;
    cout << index2 << endl;
    string temp = records[index1];
    records[index1] = records[index2];
    records[index2] = temp;
}

#endif
