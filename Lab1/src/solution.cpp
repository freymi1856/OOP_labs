#include <iostream>
#include "number_to_turkish.h"

int main() {
    int number;
    std::cout << "Enter a number (0-99): ";
    std::cin >> number;

    try {
        std::cout << "In Turkish: " << NumberToTurkish(number) << std::endl;
    } catch (const std::out_of_range& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return 0;
}