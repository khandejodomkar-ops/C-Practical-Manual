#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

template <typename T>
class Stack {
private:
    std::vector<T> data;

public:
    void push(const T& value) {
        data.push_back(value);
    }

    T pop() {
        if (data.empty()) {
            throw std::out_of_range("Stack is empty");
        }
        T value = data.back();
        data.pop_back();
        return value;
    }

    bool empty() const {
        return data.empty();
    }

    T top() const {
        if (data.empty()) {
            throw std::out_of_range("Stack is empty");
        }
        return data.back();
    }
};

int main() {
    Stack<int> intStack;
    intStack.push(10);
    intStack.push(20);
    std::cout << "Int pop: " << intStack.pop() << "\n";

    Stack<float> floatStack;
    floatStack.push(3.5f);
    floatStack.push(7.25f);
    std::cout << "Float top: " << floatStack.top() << "\n";

    Stack<std::string> stringStack;
    stringStack.push("C++");
    stringStack.push("Templates");
    std::cout << "String pop: " << stringStack.pop() << "\n";

    try {
        Stack<int> emptyStack;
        emptyStack.pop();
    } catch (const std::exception& e) {
        std::cout << "Empty stack error: " << e.what() << "\n";
    }

    std::cout << "Templates let us reuse one implementation for different data types.\n";
    return 0;
}
