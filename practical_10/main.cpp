#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

class InvalidAmount : public invalid_argument {
public:
    InvalidAmount(const string& message) : invalid_argument(message) {}
};

class InsufficientFunds : public runtime_error {
public:
    InsufficientFunds(const string& message) : runtime_error(message) {}
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
        cout << "Withdrawal successful. Balance: " << account.getBalance() << "\n";
    } catch (const InvalidAmount& e) {
        cout << "Invalid amount: " << e.what() << "\n";
    } catch (const InsufficientFunds& e) {
        cout << "Insufficient funds: " << e.what() << "\n";
    }

    try {
        account.withdraw(-50.0);
    } catch (const InvalidAmount& e) {
        cout << "Invalid amount: " << e.what() << "\n";
    } catch (const InsufficientFunds& e) {
        cout << "Insufficient funds: " << e.what() << "\n";
    }

    try {
        account.withdraw(20000.0);
    } catch (const InvalidAmount& e) {
        cout << "Invalid amount: " << e.what() << "\n";
    } catch (const InsufficientFunds& e) {
        cout << "Insufficient funds: " << e.what() << "\n";
    }

    cout << "Final balance: " << account.getBalance() << "\n";
    return 0;
}
