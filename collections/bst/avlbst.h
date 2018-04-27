#ifndef AVL_BST_H
#define AVL_BST_H

#include "node.h"
#include <iostream>
#include <vector>
using namespace std;

template <class Q, class T>
class AvlBst {
    BstNode<Q, T>* root;
    public:
        AvlBst();
        int height();
        int height(BstNode<Q, T>* node);
        int max(int int1, int int2);
        void insert(T val);
        void insert(Q key, T val);
        BstNode<Q, T>* insert(BstNode<Q, T>* node, T val);
        BstNode<Q, T>* insert(BstNode<Q, T>* node, Q key, T val);
        BstNode<Q, T>* rightRotate(BstNode<Q, T>* node);
        BstNode<Q, T>* leftRotate(BstNode<Q, T>* node);
        void printInOrder();
        void printInOrder(BstNode<Q, T>* node);
        vector<T> getValuesInOrder();
        vector<T> getValuesInOrder(BstNode<Q, T>* node, vector<T>& result);
};

template <class Q, class T>
AvlBst<Q, T>::AvlBst() {
    root = nullptr;
}

template <class Q, class T>
int AvlBst<Q, T>::height() {
    if (root == nullptr) return 0;
    return height(root) - 1;
}

template <class Q, class T>
int AvlBst<Q, T>::height(BstNode<Q, T>* node) {
    if (node == nullptr) return 0;
    int leftHeight = height(node->left);
    int rightHeight = height(node->right);
    return max(leftHeight, rightHeight) + 1;
}

template <class Q, class T>
int AvlBst<Q, T>::max(int int1, int int2) {
    return (int1 > int2) ? int1 : int2;
}

template <class Q, class T>
void AvlBst<Q, T>::insert(T val) {
    if (root == nullptr) {
        root = new BstNode<Q, T>(val);
    } else {
        insert(root, val);
    }
}

template <class Q, class T>
BstNode<Q, T>* AvlBst<Q, T>::insert(BstNode<Q, T>* node, T val) {
    if (node == nullptr) {
        return new BstNode<Q, T>(val);
    } else if (val < node->val) {
        node->left = insert(node->left, val);
    } else if (val > node->val) {
        node->right = insert(node->right, val);
    } else {
        return node;
    }
    //int balance = height(node->left) - height(node->right);
    //// left left
    //if (balance > 1 && val < node->left->val) {
    //    return rightRotate(node);
    //}
    //// right right
    //if (balance < -1 && val > node->right->val) {
    //    return leftRotate(node);
    //}
    //// left right
    //if (balance > 1 && val > node->left->val) {
    //    cout << "left right" << endl;
    //    node->left = leftRotate(node->left);
    //    return rightRotate(node);
    //}
    //// right left
    //if (balance < -1 && val < node->right->val) {
    //    cout << "right left" << endl;
    //    node->right = rightRotate(node->right);
    //    return leftRotate(node);
    //}
    return node;
}

template <class Q, class T>
void AvlBst<Q, T>::insert(Q key, T val) {
    root = insert(root, key, val);
}

template <class Q, class T>
BstNode<Q, T>* AvlBst<Q, T>::insert(BstNode<Q, T>* node, Q key, T val) {
    if (node == nullptr || key == node->key) {
        return new BstNode<Q, T>(key, val);
    } else if (key < node->key) {
        node->left = insert(node->left, key, val);
    } else if (key > node->key) {
        node->right = insert(node->right, key, val);
    }
    return node;
}

template <class Q, class T>
void AvlBst<Q, T>::printInOrder() {
    printInOrder(root);
    cout << endl;
}

template <class Q, class T>
BstNode<Q, T>* AvlBst<Q, T>::rightRotate(BstNode<Q, T>* node) {
    //BstNode<Q, T>* temp1 = node->left;
    //BstNode<Q, T>* temp2 = temp1->right;
    //temp1->right = node;
    //node->left = temp2;
    BstNode<Q, T>* temp = node->left;
    node->left = temp->right;
    temp->right = node;
    return temp;
}

template <class Q, class T>
BstNode<Q, T>* AvlBst<Q, T>::leftRotate(BstNode<Q, T>* node) {
    //BstNode<Q, T>* temp1 = node->right;
    //BstNode<Q, T>* temp2 = temp1->left;
    //temp1->left = node;
    //node->right = temp2;
    //return temp1;
    BstNode<Q, T>* temp = node->right;
    node->right = temp->left;
    temp->left = node;
    return temp;
}

template <class Q, class T>
void AvlBst<Q, T>::printInOrder(BstNode<Q, T>* node) {
    if (node != nullptr) {
        printInOrder(node->left);
        cout << node->val << " ";
        printInOrder(node->right);
    }
}

template <class Q, class T>
vector<T> AvlBst<Q, T>::getValuesInOrder() {
    vector<T> result;
    return getValuesInOrder(root, result);
}

template <class Q, class T>
vector<T> AvlBst<Q, T>::getValuesInOrder(BstNode<Q, T>* node, vector<T>& result) {
    if (node != nullptr) {
        getValuesInOrder(node->left, result);
        result.push_back(node->val);
        getValuesInOrder(node->right, result);
    }
    return result;
}

#endif
