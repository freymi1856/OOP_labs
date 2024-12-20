#include "figure.h"
#include <iostream>
#include <vector>
#include <memory>

int main() {
    using T = double;
    std::vector<std::shared_ptr<Figure<T>>> figures;

    int n;
    std::cout << "Enter the number of figures: ";
    std::cin >> n;

    for (int i = 0; i < n; ++i) {
        std::cout << "Enter vertices for Hexagon (6 points): ";
        std::vector<Point<T>> points(6);
        for (auto& p : points) std::cin >> p;
        figures.push_back(std::make_shared<Hexagon<T>>(points));
    }

    std::cout << "Figures: \n";
    for (const auto& figure : figures) {
        std::cout << *figure << ", Center: " << *figure->getCenter()
                  << ", Area: " << figure->area() << "\n";
    }

    return 0;
}