#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "node.h"
#include <string>
#include <stdexcept>
using namespace std;

template <class T>
class CircularLinkedList {
    Node<T>* head;
    Node<T>* tail;
    Node<T>* current;
    int count = 0;
    public:
        CircularLinkedList();
        ~CircularLinkedList();
        void append(T val);
        int size();
        T& get(int index);
        T& getNext();
        void clear();
        void print();
        string toString();

        class iterator;
        iterator begin();
    private:
        Node<T>* getTail();
};

template <class T>
CircularLinkedList<T>::CircularLinkedList() {
    this->head = nullptr;
    this->current = nullptr;
    this->tail = nullptr;
}

template <class T>
CircularLinkedList<T>::~CircularLinkedList() {
    delete this->head;
}

template <class T>
void CircularLinkedList<T>::append(T val) {
    Node<T>* newNode = new Node<T>(val);
    if (this->head == nullptr) {
        this->head = this->tail = this->current = newNode;
        this->tail->next = this->head;
    } else {
        tail->next = newNode;
        tail = newNode;
        tail->next = head;
    }
    count++;
}

template <class T>
int CircularLinkedList<T>::size() {
    return count;
}

template <class T>
Node<T>* CircularLinkedList<T>::getTail() {
    Node<T>* tail = this->head;
    while (tail->next != nullptr) tail = tail->next;
    return tail;
}

template <class T>
T& CircularLinkedList<T>::get(int index) {
    if (head == nullptr) {
        throw std::out_of_range("Index out of bounds");
    }
    int counter = 0;
    Node<T>* node = this->head;
    while (counter < index) {
        if (node == nullptr) {
            throw std::out_of_range("Index out of bounds");
        }
        node = node->next;
        counter++;
    }
    return node->val;
}

template <class T>
T& CircularLinkedList<T>::getNext() {
    if (current == nullptr) {
        throw std::out_of_range("Index out of bounds");
    }
    Node<T>* curr = this->current;
    current = current->next;
    return curr->val;
}

template <class T>
void CircularLinkedList<T>::clear() {
    delete this->head;
    this->head = nullptr;
    count = 0;
}

template <class T>
void CircularLinkedList<T>::print() {
    Node<T>* node = this->head;
    while (node != nullptr) {
        cout << node->val;
        node = node->next;
    }
    cout << endl;
}

template <class T>
string CircularLinkedList<T>::toString() {
    string result;
    Node<T>* node = this->head;
    while (node != nullptr) {
        result += node->val;
        node = node->next;
    }
    return result;
}

template <typename T>
typename CircularLinkedList<T>::iterator CircularLinkedList<T>::begin() {
    return typename CircularLinkedList<T>::iterator(this->head);
}

template <class T>
class CircularLinkedList<T>::iterator {
    Node<T>* current;
    public:
        iterator(Node<T>* head) { this->current = head; }
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
