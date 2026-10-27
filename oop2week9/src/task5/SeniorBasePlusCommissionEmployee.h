#pragma once
#include <string>
#include "BasePlusCommissionEmployee.h"

// 3단계 상속 계층의 맨 아래 클래스
class SeniorBasePlusCommissionEmployee : public BasePlusCommissionEmployee {
public:
    SeniorBasePlusCommissionEmployee(const std::string&, const std::string&,
        const std::string&, double = 0.0, double = 0.0, double = 0.0,
        double = 0.0, int = 0);

    void setIncentive(double);
    double getIncentive() const;

    void setYearsOfService(int);
    int getYearsOfService() const;

    double earnings() const;
    void print() const;

private:
    double incentive;      // 성과급(정액)
    int yearsOfService;    // 근속 연수
};
