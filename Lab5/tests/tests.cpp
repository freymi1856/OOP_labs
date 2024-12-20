#include "memory_resource.h"
#include "bidirectional_list.h"
#include <gtest/gtest.h>

TEST(FixedMemoryResourceTest, AllocateDeallocate) {
    FixedMemoryResource resource(1024);
    void *ptr1 = resource.allocate(128);
    void *ptr2 = resource.allocate(128);
    resource.deallocate(ptr1, 128);
    void *ptr3 = resource.allocate(128);

    EXPECT_EQ(ptr1, ptr3);
}

TEST(BidirectionalListTest, AddElements) {
    FixedMemoryResource resource(1024);
    std::pmr::polymorphic_allocator<int> alloc(&resource);
    BidirectionalList<int, decltype(alloc)> list(alloc);

    list.push_back(1);
    list.push_back(2);
    list.push_back(3);

    auto it = list.begin();
    EXPECT_EQ(*it++, 1);
    EXPECT_EQ(*it++, 2);
    EXPECT_EQ(*it, 3);
}