#include "figure.h"
#include <gtest/gtest.h>
#include <memory>

TEST(HexagonTest, AreaTest) {
    std::vector<Point<double>> points = {
        {0, 0}, {2, 0}, {3, 1.732}, {2, 3.464}, {0, 3.464}, {-1, 1.732}};
    Hexagon<double> hex(points);

    EXPECT_NEAR(hex.area(), 10.392, 0.001);
}

TEST(HexagonTest, CenterTest) {
    std::vector<Point<double>> points = {
        {0, 0}, {2, 0}, {3, 1.732}, {2, 3.464}, {0, 3.464}, {-1, 1.732}};
    Hexagon<double> hex(points);

    auto center = hex.getCenter();
    EXPECT_NEAR(center->x, 1.0, 0.001);
    EXPECT_NEAR(center->y, 1.732, 0.001);
}

TEST(OctagonTest, AreaTest) {
    std::vector<Point<double>> points = {
        {0, 0}, {2, 0}, {3, 1}, {3, 3}, {2, 4}, {0, 4}, {-1, 3}, {-1, 1}};
    Octagon<double> oct(points);

    EXPECT_NEAR(oct.area(), 12.0, 0.001);
}

TEST(OctagonTest, CenterTest) {
    std::vector<Point<double>> points = {
        {0, 0}, {2, 0}, {3, 1}, {3, 3}, {2, 4}, {0, 4}, {-1, 3}, {-1, 1}};
    Octagon<double> oct(points);

    auto center = oct.getCenter();
    EXPECT_NEAR(center->x, 0.75, 0.001);
    EXPECT_NEAR(center->y, 2.0, 0.001);
}

TEST(TriangleTest, AreaTest) {
    std::vector<Point<double>> points = {
        {0, 0}, {4, 0}, {2, 3}};
    Triangle<double> tri(points);

    EXPECT_NEAR(tri.area(), 6.0, 0.001);
}

TEST(TriangleTest, CenterTest) {
    std::vector<Point<double>> points = {
        {0, 0}, {4, 0}, {2, 3}};
    Triangle<double> tri(points);

    auto center = tri.getCenter();
    EXPECT_NEAR(center->x, 2.0, 0.001);
    EXPECT_NEAR(center->y, 1.0, 0.001);
}