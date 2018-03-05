#include "linkedlist/circularlinkedlist.h"
#include "gtest/gtest.h"

namespace {
    TEST(CircularLinkedList, AppendOneValue) {
        CircularLinkedList<int> list;

        list.append(1);

        ASSERT_EQ(1, list.size());
        ASSERT_EQ(1, list.get(0));
    }

    TEST(CircularLinkedList, AppendTwoValues) {
        CircularLinkedList<int> list;

        list.append(1);
        list.append(2);

        ASSERT_EQ(2, list.size());
        ASSERT_EQ(1, list.get(0));
        ASSERT_EQ(2, list.get(1));
    }

    TEST(CircularLinkedList, GetByIndex) {
        CircularLinkedList<int> list;

        list.append(1);
        list.append(2);

        ASSERT_EQ(1, list.get(0));
        ASSERT_EQ(2, list.get(1));
    }

    TEST(CircularLinkedList, GetHeadByIndexShouldThrowErrorIfOutOfBounds) {
        CircularLinkedList<int> list;

        EXPECT_THROW({
            list.get(0);
        }, std::out_of_range);
    }

    TEST(CircularLinkedList, GetByIndexShouldThrowErrorIfOutOfBounds) {
        CircularLinkedList<int> list;

        EXPECT_THROW({
            list.get(5);
        }, std::out_of_range);
    }

    TEST(CircularLinkedList, Clear) {
        CircularLinkedList<int> list;
        list.append(1);
        list.append(2);

        list.clear();

        ASSERT_EQ(0, list.size());
        EXPECT_THROW({
            list.get(0);
        }, std::out_of_range);
    }

    TEST(CircularLinkedList, GetNextShouldCycleThroughNodes) {
         CircularLinkedList<int> list;
         list.append(1);
         list.append(2);
         list.append(3);

         ASSERT_EQ(1, list.getNext());
         ASSERT_EQ(2, list.getNext());
         ASSERT_EQ(3, list.getNext());
         ASSERT_EQ(1, list.getNext());
     }

    TEST(CircularLinkedList, GetNextShouldThrowErrorOnEmptyList) {
         CircularLinkedList<int> list;

         EXPECT_THROW({
             list.getNext();
         }, std::out_of_range);
     }
}
