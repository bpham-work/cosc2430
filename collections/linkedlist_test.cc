#include "linkedlist/linkedlist.h"
#include "gtest/gtest.h"

namespace {
    TEST(LinkedList, AppendOneValue) {
        LinkedList<int> list;

        list.append(1);

        ASSERT_EQ(1, list.size());
        ASSERT_EQ(1, list.get(0));
    }

    TEST(LinkedList, AppendTwoValues) {
        LinkedList<int> list;

        list.append(1);
        list.append(2);

        ASSERT_EQ(2, list.size());
        ASSERT_EQ(1, list.get(0));
        ASSERT_EQ(2, list.get(1));
    }

    TEST(LinkedList, PushOneValue) {
        LinkedList<int> list;

        list.push(1);

        ASSERT_EQ(1, list.size());
        ASSERT_EQ(1, list.get(0));
    }

    TEST(LinkedList, PushTwoValues) {
        LinkedList<int> list;

        list.push(1);
        list.push(2);

        ASSERT_EQ(2, list.size());
        ASSERT_EQ(2, list.get(0));
        ASSERT_EQ(1, list.get(1));
    }

    TEST(LinkedList, PeekTail) {
        LinkedList<int> list;

        list.append(1);
        list.append(2);

        ASSERT_EQ(2, list.peekTail());
    }

    TEST(LinkedList, PeekTailOnEmptyListShouldThrowError) {
        LinkedList<int> list;

        EXPECT_THROW({
            list.peekTail();
        }, std::out_of_range);
    }

    TEST(LinkedList, PeekHead) {
        LinkedList<int> list;

        list.append(1);
        list.append(2);

        ASSERT_EQ(1, list.peekHead());
    }

    TEST(LinkedList, PeekHeadOnEmptyListShouldThrowError) {
        LinkedList<int> list;

        EXPECT_THROW({
            list.peekHead();
        }, std::out_of_range);
    }

    TEST(LinkedList, GetByIndex) {
        LinkedList<int> list;

        list.append(1);
        list.append(2);

        ASSERT_EQ(1, list.get(0));
        ASSERT_EQ(2, list.get(1));
    }

    TEST(LinkedList, GetHeadByIndexShouldThrowErrorIfOutOfBounds) {
        LinkedList<int> list;

        EXPECT_THROW({
            list.get(0);
        }, std::out_of_range);
    }

    TEST(LinkedList, GetByIndexShouldThrowErrorIfOutOfBounds) {
        LinkedList<int> list;

        EXPECT_THROW({
            list.get(5);
        }, std::out_of_range);
    }

    TEST(LinkedList, PopHead) {
        LinkedList<int> list;

        list.append(1);
        list.append(2);

        ASSERT_EQ(1, list.popHead());
        ASSERT_EQ(1, list.size());
    }

    TEST(LinkedList, PopHeadOnEmptyListShouldThrowError) {
        LinkedList<int> list;

        EXPECT_THROW({
            list.popHead();
        }, std::out_of_range);
    }

    TEST(LinkedList, RemoveHead) {
        LinkedList<int> list;
        list.append(1);

        list.remove(0);

        ASSERT_EQ(0, list.size());
    }

    TEST(LinkedList, RemoveByIndex) {
        LinkedList<int> list;
        list.append(1);
        list.append(2);

        list.remove(1);

        ASSERT_EQ(1, list.size());
        ASSERT_EQ(1, list.get(0));
    }

    TEST(LinkedList, RemoveHeadOnEmptyListShouldThrowError) {
        LinkedList<int> list;

        EXPECT_THROW({
            list.remove(0);
        }, std::out_of_range);
    }

    TEST(LinkedList, RemoveByIndexOutOfBoundsError) {
        LinkedList<int> list;

        EXPECT_THROW({
            list.remove(5);
        }, std::out_of_range);
    }

    TEST(LinkedList, Clear) {
        LinkedList<int> list;
        list.append(1);
        list.append(2);

        list.clear();

        ASSERT_EQ(0, list.size());
        EXPECT_THROW({
            list.get(0);
        }, std::out_of_range);
    }
}
