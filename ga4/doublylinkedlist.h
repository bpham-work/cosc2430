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
    public:
        DoublyLinkedList();
        ~DoublyLinkedList();
        void append(T& val);
        void push(T& val);
        T* peekTail();
        T* peekHead();
        T* popFromLeft(int position);
        T* popHead();
        T* popFromRight(int position);
        void deleteNode(DoublyNode<T>* node);
        void clear();
        void print();
        string toString();

        class iterator;
        iterator begin();
};

template <class T>
DoublyLinkedList<T>::DoublyLinkedList() {
    this->head = nullptr;
}

template <class T>
DoublyLinkedList<T>::~DoublyLinkedList() {
    delete this->head;
}

template <class T>
void DoublyLinkedList<T>::append(T& val) {
    DoublyNode<T>* newNode = new DoublyNode<T>(val);
    if (this->head == nullptr) {
        this->head = newNode;
        this->tail = newNode;
    } else {
        DoublyNode<T>* temp = this->tail;
        temp->next = newNode;
        newNode->prev = temp;
        this->tail = newNode;
    }
}

template <class T>
void DoublyLinkedList<T>::push(T& val) {
    DoublyNode<T>* newNode = new DoublyNode<T>(val);
    if (this->head == nullptr) {
        this->head = newNode;
        this->tail = newNode;
    } else {
        DoublyNode<T>* temp = this->head;
        newNode->next = temp;
        this->head = newNode;
    }
}

template <class T>
T* DoublyLinkedList<T>::peekTail() {
    if (this->tail != nullptr)
        return this->tail->val;
    return nullptr;
}

template <class T>
T* DoublyLinkedList<T>::peekHead() {
    if (this->head != nullptr)
        return this->head->val;
    return nullptr;
}

template <class T>
T* DoublyLinkedList<T>::popHead() {
    return this->popFromLeft(0);
}

template <class T>
T* DoublyLinkedList<T>::popFromLeft(int index) {
    //if (this->head == nullptr) return NULL;
    int counter = 0;
    DoublyNode<T>* node = this->head;
    while (counter < index) {
        node = node->next;
        counter++;
    }
    T* val = node->val;
    this->deleteNode(node);
    return val;
}

template <class T>
T* DoublyLinkedList<T>::popFromRight(int index) {
    //if (this->tail == nullptr) return NULL;
    int counter = 0;
    DoublyNode<T>* node = this->tail;
    while (counter < index) {
        node = node->prev;
        counter++;
    }
    T* val = node->val;
    this->deleteNode(node);
    return val;
}

template <class T>
void DoublyLinkedList<T>::deleteNode(DoublyNode<T>* node) {
    if (node->prev == nullptr) {
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
    delete node;
}

template <class T>
void DoublyLinkedList<T>::clear() {
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
