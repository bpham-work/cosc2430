#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "node.h"
#include <string>
using namespace std;

template <class T>
class LinkedList {
    Node<T>* head;
    public:
        LinkedList();
        ~LinkedList();
        void append(T val);
        void push(T val);
        T peekTail();
        T peekHead();
        void rotate();
        void clear();
        void print();
        string toString();
    private:
        T peekTail(Node<T>* node);
        Node<T>* getTail();
};

template <class T>
LinkedList<T>::LinkedList() {
    this->head = nullptr;
}

template <class T>
LinkedList<T>::~LinkedList() {
    delete this->head;
}

template <class T>
void LinkedList<T>::append(T val) {
    Node<T>* newNode = new Node<T>(val);
    if (this->head == nullptr) {
        this->head = newNode;
    } else {
        Node<T>* tail = this->getTail();
        tail->next = newNode;
    }
}

template <class T>
void LinkedList<T>::push(T val) {
    Node<T>* newNode = new Node<T>(val);
    if (this->head == nullptr) {
        this->head = newNode;
    } else {
        Node<T>* temp = this->head;
        newNode->next = temp;
        this->head = newNode;
    }
}

template <class T>
T LinkedList<T>::peekTail() {
    return this->peekTail(this->head);
}

template <class T>
T LinkedList<T>::peekTail(Node<T>* node) {
    if (node->next == nullptr) return node->val;
    return this->peekTail(node->next);
}

template <class T>
Node<T>* LinkedList<T>::getTail() {
    Node<T>* tail = this->head;
    while (tail->next != nullptr) tail = tail->next;
    return tail;
}

template <class T>
T LinkedList<T>::peekHead() {
    //if (this->head != nullptr)
        return this->head->val;
    //return nullptr;
}

template <class T>
void LinkedList<T>::rotate() {
    Node<T>* tail = this->getTail();
    Node<T>* temp = this->head;
    this->head = this->head->next;
    temp->next = nullptr;
    tail->next = temp;
}

template <class T>
void LinkedList<T>::clear() {
    delete this->head;
    this->head = nullptr;
}

template <class T>
void LinkedList<T>::print() {
    Node<T>* node = this->head;
    while (node != nullptr) {
        cout << node->val;
        node = node->next;
    }
    cout << endl;
}

template <class T>
string LinkedList<T>::toString() {
    string result;
    Node<T>* node = this->head;
    while (node != nullptr) {
        result += node->val;
        node = node->next;
    }
    return result;
}

#endif
