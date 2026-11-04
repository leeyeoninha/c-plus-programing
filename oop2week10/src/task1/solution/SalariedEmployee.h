// 과제1 [하] — 라이브러리를 상속한 파생 클래스 (모범답안)
// Employee.h / EmployeeLib.lib 는 라이브러리에서 오고, 소스 Employee.cpp 는 이 프로젝트에 없다.
#pragma once
#include "Employee.h"
#include <string>

class SalariedEmployee : public Employee {
public:
    SalariedEmployee(const std::string& name, double monthlySalary);
    double earnings() const;
    void print() const;
private:
    double monthlySalary_;
};
