#pragma once
#include <memory_resource>
#include <list>
#include <cassert>

class FixedMemoryResource : public std::pmr::memory_resource {
private:
    void *memory_block;
    size_t block_size;
    size_t allocated_size;
    std::list<void *> free_blocks;

public:
    explicit FixedMemoryResource(size_t size)
        : block_size(size), allocated_size(0), memory_block(::operator new(size)) {}

    ~FixedMemoryResource() override {
        ::operator delete(memory_block);
    }

protected:
    void *do_allocate(size_t bytes, size_t alignment) override {
        assert(bytes <= block_size && "Allocation size exceeds block size");
        if (!free_blocks.empty()) {
            void *ptr = free_blocks.front();
            free_blocks.pop_front();
            return ptr;
        }
        if (allocated_size + bytes > block_size) {
            throw std::bad_alloc();
        }
        void *ptr = static_cast<char *>(memory_block) + allocated_size;
        allocated_size += bytes;
        return ptr;
    }

    void do_deallocate(void *p, size_t bytes, size_t alignment) override {
        free_blocks.push_back(p);
    }

    bool do_is_equal(const std::pmr::memory_resource &other) const noexcept override {
        return this == &other;
    }
};