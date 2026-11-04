#include "SalariedEmployee.h"
#include <iostream>

SalariedEmployee::SalariedEmployee(const std::string& name, double monthlySalary)
    : Employee(name), monthlySalary_(monthlySalary) {}

double SalariedEmployee::earnings() const {
    return monthlySalary_;
}

void SalariedEmployee::print() const {
    Employee::print();
    std::cout << "  월급: " << monthlySalary_ << std::endl;
}
