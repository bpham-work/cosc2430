#ifndef NODE_H
#define NODE_H

template <class T>
class DoublyNode {
    public:
        DoublyNode(T val);
        ~DoublyNode();
        T val;
        DoublyNode* next;
        DoublyNode* prev;
        void clearLinks();
};

template <class T>
DoublyNode<T>::DoublyNode(T val) {
    this->val = val;
    this->next = nullptr;
    this->prev = nullptr;
}

template <class T>
DoublyNode<T>::~DoublyNode() {
    if (this->next != nullptr) delete this->next;
}

template <class T>
void DoublyNode<T>::clearLinks() {
    this->next = nullptr;
    this->prev = nullptr;
}

#endif
