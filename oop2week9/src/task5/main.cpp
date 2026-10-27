#include <iostream>
#include <iomanip>
#include <stdexcept>
#include "SeniorBasePlusCommissionEmployee.h"
using namespace std;

int main() {
    cout << fixed << setprecision(2);
    try {
        SeniorBasePlusCommissionEmployee s1(
            "Dana", "Park", "555-55-5555", 12000, .06, 900, 250, 7);

        cout << "--- 1. 3단계 상속 계층의 객체 ---\n";
        s1.print();
        cout << "\nearnings: $" << s1.earnings() << "\n\n";

        cout << "--- 2. 간접 기반 클래스의 public 함수도 그대로 상속된다 ---\n";
        cout << "getFirstName()   : " << s1.getFirstName() << "\n";
        cout << "getGrossSales()  : " << s1.getGrossSales() << "\n";
        cout << "getBaseSalary()  : " << s1.getBaseSalary() << "\n\n";

        cout << "--- 3. 기반 클래스 참조로 묶으면 기반 클래스 함수가 불린다 ---\n";
        CommissionEmployee& ref = s1;      // is-a: 파생 객체는 기반 참조에 담긴다
        cout << "ref.earnings(): $" << ref.earnings()
             << "   (성과급·기본급 제외, 기반 클래스 버전)\n\n";

        cout << "--- 4. 잘못된 값 ---\n";
        try { s1.setIncentive(-50); }
        catch (const invalid_argument& e) { cout << "예외: " << e.what() << "\n"; }
        try { s1.setYearsOfService(-1); }
        catch (const invalid_argument& e) { cout << "예외: " << e.what() << "\n"; }
        cout << "값은 그대로: incentive=" << s1.getIncentive()
             << ", years=" << s1.getYearsOfService() << "\n";
    }
    catch (const exception& e) {
        cout << "예외: " << e.what() << "\n";
    }
}
