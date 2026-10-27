#include <iostream>
#include <iomanip>
#include <stdexcept>
#include "BasePlusCommissionEmployee.h"
using namespace std;

int main() {
    cout << fixed << setprecision(2);
    try {
        BasePlusCommissionEmployee e1("Bob", "Lewis", "333-33-3333", 5000, .04, 300);
        cout << "--- 1. 객체 생성 ---\n";
        e1.print();
        cout << "\nearnings: $" << e1.earnings() << "\n\n";

        cout << "--- 2. setter로 값 변경 ---\n";
        BasePlusCommissionEmployee e2("Lisa", "Jones", "444-44-4444", 8000, .05, 1200);
        e2.print();
        cout << "\nearnings: $" << e2.earnings() << "\n\n";

        cout << "--- 3. 잘못된 값 ---\n";
        try { e2.setBaseSalary(-100); }
        catch (const invalid_argument& e) { cout << "예외: " << e.what() << "\n"; }
    }
    catch (const exception& e) {
        cout << "예외: " << e.what() << "\n";
    }
}
