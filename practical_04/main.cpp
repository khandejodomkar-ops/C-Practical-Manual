#include <iostream>
#include <memory>
#include <vector>
using namespace std;

class Gadget {
public:
    Gadget(int id) : id(id) {
        cout << "Gadget " << id << " created.\n";
    }
    ~Gadget() {
        cout << "Gadget " << id << " destroyed.\n";
    }
    void use() const {
        cout << "Using Gadget " << id << ".\n";
    }
private:
    int id;
};

int main() {
    unique_ptr<int[]> values(new int[3]{10, 20, 30});
    cout << "Unique pointer values: ";
    for (int i = 0; i < 3; ++i) {
        cout << values[i] << " ";
    }
    cout << "\n";

    shared_ptr<Gadget> g1 = make_shared<Gadget>(1);
    shared_ptr<Gadget> g2 = g1;
    cout << "Shared ownership count: " << g1.use_count() << "\n";
    g1->use();
    g2->use();

    int* raw = new int(42);
    cout << "Raw pointer value: " << *raw << "\n";
    delete raw;

    cout << "RAII ensures memory is freed automatically when the smart pointer goes out of scope.\n";
    return 0;
}
