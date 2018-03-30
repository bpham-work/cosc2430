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

    TEST(Stack, EmptyStacksShouldBeEqual) {
        Stack<int> stack1;
        Stack<int> stack2;

        ASSERT_TRUE(stack1 == stack2);
    }

    TEST(Stack, StacksShouldBeEqual) {
        Stack<int> stack1;
        stack1.push(2);
        Stack<int> stack2;
        stack2.push(2);

        ASSERT_TRUE(stack1 == stack2);
    }

    TEST(Stack, StacksShouldBeEqualChars) {
        Stack<int> stack1;
        stack1.push('t');
        stack1.push('a');
        stack1.push('t');
        Stack<int> stack2;
        stack2.push('t');
        stack2.push('a');
        stack2.push('t');

        ASSERT_TRUE(stack1 == stack2);
    }

    TEST(Stack, StacksShouldNotBeEqual) {
        Stack<int> stack1;
        stack1.push(2);
        Stack<int> stack2;
        stack2.push(3);

        ASSERT_FALSE(stack1 == stack2);
    }
}
