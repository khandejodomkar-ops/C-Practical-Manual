#include <iostream>
#include <stdexcept>
#include <string>

class InvalidAmount : public std::invalid_argument {
public:
    InvalidAmount(const std::string& message) : std::invalid_argument(message) {}
};

class InsufficientFunds : public std::runtime_error {
public:
    InsufficientFunds(const std::string& message) : std::runtime_error(message) {}
};

class BankAccount {
private:
    double balance;

public:
    BankAccount(double initialBalance) : balance(initialBalance) {}

    double getBalance() const { return balance; }

    void withdraw(double amount) {
        if (amount <= 0) {
            throw InvalidAmount("Amount must be positive.");
        }
        if (amount > balance) {
            throw InsufficientFunds("Not enough balance for this withdrawal.");
        }
        balance -= amount;
    }
};

int main() {
    BankAccount account(5000.0);

    try {
        account.withdraw(1200.0);
        std::cout << "Withdrawal successful. Balance: " << account.getBalance() << "\n";
    } catch (const InvalidAmount& e) {
        std::cout << "Invalid amount: " << e.what() << "\n";
    } catch (const InsufficientFunds& e) {
        std::cout << "Insufficient funds: " << e.what() << "\n";
    }

    try {
        account.withdraw(-50.0);
    } catch (const InvalidAmount& e) {
        std::cout << "Invalid amount: " << e.what() << "\n";
    } catch (const InsufficientFunds& e) {
        std::cout << "Insufficient funds: " << e.what() << "\n";
    }

    try {
        account.withdraw(20000.0);
    } catch (const InvalidAmount& e) {
        std::cout << "Invalid amount: " << e.what() << "\n";
    } catch (const InsufficientFunds& e) {
        std::cout << "Insufficient funds: " << e.what() << "\n";
    }

    std::cout << "Final balance: " << account.getBalance() << "\n";
    return 0;
}
