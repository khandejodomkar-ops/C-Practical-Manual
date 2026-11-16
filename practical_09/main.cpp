#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
using namespace std;

template <typename T>
class Stack {
private:
    vector<T> data;

public:
    void push(const T& value) {
        data.push_back(value);
    }

    T pop() {
        if (data.empty()) {
            throw out_of_range("Stack is empty");
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
            throw out_of_range("Stack is empty");
        }
        return data.back();
    }
};

int main() {
    Stack<int> intStack;
    intStack.push(10);
    intStack.push(20);
    cout << "Int pop: " << intStack.pop() << "\n";

    Stack<float> floatStack;
    floatStack.push(3.5f);
    floatStack.push(7.25f);
    cout << "Float top: " << floatStack.top() << "\n";

    Stack<string> stringStack;
    stringStack.push("C++");
    stringStack.push("Templates");
    cout << "String pop: " << stringStack.pop() << "\n";

    try {
        Stack<int> emptyStack;
        emptyStack.pop();
    } catch (const exception& e) {
        cout << "Empty stack error: " << e.what() << "\n";
    }

    cout << "Templates let us reuse one implementation for different data types.\n";
    return 0;
}
