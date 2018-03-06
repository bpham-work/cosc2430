#include "gtest/gtest.h"
#include "stack/stack.h"

namespace {
    TEST(Stack, ShouldPushValue) {
        Stack<int> stack;
        
        stack.push(1);

        ASSERT_EQ(1, stack.peek());
        ASSERT_EQ(1, stack.size());
    }

    TEST(Stack, ShouldPushTwoValues) {
        Stack<int> stack;
        
        stack.push(1);
        stack.push(2);

        ASSERT_EQ(2, stack.peek());
        ASSERT_EQ(2, stack.size());
    }

    TEST(Stack, ShouldBeEmpty) {
        Stack<int> stack;
        
        ASSERT_TRUE(stack.isEmpty());
        ASSERT_EQ(0, stack.size());
    }

    TEST(Stack, ShouldNotBeEmpty) {
        Stack<int> stack;

        stack.push(1);
        
        ASSERT_FALSE(stack.isEmpty());
        ASSERT_EQ(1, stack.size());
    }

    TEST(Stack, ShouldPop1) {
        Stack<int> stack;
        
        stack.push(1);

        ASSERT_EQ(1, stack.pop());
        ASSERT_EQ(0, stack.size());
    }

    TEST(Stack, ShouldPop2) {
        Stack<int> stack;
        
        stack.push(1);
        stack.push(2);

        ASSERT_EQ(2, stack.pop());
        ASSERT_EQ(1, stack.size());
    }
}
