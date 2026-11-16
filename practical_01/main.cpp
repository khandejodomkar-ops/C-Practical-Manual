#include <iostream>
#include <string>
using namespace std;

int main() {
    string name;
    int hours;
    double rate;
    const double TAX_RATE = 0.10;

    cout << "Enter your name: ";
    getline(cin, name);
    cout << "Enter hours worked: ";
    cin >> hours;
    cout << "Enter hourly rate: ";
    cin >> rate;

    double grossPay = hours * rate;
    double tax = grossPay * TAX_RATE;
    double netPay = grossPay - tax;

    cout << "\nEmployee: " << name << endl;
    cout << "Gross pay: " << grossPay << endl;
    cout << "Tax: " << tax << endl;
    cout << "Net pay: " << netPay << endl;

    bool isEligible = (netPay > 5000);
    cout << "Eligible for bonus? " << (isEligible ? "Yes" : "No") << endl;

    cout << "\nArithmetic check: " << (10 + 5) << " " << (10 > 5) << " " << ((10 > 5) && (8 < 12)) << endl;
    return 0;
}
