#include <iostream>
#include <stdexcept>
#include "BasePlusSalariedEmployee.h"
using namespace std;

BasePlusSalariedEmployee::BasePlusSalariedEmployee(
    const string& first, const string& last, const string& ssn,
    double sales, double rate, double salary)
    : base(first, last, ssn, sales, rate) {
    setBaseSalary(salary);
}

void BasePlusSalariedEmployee::setFirstName(const string& first) { base.setFirstName(first); }
string BasePlusSalariedEmployee::getFirstName() const { return base.getFirstName(); }

void BasePlusSalariedEmployee::setLastName(const string& last) { base.setLastName(last); }
string BasePlusSalariedEmployee::getLastName() const { return base.getLastName(); }

void BasePlusSalariedEmployee::setSocialSecurityNumber(const string& ssn) {
    base.setSocialSecurityNumber(ssn);
}
string BasePlusSalariedEmployee::getSocialSecurityNumber() const {
    return base.getSocialSecurityNumber();
}

void BasePlusSalariedEmployee::setGrossSales(double sales) { base.setGrossSales(sales); }
double BasePlusSalariedEmployee::getGrossSales() const { return base.getGrossSales(); }

void BasePlusSalariedEmployee::setCommissionRate(double rate) { base.setCommissionRate(rate); }
double BasePlusSalariedEmployee::getCommissionRate() const { return base.getCommissionRate(); }

void BasePlusSalariedEmployee::setBaseSalary(double salary) {
    if (salary < 0.0)
        throw invalid_argument("Salary must be >= 0.0");
    baseSalary = salary;
}
double BasePlusSalariedEmployee::getBaseSalary() const { return baseSalary; }

double BasePlusSalariedEmployee::earnings() const { return baseSalary + base.earnings(); }

void BasePlusSalariedEmployee::print() const {
    cout << "base-salaried commission employee: " << base.getFirstName()
         << ' ' << base.getLastName()
         << "\nsocial security number: " << base.getSocialSecurityNumber()
         << "\ngross sales: " << base.getGrossSales()
         << "\ncommission rate: " << base.getCommissionRate()
         << "\nbase salary: " << baseSalary;
}
