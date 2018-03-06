#include "gtest/gtest.h"
#include "queue/queue.h"

namespace {
    TEST(Queue, ShouldEnqueueValue) {
        Queue<int> queue;
        
        queue.enqueue(1);

        ASSERT_EQ(1, queue.peek());
        ASSERT_EQ(1, queue.size());
    }

    TEST(Queue, ShouldEnqueueTwoValues) {
        Queue<int> queue;
        
        queue.enqueue(1);
        queue.enqueue(2);

        ASSERT_EQ(1, queue.peek());
        ASSERT_EQ(2, queue.size());
    }

    TEST(Queue, ShouldBeEmpty) {
        Queue<int> queue;
        
        ASSERT_TRUE(queue.isEmpty());
        ASSERT_EQ(0, queue.size());
    }

    TEST(Queue, ShouldNotBeEmpty) {
        Queue<int> queue;

        queue.enqueue(1);
        
        ASSERT_FALSE(queue.isEmpty());
        ASSERT_EQ(1, queue.size());
    }

    TEST(Queue, ShouldDequeue1) {
        Queue<int> queue;
        
        queue.enqueue(1);

        ASSERT_EQ(1, queue.dequeue());
        ASSERT_EQ(0, queue.size());
    }

    TEST(Queue, ShouldDequeue2) {
        Queue<int> queue;
        
        queue.enqueue(1);
        queue.enqueue(2);
        queue.dequeue();

        ASSERT_EQ(2, queue.dequeue());
        ASSERT_EQ(0, queue.size());
    }
}
