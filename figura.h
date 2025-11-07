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
    [[nodiscard]] virtual Figura* clone() const = 0;
};

class Elipse: public Figura {
    double a{};
    double b{};
public:
    Elipse(const double a, const double b): a(a), b{b} {}
    [[nodiscard]] double area() const override {
        return a * b * std::numbers::pi;
    }
    [[nodiscard]] Figura* clone() const override{
        return new Elipse(a, b);
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
    [[nodiscard]] Figura* clone() const override{
        return new Rectangulo(width, height);
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
    [[nodiscard]] Figura* clone() const override{
        return new Triangulo(width, height);
    }
};

#endif //FIGURA_H
