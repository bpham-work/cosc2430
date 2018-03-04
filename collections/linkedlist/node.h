#ifndef NODE_H
#define NODE_H

#include <iostream>
using namespace std;

template <class T>
class Node {
    public:
        Node();
        Node(T& val);
        ~Node();
        T val;
        Node* next;
};

template <class T>
Node<T>::Node() {
    this->next = nullptr;
}

template <class T>
Node<T>::Node(T& val) {
    this->val = val;
    this->next = nullptr;
}

template <class T>
Node<T>::~Node() {
    if (this->next != nullptr) delete this->next;
}

#endif
