#include <iostream>
#include <string>

int main() {
    std::string name;
    int hours;
    double rate;
    const double TAX_RATE = 0.10;

    std::cout << "Enter your name: ";
    std::getline(std::cin, name);
    std::cout << "Enter hours worked: ";
    std::cin >> hours;
    std::cout << "Enter hourly rate: ";
    std::cin >> rate;

    double grossPay = hours * rate;
    double tax = grossPay * TAX_RATE;
    double netPay = grossPay - tax;

    std::cout << "\nEmployee: " << name << std::endl;
    std::cout << "Gross pay: " << grossPay << std::endl;
    std::cout << "Tax: " << tax << std::endl;
    std::cout << "Net pay: " << netPay << std::endl;

    bool isEligible = (netPay > 5000);
    std::cout << "Eligible for bonus? " << (isEligible ? "Yes" : "No") << std::endl;

    std::cout << "\nArithmetic check: " << (10 + 5) << " " << (10 > 5) << " " << ((10 > 5) && (8 < 12)) << std::endl;
    return 0;
}
