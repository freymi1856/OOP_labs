#ifndef FIGURE_H
#define FIGURE_H

#include <iostream>
#include <vector>
#include <memory>

class Figure {
public:
    virtual ~Figure() = default;

    virtual std::pair<double, double> GeometricCenter() const = 0;
    virtual double Area() const = 0;

    virtual void Print(std::ostream& os) const = 0;
    virtual void Read(std::istream& is) = 0;

    friend std::ostream& operator<<(std::ostream& os, const Figure& figure) {
        figure.Print(os);
        return os;
    }

    friend std::istream& operator>>(std::istream& is, Figure& figure) {
        figure.Read(is);
        return is;
    }

    virtual Figure* Clone() const = 0;
    virtual bool operator==(const Figure& other) const = 0;
};

class Hexagon : public Figure {
private:
    std::vector<std::pair<double, double>> vertices;

public:
    Hexagon() = default;
    Hexagon(const std::vector<std::pair<double, double>>& verts) : vertices(verts) {}

    std::pair<double, double> GeometricCenter() const override;
    double Area() const override;
    void Print(std::ostream& os) const override;
    void Read(std::istream& is) override;

    Figure* Clone() const override;
    bool operator==(const Figure& other) const override;
};

class Octagon : public Figure {
private:
    std::vector<std::pair<double, double>> vertices;

public:
    Octagon() = default;
    Octagon(const std::vector<std::pair<double, double>>& verts) : vertices(verts) {}

    std::pair<double, double> GeometricCenter() const override;
    double Area() const override;
    void Print(std::ostream& os) const override;
    void Read(std::istream& is) override;

    Figure* Clone() const override;
    bool operator==(const Figure& other) const override;
};

class Triangle : public Figure {
private:
    std::vector<std::pair<double, double>> vertices;

public:
    Triangle() = default;
    Triangle(const std::vector<std::pair<double, double>>& verts) : vertices(verts) {}

    std::pair<double, double> GeometricCenter() const override;
    double Area() const override;
    void Print(std::ostream& os) const override;
    void Read(std::istream& is) override;

    Figure* Clone() const override;
    bool operator==(const Figure& other) const override;
};

#endif