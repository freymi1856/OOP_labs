#include "src/memory_resource.h"
#include "src/bidirectional_list.h"
#include <iostream>
#include <string>

struct ComplexType {
    int id;
    std::string name;
    double value;

    friend std::ostream &operator<<(std::ostream &os, const ComplexType &ct) {
        os << "ComplexType{id: " << ct.id << ", name: " << ct.name << ", value: " << ct.value << "}";
        return os;
    }
};

int main() {
    FixedMemoryResource resource(1024);
    std::pmr::polymorphic_allocator<ComplexType> alloc(&resource);
    BidirectionalList<ComplexType, decltype(alloc)> list(alloc);

    list.push_back({1, "Object1", 3.14});
    list.push_back({2, "Object2", 2.71});

    for (const auto &item : list) {
        std::cout << item << std::endl;
    }

    return 0;
}