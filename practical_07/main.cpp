#include <iostream>

int add(int a, int b) {
    return a + b;
}

double add(double a, double b) {
    return a + b;
}

class ComplexNumber {
private:
    double real;
    double imag;

public:
    ComplexNumber(double r = 0.0, double i = 0.0) : real(r), imag(i) {}

    ComplexNumber operator+(const ComplexNumber& other) const {
        return ComplexNumber(real + other.real, imag + other.imag);
    }

    void display() const {
        std::cout << real << " + " << imag << "i" << std::endl;
    }
};

int main() {
    std::cout << "Integer add: " << add(5, 7) << "\n";
    std::cout << "Double add: " << add(2.5, 3.75) << "\n";

    ComplexNumber c1(2.0, 3.5);
    ComplexNumber c2(1.5, 2.0);
    ComplexNumber sum = c1 + c2;

    std::cout << "Complex number 1: ";
    c1.display();
    std::cout << "Complex number 2: ";
    c2.display();
    std::cout << "Sum: ";
    sum.display();

    std::cout << "\nFunction overloading and operator overloading are both resolved at compile time.\n";
    return 0;
}
