#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include "doublynode.h"
#include <string>
#include <iostream>
using namespace std;

template <class T>
class DoublyLinkedList {
    DoublyNode<T>* head;
    DoublyNode<T>* tail;
    int count = 0;
    public:
        DoublyLinkedList();
        ~DoublyLinkedList();
        void append(T val);
        void push(T val);
        int size();
        T& peekTail();
        T& peekHead();
        T& popLeft(int position);
        T& popHead();
        T& popRight(int position);
        void deleteNode(DoublyNode<T>* node);
        void clear();
        void print();
        string toString();
        T* toArray();

        class iterator;
        iterator begin();
};

template <class T>
DoublyLinkedList<T>::DoublyLinkedList() {
    this->head = nullptr;
    this->tail = nullptr;
}

template <class T>
DoublyLinkedList<T>::~DoublyLinkedList() {
    delete this->head;
}

template <class T>
void DoublyLinkedList<T>::append(T val) {
    DoublyNode<T>* newNode = new DoublyNode<T>(val);
    if (this->head == nullptr) {
        this->head = this->tail = newNode;
    } else {
        this->tail->next = newNode;
        newNode->prev = this->tail;
        this->tail = newNode;
    }
    count++;
}

template <class T>
void DoublyLinkedList<T>::push(T val) {
    DoublyNode<T>* newNode = new DoublyNode<T>(val);
    if (this->head == nullptr) {
        this->head = this->tail = newNode;
    } else {
        this->head->prev = newNode;
        newNode->next = this->head;
        this->head = newNode;
    }
    count++;
}

template <class T>
int DoublyLinkedList<T>::size() {
    return count;
}

template <class T>
T& DoublyLinkedList<T>::peekTail() {
    if (this->tail != nullptr)
        return this->tail->val;
    throw std::out_of_range("Out of range");
}

template <class T>
T& DoublyLinkedList<T>::peekHead() {
    if (this->head != nullptr)
        return this->head->val;
    throw std::out_of_range("Out of range");
}

template <class T>
T& DoublyLinkedList<T>::popHead() {
    return this->popLeft(0);
}

template <class T>
T& DoublyLinkedList<T>::popLeft(int index) {
    if (this->head == nullptr) {
        throw std::out_of_range("Out of range");
    }
    int counter = 0;
    DoublyNode<T>* node = this->head;
    while (counter < index) {
        node = node->next;
        counter++;
    }
    T* val = &(node->val);
    this->deleteNode(node);
    return *val;
}

template <class T>
T& DoublyLinkedList<T>::popRight(int index) {
    if (this->tail == nullptr) {
        throw std::out_of_range("Out of range");
    }
    int counter = 0;
    DoublyNode<T>* node = this->tail;
    while (counter < index) {
        node = node->prev;
        counter++;
    }
    T* val = &(node->val);
    this->deleteNode(node);
    return *val;
}

template <class T>
void DoublyLinkedList<T>::deleteNode(DoublyNode<T>* node) {
    if (node->prev == nullptr && node->next == nullptr) {
        this->head = nullptr;
        this->tail = nullptr;
    } else if (node->prev == nullptr) {
        this->head = node->next;
        this->head->prev = nullptr;
    } else if (node->next == nullptr) {
        this->tail = node->prev;
        this->tail->next = nullptr;
    } else {
        DoublyNode<T>* prevNode = node->prev;
        DoublyNode<T>* nextNode = node->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }
    node->clearLinks();
    count--;
    delete node;
}

template <class T>
void DoublyLinkedList<T>::clear() {
    count = 0;
    delete this->head;
    this->head = nullptr;
}

template <class T>
void DoublyLinkedList<T>::print() {
    DoublyNode<T>* node = this->head;
    while (node != nullptr) {
        cout << node->val;
        node = node->next;
    }
    cout << endl;
}

template <class T>
string DoublyLinkedList<T>::toString() {
    string result;
    DoublyNode<T>* node = this->head;
    while (node != nullptr) {
        result += node->val;
        node = node->next;
    }
    return result;
}

template <class T>
T* DoublyLinkedList<T>::toArray() {
    T* array =  new T[count];
    int counter = 0;
    DoublyNode<T>* node = this->head;
    while (node != nullptr) {
        array[counter] = node->val;
        node = node->next;
        counter++;
    }
    return array;
}

template <typename T>
typename DoublyLinkedList<T>::iterator DoublyLinkedList<T>::begin() {
    return typename DoublyLinkedList<T>::iterator(this->head);
}

template <class T>
class DoublyLinkedList<T>::iterator {
    DoublyNode<T>* current;
    public:
        iterator(DoublyNode<T>* head) { this->current = head; }
        iterator& operator++() {
            current = current->next;
            return *this;
        }
        iterator& operator++(int a) {
            current = current->next;
            return *this;
        }
        T* operator*() { return current->val; }
        bool operator!=(bool end) { return end; }
        bool end() { return current == nullptr;  }
};

#endif
