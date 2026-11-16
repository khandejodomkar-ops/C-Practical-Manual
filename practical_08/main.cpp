#include <iostream>
#include <memory>
#include <string>

class Shape {
public:
    virtual ~Shape() = default;
    virtual std::string type() const = 0;
};

class Circle : public Shape {
public:
    std::string type() const override { return "Circle"; }
};

class Rectangle : public Shape {
public:
    std::string type() const override { return "Rectangle"; }
};

class ShapeFactory {
public:
    static std::unique_ptr<Shape> createShape(const std::string& type) {
        if (type == "circle") return std::make_unique<Circle>();
        if (type == "rectangle") return std::make_unique<Rectangle>();
        throw std::invalid_argument("Unknown shape type");
    }
};

int main() {
    try {
        auto circle = ShapeFactory::createShape("circle");
        auto rectangle = ShapeFactory::createShape("rectangle");

        std::cout << "Created: " << circle->type() << "\n";
        std::cout << "Created: " << rectangle->type() << "\n";
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << "\n";
    }

    std::cout << "\nFactory pattern centralizes object creation and avoids duplicated logic.\n";
    return 0;
}
