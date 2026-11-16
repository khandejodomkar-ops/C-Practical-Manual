#include <iostream>
#include <memory>
#include <vector>

class Gadget {
public:
    Gadget(int id) : id(id) {
        std::cout << "Gadget " << id << " created.\n";
    }
    ~Gadget() {
        std::cout << "Gadget " << id << " destroyed.\n";
    }
    void use() const {
        std::cout << "Using Gadget " << id << ".\n";
    }
private:
    int id;
};

int main() {
    std::unique_ptr<int[]> values(new int[3]{10, 20, 30});
    std::cout << "Unique pointer values: ";
    for (int i = 0; i < 3; ++i) {
        std::cout << values[i] << " ";
    }
    std::cout << "\n";

    std::shared_ptr<Gadget> g1 = std::make_shared<Gadget>(1);
    std::shared_ptr<Gadget> g2 = g1;
    std::cout << "Shared ownership count: " << g1.use_count() << "\n";
    g1->use();
    g2->use();

    int* raw = new int(42);
    std::cout << "Raw pointer value: " << *raw << "\n";
    delete raw;

    std::cout << "RAII ensures memory is freed automatically when the smart pointer goes out of scope.\n";
    return 0;
}
