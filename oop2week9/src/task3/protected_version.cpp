#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <string>
using namespace std;

// 교재 그림 11.12: 파생 클래스가 직접 쓰도록 데이터를 protected로 선언
class CommissionEmployeeP {
public:
    CommissionEmployeeP(const string& first, const string& last,
        const string& ssn, double sales = 0.0, double rate = 0.0)
        : firstName(first), lastName(last), socialSecurityNumber(ssn) {
        setGrossSales(sales);
        setCommissionRate(rate);
    }
    void setGrossSales(double sales) {
        if (sales < 0.0) throw invalid_argument("Gross sales must be >= 0.0");
        grossSales = sales;
    }
    double getGrossSales() const { return grossSales; }
    void setCommissionRate(double rate) {
        if (rate <= 0.0 || rate >= 1.0)
            throw invalid_argument("Commission rate must be > 0.0 and < 1.0");
        commissionRate = rate;
    }
    double getCommissionRate() const { return commissionRate; }
    double earnings() const { return commissionRate * grossSales; }
    void print() const {
        cout << "commission employee: " << firstName << ' ' << lastName
             << "\nsocial security number: " << socialSecurityNumber
             << "\ngross sales: " << grossSales
             << "\ncommission rate: " << commissionRate;
    }
protected:                     // 파생 클래스에게 열어 준 데이터
    string firstName;
    string lastName;
    string socialSecurityNumber;
    double grossSales;
    double commissionRate;
};

class BasePlusCommissionEmployeeP : public CommissionEmployeeP {
public:
    BasePlusCommissionEmployeeP(const string& first, const string& last,
        const string& ssn, double sales = 0.0, double rate = 0.0,
        double salary = 0.0)
        : CommissionEmployeeP(first, last, ssn, sales, rate) {
        setBaseSalary(salary);
    }
    void setBaseSalary(double salary) {
        if (salary < 0.0) throw invalid_argument("Salary must be >= 0.0");
        baseSalary = salary;
    }
    double getBaseSalary() const { return baseSalary; }
    // 파생 클래스 코드에서 setter를 건너뛰고 직접 대입하는 함수 (검증 없음)
    void overwrite(double sales, double rate) {
        grossSales = sales;          // setGrossSales를 거치지 않는다
        commissionRate = rate;       // setCommissionRate를 거치지 않는다
    }
    double earnings() const { return baseSalary + commissionRate * grossSales; }  // 직접 접근
    void print() const {
        cout << "base-salaried commission employee: " << firstName << ' ' << lastName
             << "\nsocial security number: " << socialSecurityNumber
             << "\ngross sales: " << grossSales
             << "\ncommission rate: " << commissionRate
             << "\nbase salary: " << baseSalary;
    }
private:
    double baseSalary;
};

int main() {
    cout << fixed << setprecision(2);
    BasePlusCommissionEmployeeP e1("Bob", "Lewis", "333-33-3333", 5000, .04, 300);
    cout << "--- 1. 정상 입력 ---\n";
    e1.print();
    cout << "\nearnings: $" << e1.earnings() << "\n\n";

    cout << "--- 2. 파생 클래스가 protected 데이터를 직접 바꾼다 ---\n";
    e1.overwrite(-9000.0, 2.5);
    cout << "(검증 없이 그대로 저장됨)\n";
    e1.print();
    cout << "\nearnings: $" << e1.earnings() << "\n";
}
