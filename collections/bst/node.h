#ifndef BST_NODE_H
#define BST_NODE_H

template <class Q, class T>
class BstNode {
    public:
        BstNode* left;
        BstNode* right;
        Q key;
        T val;
        BstNode();
        BstNode(T& val);
        BstNode(Q& key, T& val);
};

template <class Q, class T>
BstNode<Q, T>::BstNode() {
    left = nullptr;
    right = nullptr;
}

template <class Q, class T>
BstNode<Q, T>::BstNode(T& val) {
    this->key = val;
    this->val = val;
    left = nullptr;
    right = nullptr;
}

template <class Q, class T>
BstNode<Q, T>::BstNode(Q& key, T& val) {
    this->key = key;
    this->val = val;
    left = nullptr;
    right = nullptr;
}

#endif
