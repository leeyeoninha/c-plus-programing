#include <iostream>
#include <stdexcept>
#include "BasePlusCommissionEmployee.h"
using namespace std;

BasePlusCommissionEmployee::BasePlusCommissionEmployee(
    const string& first, const string& last, const string& ssn,
    double sales, double rate, double salary)
    : CommissionEmployee(first, last, ssn, sales, rate) {  // 기반 클래스 생성자 호출
    setBaseSalary(salary);
}

void BasePlusCommissionEmployee::setBaseSalary(double salary) {
    if (salary < 0.0)
        throw invalid_argument("Salary must be >= 0.0");
    baseSalary = salary;
}
double BasePlusCommissionEmployee::getBaseSalary() const { return baseSalary; }

double BasePlusCommissionEmployee::earnings() const {
    return getBaseSalary() + CommissionEmployee::earnings();
}

void BasePlusCommissionEmployee::print() const {
    cout << "base-salaried ";
    CommissionEmployee::print();          // 기반 클래스의 출력을 재사용
    cout << "\nbase salary: " << getBaseSalary();
}
