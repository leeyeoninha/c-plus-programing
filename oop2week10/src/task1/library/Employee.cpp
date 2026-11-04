#include "Employee.h"
#include <iostream>

Employee::Employee(const std::string& name) : name_(name) {}
Employee::~Employee() {}

const std::string& Employee::getName() const { return name_; }

double Employee::earnings() const { return 0.0; }

void Employee::print() const {
    std::cout << "name: " << name_ << std::endl;
}
