#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "node.h"
#include <string>
using namespace std;

template <class T>
class LinkedList {
    Node<T>* head;
    int count = 0;
    public:
        LinkedList();
        ~LinkedList();
        void append(T val);
        void push(T val);
        int size();
        T& peekTail();
        T& peekHead();
        T& get(int index);
        T& popHead();
        void remove(int index);
        void clear();
        void print();
        string toString();

        class iterator;
        iterator begin();
    private:
        T& peekTail(Node<T>* node);
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
    count++;
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
    count++;
}

template <class T>
int LinkedList<T>::size() {
    return count;
}

template <class T>
T& LinkedList<T>::peekTail() {
    if (this->head == nullptr) throw std::out_of_range("Out of range");
    return this->peekTail(this->head);
}

template <class T>
T& LinkedList<T>::peekTail(Node<T>* node) {
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
T& LinkedList<T>::peekHead() {
    if (this->head != nullptr)
        return this->head->val;
    throw std::out_of_range("Out of range");
}

template <class T>
T& LinkedList<T>::get(int index) {
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
T& LinkedList<T>::popHead() {
    if (this->head != nullptr) {
        Node<T>* temp = this->head;
        T* toReturn = &(this->head->val);
        this->head = this->head->next;
        temp->next = nullptr;
        delete temp;
        count--;
        return *toReturn;
    }
    throw std::out_of_range("Cannot pop from empty list");
}

template <class T>
void LinkedList<T>::remove(int index) {
    if (index == 0) this->popHead();
    else {
        int counter = 0;
        Node<T>* nodeBefore = this->head;
        while (counter < index-1) {
            if (nodeBefore == nullptr) {
                throw std::out_of_range("Index out of bounds");
            }
            nodeBefore = nodeBefore->next;
            counter++;
        }
        Node<T>* toDelete = nodeBefore->next;
        nodeBefore->next = toDelete->next;
        toDelete->next = nullptr;
        delete toDelete;
        count--;
    }
}

template <class T>
void LinkedList<T>::clear() {
    delete this->head;
    this->head = nullptr;
    count = 0;
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

template <typename T>
typename LinkedList<T>::iterator LinkedList<T>::begin() {
    return typename LinkedList<T>::iterator(this->head);
}

template <class T>
class LinkedList<T>::iterator {
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
