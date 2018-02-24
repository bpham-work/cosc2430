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
        static void heapSort(string* records, const int& arrSize, Comparator& comparator);
    private:
        static void quickSort(string* records, int lo, int hi, Comparator& comparator);
        static int partition(string* records, int lo, int hi, Comparator& comparator);
        static void mergeSort(string* records, string* aux, const int& lo, const int& hi, Comparator& comparator);
        static void merge(string* records, string* aux, const int& lo, const int& hi, Comparator& comparator);
        static void swap(string* records, int index1, int index2);
        static void heapify(string* records, const int& arrSize, Comparator& comparator);
        static void sink(string* records, const int& node, const int& arrSize, Comparator& comparator);
};

void Sorter::selectionSort(string* records, const int& arrSize, Comparator& comparator) {
    for (int i = 0; i < arrSize-1; i++) {
        int minIndex = i;
        for (int k = i+1; k < arrSize; k++) {
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
        while (left <= hi && comparator.compare(records[left], records[part]) < 0) {
            left++;
        }
        while (right > lo && comparator.compare(records[right], records[part]) > 0) {
            right--;
        }
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

void Sorter::heapSort(string* records, const int& arrSize, Comparator& comparator) {
    string heap[arrSize + 1];
    for (int i = 1; i < arrSize + 1; i++) {
        heap[i] = records[i-1];
    }
    heapify(heap, arrSize+1, comparator);
    for (int i = arrSize; i > 1; i--) {
        swap(heap, 1, i);
        sink(heap, 1, i, comparator);
    }
    for (int i = 1; i < arrSize + 1; i++) {
        records[i-1] = heap[i];
    }
}

void Sorter::heapify(string* records, const int& arrSize, Comparator& comparator) {
    for (int i = arrSize - 1; i > 0; i--) {
        sink(records, i, arrSize, comparator);
    }
}

void Sorter::sink(string* records, const int& node, const int& arrSize, Comparator& comparator) {
    int leftChild = node * 2;
    int rightChild = node * 2 + 1;
    if (leftChild < arrSize && rightChild < arrSize) {
        int leftComp = comparator.compare(records[node], records[leftChild]);
        int rightComp = comparator.compare(records[node], records[rightChild]);
        int childComp = comparator.compare(records[leftChild], records[rightChild]);
        if (leftComp < 0 || rightComp < 0) {
            if (childComp < 0) {
                swap(records, node, rightChild);
                sink(records, rightChild, arrSize, comparator);
            } else {
                swap(records, node, leftChild);
                sink(records, leftChild, arrSize, comparator);
            }
        }
    } else if (leftChild < arrSize) {
        int leftComp = comparator.compare(records[node], records[leftChild]);
        if (leftComp < 0) {
            swap(records, node, leftChild);
            sink(records, leftChild, arrSize, comparator);
        }
    } else if (rightChild < arrSize) {
        int rightComp = comparator.compare(records[node], records[rightChild]);
        if (rightComp < 0) {
            swap(records, node, rightChild);
            sink(records, rightChild, arrSize, comparator);
        }
    }
}

void Sorter::swap(string* records, int index1, int index2) {
    string temp = records[index1];
    records[index1] = records[index2];
    records[index2] = temp;
}

#endif
