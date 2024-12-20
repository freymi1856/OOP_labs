#include "figure.h"
#include <gtest/gtest.h>
#include <sstream>

// Тест для Hexagon
TEST(FigureTests, HexagonTest) {
    Hexagon hexagon({{0, 0}, {2, 0}, {3, 2}, {2, 4}, {0, 4}, {-1, 2}});
    
    // Проверяем геометрический центр
    auto center = hexagon.getCenter();
    EXPECT_DOUBLE_EQ(center.x, 1.0);
    EXPECT_DOUBLE_EQ(center.y, 2.0);

    // Проверяем площадь
    EXPECT_DOUBLE_EQ(static_cast<double>(hexagon), 10.0);

    // Проверяем вывод через оператор <<
    std::ostringstream oss;
    oss << hexagon;
    EXPECT_EQ(oss.str(), "(0,0) (2,0) (3,2) (2,4) (0,4) (-1,2)");
}

// Тест для Octagon
TEST(FigureTests, OctagonTest) {
    Octagon octagon({{1, 0}, {3, 0}, {4, 1}, {4, 3}, {3, 4}, {1, 4}, {0, 3}, {0, 1}});
    
    // Проверяем геометрический центр
    auto center = octagon.getCenter();
    EXPECT_DOUBLE_EQ(center.x, 2.0);
    EXPECT_DOUBLE_EQ(center.y, 2.0);

    // Проверяем площадь
    EXPECT_DOUBLE_EQ(static_cast<double>(octagon), 12.0);

    // Проверяем вывод через оператор <<
    std::ostringstream oss;
    oss << octagon;
    EXPECT_EQ(oss.str(), "(1,0) (3,0) (4,1) (4,3) (3,4) (1,4) (0,3) (0,1)");
}

// Тест для Triangle
TEST(FigureTests, TriangleTest) {
    Triangle triangle({{0, 0}, {3, 0}, {1.5, 2}});
    
    // Проверяем геометрический центр
    auto center = triangle.getCenter();
    EXPECT_DOUBLE_EQ(center.x, 1.5);
    EXPECT_DOUBLE_EQ(center.y, 0.6666666666666666);

    // Проверяем площадь
    EXPECT_DOUBLE_EQ(static_cast<double>(triangle), 3.0);

    // Проверяем вывод через оператор <<
    std::ostringstream oss;
    oss << triangle;
    EXPECT_EQ(oss.str(), "(0,0) (3,0) (1.5,2)");
}