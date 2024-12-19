#include <iostream>
#include "three.h"

int main() {
    Three number1("1201");
    Three number2("11");
    Three result = number1 + number2;

    std::cout << "Результат сложения: " << result.toString() << std::endl;
    return 0;
}