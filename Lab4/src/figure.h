#ifndef FIGURE_H
#define FIGURE_H

#include <iostream>
#include <memory>
#include <vector>
#include <cmath>
#include <concepts>

// Концепт для проверки скалярных типов
template <typename T>
concept Scalar = std::is_arithmetic_v<T>;

// Шаблон точки
template <Scalar T>
struct Point {
    T x, y;

    Point() : x(0), y(0) {}
    Point(T x, T y) : x(x), y(y) {}

    friend std::ostream& operator<<(std::ostream& os, const Point& point) {
        return os << "(" << point.x << ", " << point.y << ")";
    }

    friend std::istream& operator>>(std::istream& is, Point& point) {
        return is >> point.x >> point.y;
    }
};

// Базовый класс Figure
template <Scalar T>
class Figure {
public:
    virtual ~Figure() = default;

    virtual std::unique_ptr<Point<T>> getCenter() const = 0;
    virtual double area() const = 0;

    friend std::ostream& operator<<(std::ostream& os, const Figure& figure) {
        figure.print(os);
        return os;
    }

    virtual void print(std::ostream& os) const = 0;
    virtual bool operator==(const Figure& other) const = 0;
};

#endif