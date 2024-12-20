#pragma once
#include <memory_resource>
#include <iterator>

template <typename T>
class Node {
public:
    T data;
    Node *next;
    Node *prev;

    explicit Node(const T &value) : data(value), next(nullptr), prev(nullptr) {}
};

template <typename T, typename Allocator = std::pmr::polymorphic_allocator<Node<T>>>
class BidirectionalList {
private:
    Node<T> *head;
    Node<T> *tail;
    Allocator allocator;

public:
    class Iterator {
    private:
        Node<T> *current;

    public:
        using iterator_category = std::forward_iterator_tag;
        using value_type = T;
        using difference_type = std::ptrdiff_t;
        using pointer = T *;
        using reference = T &;

        explicit Iterator(Node<T> *node) : current(node) {}

        reference operator*() const { return current->data; }
        pointer operator->() const { return &current->data; }

        Iterator &operator++() {
            current = current->next;
            return *this;
        }

        bool operator==(const Iterator &other) const { return current == other.current; }
        bool operator!=(const Iterator &other) const { return current != other.current; }
    };

    explicit BidirectionalList(const Allocator &alloc = Allocator())
        : head(nullptr), tail(nullptr), allocator(alloc) {}

    ~BidirectionalList() {
        while (head) {
            Node<T> *temp = head;
            head = head->next;
            allocator.deallocate(temp, 1);
        }
    }

    void push_back(const T &value) {
        Node<T> *new_node = allocator.allocate(1);
        new (new_node) Node<T>(value);

        if (!tail) {
            head = tail = new_node;
        } else {
            tail->next = new_node;
            new_node->prev = tail;
            tail = new_node;
        }
    }

    Iterator begin() const { return Iterator(head); }
    Iterator end() const { return Iterator(nullptr); }
};