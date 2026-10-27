#pragma once
#include <string>
#include "../common/CommissionEmployee.h"

// public 상속: BasePlusCommissionEmployee는 CommissionEmployee이다(is-a)
class BasePlusCommissionEmployee : public CommissionEmployee {
public:
    BasePlusCommissionEmployee(const std::string&, const std::string&,
        const std::string&, double = 0.0, double = 0.0, double = 0.0);

    void setBaseSalary(double);
    double getBaseSalary() const;

    double earnings() const;     // 기반 클래스 earnings를 숨긴다(hiding)
    void print() const;          // 기반 클래스 print를 숨긴다

private:
    double baseSalary;
};
