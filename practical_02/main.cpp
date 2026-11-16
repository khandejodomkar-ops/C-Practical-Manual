#include <iostream>
#include <string>

class BankAccount {
private:
    std::string accountNumber;
    double balance;

public:
    BankAccount(std::string accNo, double initialBalance) : accountNumber(accNo), balance(initialBalance) {
        if (initialBalance < 0) {
            balance = 0;
        }
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
        }
    }

    void withdraw(double amount) {
        if (amount <= 0) {
            std::cout << "Withdrawal amount must be positive.\n";
            return;
        }
        if (amount > balance) {
            std::cout << "Insufficient balance.\n";
            return;
        }
        balance -= amount;
    }

    void display() const {
        std::cout << "Account: " << accountNumber << "\n";
        std::cout << "Balance: Rs. " << balance << "\n";
    }
};

int main() {
    BankAccount account1("ACC101", 1500.0);
    BankAccount account2("ACC102", 2200.0);

    account1.deposit(300.0);
    account1.withdraw(200.0);
    account2.withdraw(2500.0);

    std::cout << "Account 1 details:\n";
    account1.display();
    std::cout << "\nAccount 2 details:\n";
    account2.display();

    std::cout << "\nPrivate members are hidden from outside code and protected by encapsulation.\n";
    std::cout << "Public members can be accessed directly and provide safe operations like deposit and withdraw.\n";
    return 0;
}
