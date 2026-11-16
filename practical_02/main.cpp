#include <iostream>
#include <string>
using namespace std;

class BankAccount {
private:
    string accountNumber;
    double balance;

public:
    BankAccount(string accNo, double initialBalance) : accountNumber(accNo), balance(initialBalance) {
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
            cout << "Withdrawal amount must be positive.\n";
            return;
        }
        if (amount > balance) {
            cout << "Insufficient balance.\n";
            return;
        }
        balance -= amount;
    }

    void display() const {
        cout << "Account: " << accountNumber << "\n";
        cout << "Balance: Rs. " << balance << "\n";
    }
};

int main() {
    BankAccount account1("ACC101", 1500.0);
    BankAccount account2("ACC102", 2200.0);

    account1.deposit(300.0);
    account1.withdraw(200.0);
    account2.withdraw(2500.0);

    cout << "Account 1 details:\n";
    account1.display();
    cout << "\nAccount 2 details:\n";
    account2.display();

    cout << "\nPrivate members are hidden from outside code and protected by encapsulation.\n";
    cout << "Public members can be accessed directly and provide safe operations like deposit and withdraw.\n";
    return 0;
}
