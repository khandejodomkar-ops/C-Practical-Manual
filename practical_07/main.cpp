#include <iostream>
using namespace std;

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
        cout << real << " + " << imag << "i" << endl;
    }
};

int main() {
    cout << "Integer add: " << add(5, 7) << "\n";
    cout << "Double add: " << add(2.5, 3.75) << "\n";

    ComplexNumber c1(2.0, 3.5);
    ComplexNumber c2(1.5, 2.0);
    ComplexNumber sum = c1 + c2;

    cout << "Complex number 1: ";
    c1.display();
    cout << "Complex number 2: ";
    c2.display();
    cout << "Sum: ";
    sum.display();

    cout << "\nFunction overloading and operator overloading are both resolved at compile time.\n";
    return 0;
}
