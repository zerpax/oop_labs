#include <gtest/gtest.h>

#include "../src/allocator.h"
#include "../src/node.h"
#include "../src/iterator.h"
#include "../src/stack.h"

TEST(test_1, node) {
    EXPECT_NO_THROW(
        Node<int> node;
    );
}

TEST(test_2, node) {
    int test_value = 213;
    Node<int> node(test_value);
    ASSERT_TRUE(node.value = test_value);
}

TEST(test_1, iterator) {
    EXPECT_NO_THROW(Iterator<int> iterator);
}

TEST(test_2, iterator) {
    Node<int> test_node(123);
    Iterator<int> iterator(&test_node);
    ASSERT_TRUE(test_node.value == *iterator);
}

TEST(test_3, iterator) {
    Node<int> test_node(123);
    Iterator<int> iterator1(&test_node);
    Iterator<int> iterator2(iterator1);
    ASSERT_TRUE(*iterator1 == *iterator2);
}

TEST(test_4, iterator) {
    Node<int> test_node(123);
    Iterator<int> iterator1(&test_node);
    Iterator<int> iterator2(iterator1);
    ASSERT_TRUE(iterator1 == iterator2);
}

TEST(test_5, iterator) {
    Node<int> test_node(123);
    Iterator<int> iterator1(&test_node);
    Iterator<int> iterator2 = iterator1;
    ASSERT_TRUE(iterator1 == iterator2);
}

TEST(test_6, iterator) {
    Node<int> test_node1(123);
    Iterator<int> iterator1(&test_node1);
    Node<int> test_node2(123);
    Iterator<int> iterator2(&test_node2);
    ASSERT_TRUE(iterator1 != iterator2);
}


TEST(test_1, allocator) {
    const size_t block_size = 1000;
    EXPECT_NO_THROW(({Allocator<int, block_size> allocator;}));
}

TEST(test_2, allocator) {
    const size_t block_size = 1000;
    Allocator<int, block_size> allocator;
    EXPECT_NO_THROW(({allocator.allocate(1);}));
}

TEST(test_3, allocator) {
    const size_t block_size = 1000;
    Allocator<int, block_size> allocator;
    EXPECT_THROW(({allocator.allocate(2);}), std::bad_alloc);
}

TEST(test_4, allocator) {
    const size_t block_size = 1000;
    Allocator<int, block_size> allocator;
    int* ptr = allocator.allocate(1);
    EXPECT_NO_THROW(({allocator.deallocate(ptr, 1);}));
}

TEST(test_5, allocator) {
    const size_t block_size = 1000;
    Allocator<int, block_size> allocator;
    int* ptr = allocator.allocate(1);
    allocator.construct(ptr, 1);
    ASSERT_TRUE(*ptr = 1);
}

TEST(test_6, allocator) {
    const size_t block_size = 1000;
    Allocator<int, block_size> allocator;
    int* ptr = allocator.allocate(1);
    allocator.construct(ptr, 1);
    EXPECT_NO_THROW(({allocator.destroy(ptr);}));
}


TEST(test_1, stack) {
    EXPECT_NO_THROW(
        Stack<int> stack;
    );
}

TEST(test_2, stack) {
    Stack<int> stack;
    ASSERT_TRUE(stack.empty());
}

TEST(test_3, stack) {
    Stack<int> stack;
    EXPECT_THROW(stack.top(), std::out_of_range);
}

TEST(test_4, stack) {
    Stack<int> stack;
    stack.push(12);
    ASSERT_FALSE(stack.empty());
}

TEST(test_5, stack) {
    Stack<int> stack;
    stack.push(123);
    stack.push(123);
    stack.push(123);
    stack.push(123);
    ASSERT_TRUE(stack.size() == 4);
}

TEST(test_6, stack) {
    Stack<int> stack;
    stack.push(123);
    stack.push(123);
    stack.push(123);
    stack.pop();
    stack.pop();
    stack.pop();
    ASSERT_TRUE(stack.empty());
}

TEST(test_7, stack) {
    Stack<int> stack;
    for(int i = 0; i < 20; i++){
        stack.push(i);
    }
    for(int i = 0; i < 13; i++){
        stack.pop();
    }
    ASSERT_TRUE(stack.size() == 7);
}

TEST(test_8, stack) {
    Stack<int> stack;
    EXPECT_THROW(stack.pop(), std::out_of_range);
}

TEST(test_9, stack) {
    Stack<int> stack;
    stack.push(1);
    stack.push(2);
    Iterator<int> iterator = stack.begin();
    iterator++;
    ASSERT_TRUE(*iterator == 1);
}

TEST(test_10, stack) {
    Stack<int> stack;
    stack.push(1);
    stack.push(2);
    Iterator<int> iterator = stack.begin();
    iterator++;
    ++iterator;
    ASSERT_TRUE(iterator == stack.end());
}

TEST(test_11, stack) {
    Stack<int> stack;
    std::ostringstream output;
    std::string str_comp(("9 8 7 6 5 4 3 2 1 0 "));
    for(int i = 0; i < 10; i++){
        stack.push(i);
    }
    for(auto elem : stack){
        output << elem << ' ';
    }
    ASSERT_TRUE(output.str() == str_comp);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}