#include "doublylinkedlist/doublylinkedlist.h"
#include "gtest/gtest.h"

namespace {
    TEST(DoublyLinkedList, PopLeftOnlyNodeShouldNotSegFault) {
        DoublyLinkedList<int> list;
        list.append(1);

        ASSERT_EXIT((list.popLeft(0), exit(0)),::testing::ExitedWithCode(0),".*");
    }

    TEST(DoublyLinkedList, PopLeftOnlyNode) {
        DoublyLinkedList<int> list;
        list.append(1);

        int result = list.popLeft(0);

        ASSERT_EQ(0, list.size());
        ASSERT_EQ(1, result);
    }

    TEST(DoublyLinkedList, PopLeftEmptyListShouldError) {
        DoublyLinkedList<int> list;

        EXPECT_THROW({
            list.popLeft(0);        
        }, std::out_of_range);
    }

    TEST(DoublyLinkedList, PopLeftSecondNode) {
        DoublyLinkedList<int> list;
        list.append(1);
        list.append(2);

        int result = list.popLeft(1);

        ASSERT_EQ(1, list.size());
        ASSERT_EQ(2, result);
    }

    TEST(DoublyLinkedList, PopRightOnlyNodeShouldNotSegFault) {
        DoublyLinkedList<int> list;
        list.append(1);

        ASSERT_EXIT((list.popRight(0), exit(0)),::testing::ExitedWithCode(0),".*");
    }

    TEST(DoublyLinkedList, PopRightOnlyNode) {
        DoublyLinkedList<int> list;
        list.append(1);

        int result = list.popRight(0);

        ASSERT_EQ(0, list.size());
        ASSERT_EQ(1, result);
    }

    TEST(DoublyLinkedList, PopRightEmptyListShouldError) {
        DoublyLinkedList<int> list;

        EXPECT_THROW({
            list.popRight(0);        
        }, std::out_of_range);
    }

    TEST(DoublyLinkedList, PopRightSecondNode) {
        DoublyLinkedList<int> list;
        list.append(1);
        list.append(2);

        int result = list.popRight(1);

        ASSERT_EQ(1, list.size());
        ASSERT_EQ(1, result);
    }

    TEST(DoublyLinkedList, PopOnlyHeadShouldNotSegFault) {
        DoublyLinkedList<int> list;
        list.append(1);

        ASSERT_EXIT((list.popHead(), exit(0)),::testing::ExitedWithCode(0),".*");
    }

    TEST(DoublyLinkedList, PopHeadOnlyNode) {
        DoublyLinkedList<int> list;
        list.append(1);

        int result = list.popHead();

        ASSERT_EQ(0, list.size());
        ASSERT_EQ(1, result);
    }
    
    TEST(DoublyLinkedList, AppendValue) {
        DoublyLinkedList<int> list;
        
        list.append(1);
        int result = list.peekHead();

        ASSERT_EQ(1, list.size());
        ASSERT_EQ(1, result);
    }

    TEST(DoublyLinkedList, PushValue) {
        DoublyLinkedList<int> list;
        
        list.push(1);
        list.push(2);
        int result = list.peekHead();

        ASSERT_EQ(2, list.size());
        ASSERT_EQ(2, result);
    }

    TEST(DoublyLinkedList, clear) {
        DoublyLinkedList<int> list;
        list.push(1);
        list.push(2);

        list.clear();

        ASSERT_EQ(0, list.size());
        EXPECT_THROW({
            list.peekHead();        
        }, std::out_of_range);
    }

    TEST(DoublyLinkedList, PeekHeadWhenEmptyShouldThrowError) {
        DoublyLinkedList<int> list;

        EXPECT_THROW({
            list.peekHead();        
        }, std::out_of_range);
    }

    TEST(DoublyLinkedList, PeekTailWhenEmptyShouldThrowError) {
        DoublyLinkedList<int> list;

        EXPECT_THROW({
            list.peekTail();
        }, std::out_of_range);
    }
}
