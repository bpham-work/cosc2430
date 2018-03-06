#ifndef STACK_H
#define STACK_H

#include "node.h"

template <class T>
class Stack {
    Node<T>* head;
    int length = 0;
    public:
        Stack();
        int size();
        void push(T val);
        T& pop();
        T& peek();
        bool isEmpty();
};

template <class T>
Stack<T>::Stack() {}

template <class T>
int Stack<T>::size() {
    return length;
}

template <class T>
void Stack<T>::push(T val) {
    length++;
    Node<T>* newNode = new Node<T>(val);
    newNode->next = head;
    head = newNode;
}

template <class T>
T& Stack<T>::pop() {
    length--;
    Node<T>* toDelete = head;
    T* toReturn = new T;
    *toReturn = toDelete->val;
    head = head->next;
    delete toDelete;
    return *(toReturn);
}

template <class T>
T& Stack<T>::peek() {
    return head->val;
}

template <class T>
bool Stack<T>::isEmpty() {
    return length == 0;
}

#endif
