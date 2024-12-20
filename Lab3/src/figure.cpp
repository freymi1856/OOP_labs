#include "figure.h"
#include <cmath>

std::pair<double, double> Hexagon::GeometricCenter() const {
    double x = 0, y = 0;
    for (const auto& [vx, vy] : vertices) {
        x += vx;
        y += vy;
    }
    return {x / vertices.size(), y / vertices.size()};
}

double Hexagon::Area() const {
    double area = 0;
    size_t n = vertices.size();
    for (size_t i = 0; i < n; ++i) {
        auto [x1, y1] = vertices[i];
        auto [x2, y2] = vertices[(i + 1) % n];
        area += (x1 * y2 - x2 * y1);
    }
    return std::abs(area) / 2.0;
}

void Hexagon::Print(std::ostream& os) const {
    os << "Hexagon: ";
    for (const auto& [x, y] : vertices) {
        os << "(" << x << ", " << y << ") ";
    }
}

void Hexagon::Read(std::istream& is) {
    vertices.clear();
    std::cout << "Enter 6 vertices (x y): ";
    for (size_t i = 0; i < 6; ++i) {
        double x, y;
        is >> x >> y;
        vertices.emplace_back(x, y);
    }
}

Figure* Hexagon::Clone() const {
    return new Hexagon(vertices);
}

bool Hexagon::operator==(const Figure& other) const {
    const Hexagon* hex = dynamic_cast<const Hexagon*>(&other);
    return hex && vertices == hex->vertices;
}

std::pair<double, double> Triangle::GeometricCenter() const {
    double x = 0, y = 0;
    for (const auto& [vx, vy] : vertices) {
        x += vx;
        y += vy;
    }
    return {x / vertices.size(), y / vertices.size()};
}

double Triangle::Area() const {
    double area = 0;
    size_t n = vertices.size();
    for (size_t i = 0; i < n; ++i) {
        auto [x1, y1] = vertices[i];
        auto [x2, y2] = vertices[(i + 1) % n];
        area += (x1 * y2 - x2 * y1);
    }
    return std::abs(area) / 2.0;
}

void Triangle::Print(std::ostream& os) const {
    os << "Triangle: ";
    for (const auto& [x, y] : vertices) {
        os << "(" << x << ", " << y << ") ";
    }
}

void Triangle::Read(std::istream& is) {
    vertices.clear();
    std::cout << "Enter 6 vertices (x y): ";
    for (size_t i = 0; i < 6; ++i) {
        double x, y;
        is >> x >> y;
        vertices.emplace_back(x, y);
    }
}

Figure* Triangle::Clone() const {
    return new Triangle(vertices);
}

bool Triangle::operator==(const Figure& other) const {
    const Triangle* hex = dynamic_cast<const Triangle*>(&other);
    return hex && vertices == hex->vertices;
}

std::pair<double, double> Octagon::GeometricCenter() const {
    double x = 0, y = 0;
    for (const auto& [vx, vy] : vertices) {
        x += vx;
        y += vy;
    }
    return {x / vertices.size(), y / vertices.size()};
}

double Octagon::Area() const {
    double area = 0;
    size_t n = vertices.size();
    for (size_t i = 0; i < n; ++i) {
        auto [x1, y1] = vertices[i];
        auto [x2, y2] = vertices[(i + 1) % n];
        area += (x1 * y2 - x2 * y1);
    }
    return std::abs(area) / 2.0;
}

void Octagon::Print(std::ostream& os) const {
    os << "Octagon: ";
    for (const auto& [x, y] : vertices) {
        os << "(" << x << ", " << y << ") ";
    }
}

void Octagon::Read(std::istream& is) {
    vertices.clear();
    std::cout << "Enter 6 vertices (x y): ";
    for (size_t i = 0; i < 6; ++i) {
        double x, y;
        is >> x >> y;
        vertices.emplace_back(x, y);
    }
}

Figure* Octagon::Clone() const {
    return new Octagon(vertices);
}

bool Octagon::operator==(const Figure& other) const {
    const Octagon* hex = dynamic_cast<const Octagon*>(&other);
    return hex && vertices == hex->vertices;
}