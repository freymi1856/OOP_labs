#include "figure.h"

// Hexagon
Hexagon::Hexagon(const std::vector<Point>& vertices) : vertices(vertices) {
    if (vertices.size() != 6) {
        throw std::invalid_argument("Hexagon must have 6 vertices");
    }
}

Point Hexagon::getCenter() const {
    double x_sum = 0.0, y_sum = 0.0;
    for (const auto& vertex : vertices) {
        x_sum += vertex.x;
        y_sum += vertex.y;
    }
    return {x_sum / vertices.size(), y_sum / vertices.size()};
}

Hexagon::operator double() const {
    double area = 0.0;
    for (size_t i = 0; i < vertices.size(); ++i) {
        const auto& p1 = vertices[i];
        const auto& p2 = vertices[(i + 1) % vertices.size()];
        area += (p1.x * p2.y - p2.x * p1.y);
    }
    return std::abs(area) / 2.0;
}

// Octagon
Octagon::Octagon(const std::vector<Point>& vertices) : vertices(vertices) {
    if (vertices.size() != 8) {
        throw std::invalid_argument("Octagon must have 8 vertices");
    }
}

Point Octagon::getCenter() const {
    double x_sum = 0.0, y_sum = 0.0;
    for (const auto& vertex : vertices) {
        x_sum += vertex.x;
        y_sum += vertex.y;
    }
    return {x_sum / vertices.size(), y_sum / vertices.size()};
}

Octagon::operator double() const {
    double area = 0.0;
    for (size_t i = 0; i < vertices.size(); ++i) {
        const auto& p1 = vertices[i];
        const auto& p2 = vertices[(i + 1) % vertices.size()];
        area += (p1.x * p2.y - p2.x * p1.y);
    }
    return std::abs(area) / 2.0;
}

// Triangle
Triangle::Triangle(const std::vector<Point>& vertices) : vertices(vertices) {
    if (vertices.size() != 3) {
        throw std::invalid_argument("Triangle must have 3 vertices");
    }
}

Point Triangle::getCenter() const {
    double x_sum = 0.0, y_sum = 0.0;
    for (const auto& vertex : vertices) {
        x_sum += vertex.x;
        y_sum += vertex.y;
    }
    return {x_sum / vertices.size(), y_sum / vertices.size()};
}

Triangle::operator double() const {
    double area = 0.0;
    for (size_t i = 0; i < vertices.size(); ++i) {
        const auto& p1 = vertices[i];
        const auto& p2 = vertices[(i + 1) % vertices.size()];
        area += (p1.x * p2.y - p2.x * p1.y);
    }
    return std::abs(area) / 2.0;
}