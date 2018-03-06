#ifndef QUEUE_H
#define QUEUE_H

#include "node.h"

template <class T>
class Queue {
    Node<T>* head;
    Node<T>* tail;
    int length = 0;
    public:
        Queue();
        int size();
        void enqueue(T val);
        T& dequeue();
        T& peek();
        bool isEmpty();
};

template <class T>
Queue<T>::Queue() {
    head = nullptr;
    tail = nullptr;
}

template <class T>
int Queue<T>::size() {
    return length;
}

template <class T>
void Queue<T>::enqueue(T val) {
    length++;
    Node<T>* newNode = new Node<T>(val);
    if (head == nullptr) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}

template <class T>
T& Queue<T>::dequeue() {
    length--;
    Node<T>* toDelete = head;
    T* toReturn = new T;
    *toReturn = toDelete->val;
    head = head->next;
    delete toDelete;
    return *(toReturn);
}

template <class T>
T& Queue<T>::peek() {
    return head->val;
}

template <class T>
bool Queue<T>::isEmpty() {
    return length == 0;
}

#endif
