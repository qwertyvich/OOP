#include <gtest/gtest.h>
#include "../include/List.hpp"              
#include "../include/CustomMemoryResource.hpp" 

TEST(LinkedListTest, PushFrontAndSize) {
    CustomMemoryResource custom_resource; 
    std::pmr::polymorphic_allocator<Node<int>> allocator(&custom_resource);
    LinkedList<int> list(allocator);
    EXPECT_TRUE(list.empty());
    EXPECT_EQ(list.size(), 0);
    list.push_front(10);
    list.push_front(20);
    list.push_front(30);
    EXPECT_FALSE(list.empty());
    EXPECT_EQ(list.size(), 3);
    EXPECT_EQ(list.front(), 30);  
}

TEST(LinkedListTest, PushBackAndPopFront) {
    CustomMemoryResource custom_resource;
    std::pmr::polymorphic_allocator<Node<int>> allocator(&custom_resource);
    LinkedList<int> list(allocator);
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);

    EXPECT_EQ(list.size(), 3);
    EXPECT_EQ(list.front(), 1);
    list.pop_front();
    EXPECT_EQ(list.size(), 2);
    EXPECT_EQ(list.front(), 2); 
}

TEST(LinkedListTest, PopBackAndSize) {
    CustomMemoryResource custom_resource;
    std::pmr::polymorphic_allocator<Node<int>> allocator(&custom_resource);
    LinkedList<int> list(allocator);

    list.push_back(10);
    list.push_back(20);
    list.push_back(30);

    EXPECT_EQ(list.size(), 3);
    list.pop_back();
    EXPECT_EQ(list.size(), 2);
    EXPECT_EQ(list.front(), 10);  
}

TEST(LinkedListTest, ClearList) {
    CustomMemoryResource custom_resource;
    std::pmr::polymorphic_allocator<Node<int>> allocator(&custom_resource);
    LinkedList<int> list(allocator);

    list.push_back(10);
    list.push_back(20);
    list.push_back(30);

    EXPECT_EQ(list.size(), 3);
    list.clear();
    EXPECT_TRUE(list.empty());
    EXPECT_EQ(list.size(), 0);
}

TEST(LinkedListTest, IteratorTest) {
    CustomMemoryResource custom_resource;
    std::pmr::polymorphic_allocator<Node<int>> allocator(&custom_resource);
    LinkedList<int> list(allocator);

    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    int expected_values[] = { 1, 2, 3 };
    int index = 0;

    for (auto it = list.begin(); it != list.end(); ++it) {
        EXPECT_EQ(*it, expected_values[index]);
        ++index;
    }
}

TEST(LinkedListTest, EqualityOperator) {
    CustomMemoryResource custom_resource;
    std::pmr::polymorphic_allocator<Node<int>> allocator(&custom_resource);
    LinkedList<int> list1(allocator);
    LinkedList<int> list2(allocator);

    list1.push_back(1);
    list1.push_back(2);
    list1.push_back(3);

    list2.push_back(1);
    list2.push_back(2);
    list2.push_back(3);
    EXPECT_TRUE(list1 == list2);

    list2.pop_back();
    EXPECT_FALSE(list1 == list2);
}

TEST(LinkedListTest, MemoryAllocationTest) {
    CustomMemoryResource custom_resource;
    std::pmr::polymorphic_allocator<Node<int>> allocator(&custom_resource);
    LinkedList<int> list(allocator);
    EXPECT_EQ(list.size(), 0);
    list.push_back(100);
    EXPECT_EQ(list.size(), 1); 

    list.push_back(200);
    EXPECT_EQ(list.size(), 2);  

    list.push_back(300);
    EXPECT_EQ(list.size(), 3); 
    EXPECT_EQ(list.front(), 100);
}

TEST(LinkedListTest, PopFrontWhenEmpty) {
    CustomMemoryResource custom_resource;
    std::pmr::polymorphic_allocator<Node<int>> allocator(&custom_resource);
    LinkedList<int> list(allocator);
    EXPECT_THROW(list.pop_front(), std::runtime_error);
}

TEST(LinkedListTest, FrontWhenEmpty) {
    CustomMemoryResource custom_resource;
    std::pmr::polymorphic_allocator<Node<int>> allocator(&custom_resource);
    LinkedList<int> list(allocator);
    EXPECT_THROW(list.front(), std::runtime_error);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
