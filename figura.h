//
// Created by rrivas on 6/11/2025.
//

#ifndef FIGURA_H
#define FIGURA_H

#include <numbers>

struct Figura {
    virtual ~Figura() = default; // OJO, en herencia,
    // - debe existir siempre
    // - debe ser virtual

    [[nodiscard]] virtual double area() const = 0;
};

class Elipse: public Figura {
    double a{};
    double b{};
public:
    Elipse(const double a, const double b): a(a), b{b} {}
    [[nodiscard]] double area() const override {
        return a * b * std::numbers::pi;
    }
};

class Rectangulo: public Figura {
    double width{};
    double height{};
public:
    Rectangulo(const double width, const double height)
        : width{width}, height{height} {}
    [[nodiscard]] double area() const override {
        return width * height;
    }
};

class Triangulo: public Figura {
    double width{};
    double height{};
public:
    Triangulo(const double width, const double height)
        : width{width}, height{height} {}
    [[nodiscard]] double area() const override {
        return width * height / 2;
    }
};

#endif //FIGURA_H
