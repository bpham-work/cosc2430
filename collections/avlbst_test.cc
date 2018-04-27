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

    TEST(AvlBst, RightRightBalance) {
        AvlBst<int, int> bst;

        bst.insert(10);        
        bst.insert(100);        
        bst.insert(200);        
        bst.printInOrder();
        ASSERT_EQ(1, bst.height());
    }

    TEST(AvlBst, LeftLeftBalance) {
        AvlBst<int, int> bst;

        bst.insert(100);        
        bst.insert(10);        
        bst.insert(1);        
        bst.printInOrder();
        ASSERT_EQ(1, bst.height());
    }

    TEST(AvlBst, LeftRightBalance) {
        AvlBst<int, int> bst;

        bst.insert(100);        
        bst.insert(10);        
        bst.insert(50);        
        bst.printInOrder();
        ASSERT_EQ(1, bst.height());
    }

    TEST(AvlBst, RightLeftBalance) {
        AvlBst<int, int> bst;

        bst.insert(10);        
        bst.insert(100);        
        bst.insert(50);        
        bst.printInOrder();
        ASSERT_EQ(1, bst.height());
    }

    TEST(AvlBst, RightLeftRightSubBalance) {
        AvlBst<int, int> bst;

        bst.insert(10);        
        bst.insert(100);        
        bst.insert(20);        
        bst.insert(30);        
        bst.printInOrder();
        ASSERT_EQ(2, bst.height());
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

    TEST(AvlBst, RightRightBalance2) {
        AvlBst<int, int> bst;

        bst.insert(10, 10);        
        bst.insert(100, 100);        
        bst.insert(200, 200);        
        bst.printInOrder();
        ASSERT_EQ(1, bst.height());
    }

    TEST(AvlBst, LeftLeftBalance2) {
        AvlBst<int, int> bst;

        bst.insert(100, 100);        
        bst.insert(10, 10);        
        bst.insert(1, 1);        
        bst.printInOrder();
        ASSERT_EQ(1, bst.height());
    }

    TEST(AvlBst, LeftRightBalance2) {
        AvlBst<int, int> bst;

        bst.insert(100, 100);        
        bst.insert(10, 10);        
        bst.insert(50, 50);        
        bst.printInOrder();
        ASSERT_EQ(1, bst.height());
    }

    TEST(AvlBst, RightLeftBalance2) {
        AvlBst<int, int> bst;

        bst.insert(10, 10);        
        bst.insert(100, 100);        
        bst.insert(50, 50);        
        bst.printInOrder();
        ASSERT_EQ(1, bst.height());
    }

    TEST(AvlBst, RightLeftRightSubBalance2) {
        AvlBst<int, int> bst;

        bst.insert(10, 10);        
        bst.insert(100, 100);        
        bst.insert(20, 20);        
        bst.insert(30, 30);        
        bst.printInOrder();
        ASSERT_EQ(2, bst.height());
    }
}
