#ifndef SORTER_H
#define SORTER_H

#include <iostream>

#include "record.h"

class Sorter {
    public:
        static void selectionSort(Record* records, const int& arrSize);
        static void insertionSort(Record* records, const int& arrSize);
        static void quickSort(Record* records, const int& arrSize);
        static void mergeSort(Record* records, const int& arrSize);
        static void heapSort(Record* records, const int& arrSize);
    private:
        static void quickSort(Record* records, int lo, int hi);
        static int partition(Record* records, int lo, int hi);
        static void mergeSort(Record* records, Record* aux, const int& lo, const int& hi);
        static void merge(Record* records, Record* aux, const int& lo, const int& hi);
        static void swap(Record* records, int index1, int index2);
        static void heapify(Record* records, const int& arrSize);
        static void sink(Record* records, const int& node, const int& arrSize);
};

void Sorter::selectionSort(Record* records, const int& arrSize) {
    for (int i = 0; i < arrSize-1; i++) {
        int minIndex = i;
        for (int k = i+1; k < arrSize; k++) {
            Record record1 = records[k];
            Record minRecord = records[minIndex];
            int comp = record1.compare(minRecord);
            if (comp < 0) minIndex = k;
        }
        swap(records, i, minIndex);
    }
}

void Sorter::insertionSort(Record* records, const int& arrSize) {
    for (int i = 1; i < arrSize; i++) {
        int k = i;
        while (k > 0 && records[k].compare(records[k-1]) < 0) {
            swap(records, k, k-1);
            k--;
        }
    }
}

void Sorter::quickSort(Record* records, const int& arrSize) {
    quickSort(records, 0, arrSize-1);
}

void Sorter::quickSort(Record* records, int lo, int hi) {
    if (lo >= hi) return;
    int partitionIndex = partition(records, lo, hi);
    quickSort(records, lo, partitionIndex - 1);
    quickSort(records, partitionIndex + 1, hi);
}

int Sorter::partition(Record* records, int lo, int hi) {
    int part = lo;
    int left = lo + 1;
    int right = hi;
    while (left <= hi && right >= lo) {
        while (left <= hi && records[left].compare(records[part]) < 0) {
            left++;
        }
        while (right > lo && records[right].compare(records[part]) > 0) {
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

void Sorter::mergeSort(Record* records, const int& arrSize) {
    Record aux[arrSize];
    mergeSort(records, aux, 0, arrSize-1);
}

void Sorter::mergeSort(Record* records, Record* aux, const int& lo, const int& hi) {
    if (lo >= hi) return;
    int mid = (lo + hi) / 2;
    mergeSort(records, aux, lo, mid);
    mergeSort(records, aux, mid+1, hi);
    merge(records, aux, lo, hi);
}

void Sorter::merge(Record* records, Record* aux, const int& lo, const int& hi) {
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
        } else if (aux[left].compare(aux[right]) <= 0) {
            records[insert] = aux[left++];
        } else {
            records[insert] = aux[right++];
        }
        insert++;
    }
}

void Sorter::heapSort(Record* records, const int& arrSize) {
    Record heap[arrSize + 1];
    for (int i = 1; i < arrSize + 1; i++) {
        heap[i] = records[i-1];
    }
    heapify(heap, arrSize+1);
    for (int i = arrSize; i > 1; i--) {
        swap(heap, 1, i);
        sink(heap, 1, i);
    }
    for (int i = 1; i < arrSize + 1; i++) {
        records[i-1] = heap[i];
    }
}

void Sorter::heapify(Record* records, const int& arrSize) {
    for (int i = arrSize - 1; i > 0; i--) {
        sink(records, i, arrSize);
    }
}

void Sorter::sink(Record* records, const int& node, const int& arrSize) {
    int leftChild = node * 2;
    int rightChild = node * 2 + 1;
    if (leftChild < arrSize && rightChild < arrSize) {
        int leftComp = records[node].compare(records[leftChild]);
        int rightComp = records[node].compare(records[rightChild]);
        int childComp = records[leftChild].compare(records[rightChild]);
        if (leftComp < 0 || rightComp < 0) {
            if (childComp < 0) {
                swap(records, node, rightChild);
                sink(records, rightChild, arrSize);
            } else {
                swap(records, node, leftChild);
                sink(records, leftChild, arrSize);
            }
        }
    } else if (leftChild < arrSize) {
        int leftComp = records[node].compare(records[leftChild]);
        if (leftComp < 0) {
            swap(records, node, leftChild);
            sink(records, leftChild, arrSize);
        }
    } else if (rightChild < arrSize) {
        int rightComp = records[node].compare(records[rightChild]);
        if (rightComp < 0) {
            swap(records, node, rightChild);
            sink(records, rightChild, arrSize);
        }
    }
}

void Sorter::swap(Record* records, int index1, int index2) {
    Record temp = records[index1];
    records[index1] = records[index2];
    records[index2] = temp;
}

#endif
