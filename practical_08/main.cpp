#include <iostream>
#include <memory>
#include <string>
using namespace std;

class Shape {
public:
    virtual ~Shape() = default;
    virtual string type() const = 0;
};

class Circle : public Shape {
public:
    string type() const override { return "Circle"; }
};

class Rectangle : public Shape {
public:
    string type() const override { return "Rectangle"; }
};

class ShapeFactory {
public:
    static unique_ptr<Shape> createShape(const string& type) {
        if (type == "circle") return make_unique<Circle>();
        if (type == "rectangle") return make_unique<Rectangle>();
        throw invalid_argument("Unknown shape type");
    }
};

int main() {
    try {
        auto circle = ShapeFactory::createShape("circle");
        auto rectangle = ShapeFactory::createShape("rectangle");

        cout << "Created: " << circle->type() << "\n";
        cout << "Created: " << rectangle->type() << "\n";
    } catch (const exception& e) {
        cout << "Error: " << e.what() << "\n";
    }

    cout << "\nFactory pattern centralizes object creation and avoids duplicated logic.\n";
    return 0;
}
