#include "gtest/gtest.h"
#include "bst/avlbst.h"

namespace {
    TEST(AvlBst, Test) {
        AvlBst<int, int> bst;

        bst.insert(10);        
        bst.insert(5);        
        bst.insert(20);        
        bst.insert(30);        
        bst.printInOrder();
        ASSERT_EQ(2, bst.height());
    }

    TEST(AvlBst, Test2) {
        AvlBst<int, int> bst;

        bst.insert(10);        
        bst.insert(100);        
        bst.insert(20);        
        bst.insert(30);        
        bst.printInOrder();
        //ASSERT_EQ(2, bst.height());
    }

    TEST(AvlBst, Test3) {
        AvlBst<int, int> bst;

        bst.insert(10, 10);        
        bst.insert(5, 5);        
        bst.insert(20, 20);        
        bst.insert(30, 30);        
        bst.printInOrder();
        ASSERT_EQ(2, bst.height());
    }

    TEST(AvlBst, Test4) {
        AvlBst<int, int> bst;

        bst.insert(10, 10);        
        bst.insert(100, 100);        
        bst.insert(20, 20);        
        bst.insert(30, 30);        
        bst.printInOrder();
        //ASSERT_EQ(2, bst.height());
    }
}
