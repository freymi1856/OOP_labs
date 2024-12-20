#include "figure.h"
#include <iostream>
#include <memory>
#include <cmath>

// Реализация для фигур: Hexagon, Octagon, Triangle

template <Scalar T>
class Hexagon : public Figure<T> {
private:
    std::vector<std::unique_ptr<Point<T>>> vertices;

public:
    Hexagon(const std::vector<Point<T>>& points) {
        if (points.size() != 6) throw std::invalid_argument("Hexagon requires 6 vertices.");
        for (const auto& p : points) {
            vertices.push_back(std::make_unique<Point<T>>(p));
        }
    }

    std::unique_ptr<Point<T>> getCenter() const override {
        T cx = 0, cy = 0;
        for (const auto& v : vertices) {
            cx += v->x;
            cy += v->y;
        }
        return std::make_unique<Point<T>>(cx / 6, cy / 6);
    }

    double area() const override {
        double result = 0;
        for (size_t i = 0; i < 6; ++i) {
            const auto& p1 = *vertices[i];
            const auto& p2 = *vertices[(i + 1) % 6];
            result += p1.x * p2.y - p2.x * p1.y;
        }
        return std::abs(result) / 2;
    }

    void print(std::ostream& os) const override {
        os << "Hexagon: ";
        for (const auto& v : vertices) {
            os << *v << " ";
        }
    }

    bool operator==(const Figure<T>& other) const override {
        const auto* o = dynamic_cast<const Hexagon*>(&other);
        if (!o) return false;
        for (size_t i = 0; i < 6; ++i) {
            if (*vertices[i] != *o->vertices[i]) return false;
        }
        return true;
    }
};

class Octagon : public Figure<T> {
private:
    std::vector<std::unique_ptr<Point<T>>> vertices;

public:
    Octagon(const std::vector<Point<T>>& points) {
        if (points.size() != 6) throw std::invalid_argument("Octagon requires 6 vertices.");
        for (const auto& p : points) {
            vertices.push_back(std::make_unique<Point<T>>(p));
        }
    }

    std::unique_ptr<Point<T>> getCenter() const override {
        T cx = 0, cy = 0;
        for (const auto& v : vertices) {
            cx += v->x;
            cy += v->y;
        }
        return std::make_unique<Point<T>>(cx / 6, cy / 6);
    }

    double area() const override {
        double result = 0;
        for (size_t i = 0; i < 6; ++i) {
            const auto& p1 = *vertices[i];
            const auto& p2 = *vertices[(i + 1) % 6];
            result += p1.x * p2.y - p2.x * p1.y;
        }
        return std::abs(result) / 2;
    }

    void print(std::ostream& os) const override {
        os << "Octagon: ";
        for (const auto& v : vertices) {
            os << *v << " ";
        }
    }

    bool operator==(const Figure<T>& other) const override {
        const auto* o = dynamic_cast<const Octagon*>(&other);
        if (!o) return false;
        for (size_t i = 0; i < 6; ++i) {
            if (*vertices[i] != *o->vertices[i]) return false;
        }
        return true;
    }
};

class Triangle : public Figure<T> {
private:
    std::vector<std::unique_ptr<Point<T>>> vertices;

public:
    Triangle(const std::vector<Point<T>>& points) {
        if (points.size() != 6) throw std::invalid_argument("Triangle requires 6 vertices.");
        for (const auto& p : points) {
            vertices.push_back(std::make_unique<Point<T>>(p));
        }
    }

    std::unique_ptr<Point<T>> getCenter() const override {
        T cx = 0, cy = 0;
        for (const auto& v : vertices) {
            cx += v->x;
            cy += v->y;
        }
        return std::make_unique<Point<T>>(cx / 6, cy / 6);
    }

    double area() const override {
        double result = 0;
        for (size_t i = 0; i < 6; ++i) {
            const auto& p1 = *vertices[i];
            const auto& p2 = *vertices[(i + 1) % 6];
            result += p1.x * p2.y - p2.x * p1.y;
        }
        return std::abs(result) / 2;
    }

    void print(std::ostream& os) const override {
        os << "Triangle: ";
        for (const auto& v : vertices) {
            os << *v << " ";
        }
    }

    bool operator==(const Figure<T>& other) const override {
        const auto* o = dynamic_cast<const Triangle*>(&other);
        if (!o) return false;
        for (size_t i = 0; i < 6; ++i) {
            if (*vertices[i] != *o->vertices[i]) return false;
        }
        return true;
    }
};