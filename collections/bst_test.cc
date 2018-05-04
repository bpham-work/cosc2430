#include "gtest/gtest.h"
#include "bst/bst.h"
#include "bst/avlbst.h"
#include <vector>
#include <iostream>
#include <stdexcept>
#include <chrono>
using namespace std;

namespace {
    TEST(Bst, Insert) {
        Bst<int, int> bst;
        vector<int> result;

        bst.insert(1);
        bst.insert(2);
        bst.insert(3);
        bst.insert(4);
        bst.insert(5);
        
        bst.inOrder(result);

        for (int i = 1; i <= 5; i++) {
            ASSERT_EQ(i, result[i-1]);
        }
    }

    TEST(Bst, InOrder) {
        Bst<int, int> bst;
        vector<int> result;

        bst.insert(10);
        bst.insert(5);
        bst.insert(15);
        bst.insert(1);
        bst.insert(3);
        bst.insert(12);
        bst.insert(17);
        bst.inOrder(result);

        ASSERT_EQ(1, result[0]);
        ASSERT_EQ(3, result[1]);
        ASSERT_EQ(5, result[2]);
        ASSERT_EQ(10, result[3]);
        ASSERT_EQ(12, result[4]);
        ASSERT_EQ(15, result[5]);
        ASSERT_EQ(17, result[6]);
    }

    TEST(Bst, PreOrder) {
        Bst<int, int> bst;
        vector<int> result;

        bst.insert(10);
        bst.insert(5);
        bst.insert(15);
        bst.insert(1);
        bst.insert(3);
        bst.insert(12);
        bst.insert(17);
        bst.preOrder(result);

        ASSERT_EQ(10, result[0]);
        ASSERT_EQ(5, result[1]);
        ASSERT_EQ(1, result[2]);
        ASSERT_EQ(3, result[3]);
        ASSERT_EQ(15, result[4]);
        ASSERT_EQ(12, result[5]);
        ASSERT_EQ(17, result[6]);
    }

    TEST(Bst, PostOrder) {
        Bst<int, int> bst;
        vector<int> result;

        bst.insert(10);
        bst.insert(5);
        bst.insert(15);
        bst.insert(1);
        bst.insert(7);
        bst.insert(12);
        bst.insert(17);
        bst.postOrder(result);

        ASSERT_EQ(1, result[0]);
        ASSERT_EQ(7, result[1]);
        ASSERT_EQ(5, result[2]);
        ASSERT_EQ(12, result[3]);
        ASSERT_EQ(17, result[4]);
        ASSERT_EQ(15, result[5]);
        ASSERT_EQ(10, result[6]);
    }

    TEST(Bst, LevelOrder) {
        Bst<int, int> bst;
        vector<int> result;

        bst.insert(10);
        bst.insert(5);
        bst.insert(15);
        bst.insert(1);
        bst.insert(7);
        bst.insert(12);
        bst.insert(17);
        bst.levelOrder(result);

        ASSERT_EQ(10, result[0]);
        ASSERT_EQ(5, result[1]);
        ASSERT_EQ(15, result[2]);
        ASSERT_EQ(1, result[3]);
        ASSERT_EQ(7, result[4]);
        ASSERT_EQ(12, result[5]);
        ASSERT_EQ(17, result[6]);
    }

    TEST(Bst, Get) {
        Bst<int, int> bst;

        bst.insert(10);
        bst.insert(5);
        bst.insert(15);
        bst.insert(1);
        bst.insert(7);
        bst.insert(12);
        bst.insert(17);

        ASSERT_EQ(7, bst.get(7));
    }

    TEST(Bst, GetOutOfRange) {
        Bst<int, int> bst;

        bst.insert(10);
        bst.insert(5);
        bst.insert(15);
        bst.insert(1);
        bst.insert(7);
        bst.insert(12);
        bst.insert(17);

        ASSERT_THROW(bst.get(100), out_of_range);
    }

    TEST(Bst, Height1) {
        Bst<int, int> bst;

        bst.insert(10);
        bst.insert(5);
        bst.insert(15);
        bst.insert(1);
        bst.insert(7);
        bst.insert(12);
        bst.insert(17);

        ASSERT_EQ(2, bst.height());
    }

    TEST(Bst, Test) {
        Bst<int, int> bst;
        Bst<int, int> avl_bst;

        for (int i = 0; i < 100000; i++) {
            bst.insert(i);
            avl_bst.insert(i);
        }
        auto bst_time_start = chrono::system_clock::now();
        bst.insert(99999999);
        auto bst_time_end = chrono::system_clock::now();
        auto bst_elapsed = chrono::duration_cast<chrono::milliseconds>(bst_time_end - bst_time_start);

        auto avlbst_time_start = chrono::system_clock::now();
        avl_bst.insert(999999999);
        auto avlbst_time_end = chrono::system_clock::now();
        auto avlbst_elapsed = chrono::duration_cast<chrono::milliseconds>(avlbst_time_end - avlbst_time_start);
        cout << "Bst elapsed: " << bst_elapsed.count() << endl;
        cout << "Avl Bst elapsed: " << avlbst_elapsed.count() << endl;
    }
}
