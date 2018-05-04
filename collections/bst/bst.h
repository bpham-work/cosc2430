#ifndef BST_H
#define BST_H

#include "node.h"

#include <iostream>
#include <vector>
#include <queue>
#include <stdexcept>
#include <algorithm>
using namespace std;

template <class Q, class T>
class Bst {
    int totalSize = 0;
    public:
        BstNode<Q, T>* root;
        Bst();
        void insert(T val);
        void insert(Q key, T val);
        void inOrder(vector<T>& container);
        void preOrder(vector<T>& container);
        void postOrder(vector<T>& container);
        void levelOrder(vector<T>& container);
        int size();
        T& get(Q key);
        int height();
    private:
        BstNode<Q, T>* insert(T val, BstNode<Q, T>* node);
        void inOrder(vector<T>& container, BstNode<Q, T>* node);
        void preOrder(vector<T>& container, BstNode<Q, T>* node);
        void postOrder(vector<T>& container, BstNode<Q, T>* node);
        T& get(Q key, BstNode<Q, T>* node);
        int height(BstNode<Q, T>* node);
};

template <class Q, class T>
Bst<Q, T>::Bst() {
    root = nullptr;
}

template <class Q, class T>
void Bst<Q, T>::insert(T val) {
    totalSize++;
    root = insert(val, root);
}

template <class Q, class T>
BstNode<Q, T>* Bst<Q, T>::insert(T val, BstNode<Q, T>* node) {
    if (node == nullptr || node->val == val) {
        return new BstNode<Q, T>(val);
    } else if (val < node->val) {
        node->left = insert(val, node->left);
    } else if (val > node->val) {
        node->right = insert(val, node->right);
    }
    return node;
}

template <class Q, class T>
void Bst<Q, T>::inOrder(vector<T>& container) {
    inOrder(container, root);
}

template <class Q, class T>
void Bst<Q, T>::inOrder(vector<T>& container, BstNode<Q, T>* node) {
    if (node != nullptr) {
        inOrder(container, node->left);
        container.push_back(node->val);
        inOrder(container, node->right);
    }
}

template <class Q, class T>
void Bst<Q, T>::preOrder(vector<T>& container) {
    preOrder(container, root);
}

template <class Q, class T>
void Bst<Q, T>::preOrder(vector<T>& container, BstNode<Q, T>* node) {
    if (node != nullptr) {
        container.push_back(node->val);
        preOrder(container, node->left);
        preOrder(container, node->right);
    }
}

template <class Q, class T>
void Bst<Q, T>::postOrder(vector<T>& container) {
    postOrder(container, root);
}

template <class Q, class T>
void Bst<Q, T>::postOrder(vector<T>& container, BstNode<Q, T>* node) {
    if (node == nullptr) {
        return;
    }
    postOrder(container, node->left);
    postOrder(container, node->right);
    container.push_back(node->val);
}

template <class Q, class T>
void Bst<Q, T>::levelOrder(vector<T>& container) {
    queue<BstNode<Q, T>> q;
    if (root != nullptr) {
        q.push(*root);
    }
    while (!q.empty()) {
        container.push_back(q.front().val);
        if (q.front().left != nullptr) {
            q.push(*(q.front().left));
        }
        if (q.front().right != nullptr) {
            q.push(*(q.front().right));
        }
        q.pop();
    }
}

template <class Q, class T>
int Bst<Q, T>::size() {
    return totalSize;
}

template <class Q, class T>
T& Bst<Q, T>::get(Q key) {
    return get(key, root);
}

template <class Q, class T>
T& Bst<Q, T>::get(Q key, BstNode<Q, T>* node) {
    if (node == nullptr) {
        throw out_of_range("Value does not exist in tree");
    } else if (key == node->key) {
        return node->val;
    } else if (key < node->key) {
        return get(key, node->left);
    } else {
        return get(key, node->right);
    }
}

template <class Q, class T>
int Bst<Q, T>::height() {
    return height(root);
}
template <class Q, class T>
int Bst<Q, T>::height(BstNode<Q, T>* node) {
    if (node == nullptr) {
        return -1;
    }
    int left = height(node->left);
    int right = height(node->right);
    return max(left, right) + 1;    
}
#endif
