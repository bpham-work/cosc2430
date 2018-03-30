#ifndef STACK_H
#define STACK_H

#include <string>
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
        string toString();
        bool operator==(Stack<T>& otherStack);
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

template <class T>
string Stack<T>::toString() {
    string result = "";
    while (!this->isEmpty()) {
        result.insert(0, 1, this->pop());
    }
    return result;
}

template <class T>
bool Stack<T>::operator==(Stack<T>& otherStack) {
    if (this->size() != otherStack.size()) return false;
    T* stack1Val = new T;
    T* stack2Val = new T;
    Stack<T> temp;
    bool isSame = true;
    while (!this->isEmpty()) {
        *stack1Val = this->peek();
        *stack2Val = otherStack.peek();
        temp.push(this->pop());
        otherStack.pop();
        if (*stack1Val != *stack2Val) {
            isSame = false;
            break;
        }
    }
    while (!temp.isEmpty()) {
        T val = temp.pop();
        this->push(val);
        otherStack.push(val);
    }
    delete stack1Val;
    delete stack2Val;
    return isSame;
}
#endif
