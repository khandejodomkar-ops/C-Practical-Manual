#include <iostream>
#include <cstring>
using namespace std;

class IntArray {
private:
    int* data;
    int size;

public:
    IntArray() : data(nullptr), size(0) {
        cout << "Default constructor called.\n";
    }

    IntArray(int n) : size(n) {
        data = new int[size];
        for (int i = 0; i < size; ++i) {
            data[i] = i + 1;
        }
        cout << "Parameterized constructor called.\n";
    }

    IntArray(const IntArray& other) : size(other.size) {
        data = new int[size];
        memcpy(data, other.data, size * sizeof(int));
        cout << "Copy constructor called.\n";
    }

    IntArray& operator=(const IntArray& other) {
        if (this == &other) {
            return *this;
        }
        delete[] data;
        size = other.size;
        data = new int[size];
        memcpy(data, other.data, size * sizeof(int));
        cout << "Copy assignment called.\n";
        return *this;
    }

    IntArray(IntArray&& other) noexcept : data(other.data), size(other.size) {
        other.data = nullptr;
        other.size = 0;
        cout << "Move constructor called.\n";
    }

    IntArray& operator=(IntArray&& other) noexcept {
        if (this != &other) {
            delete[] data;
            data = other.data;
            size = other.size;
            other.data = nullptr;
            other.size = 0;
        }
        cout << "Move assignment called.\n";
        return *this;
    }

    ~IntArray() {
        delete[] data;
        cout << "Destructor called.\n";
    }

    void print() const {
        cout << "Array values: ";
        for (int i = 0; i < size; ++i) {
            cout << data[i] << " ";
        }
        cout << "\n";
    }
};

int main() {
    IntArray a1(3);
    a1.print();

    IntArray a2(a1);
    a2.print();

    IntArray a3;
    a3 = a1;
    a3.print();

    IntArray a4 = move(a1);
    a4.print();
    return 0;
}
