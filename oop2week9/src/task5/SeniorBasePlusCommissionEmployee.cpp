#include <iostream>
#include <stdexcept>
#include "SeniorBasePlusCommissionEmployee.h"
using namespace std;

SeniorBasePlusCommissionEmployee::SeniorBasePlusCommissionEmployee(
    const string& first, const string& last, const string& ssn,
    double sales, double rate, double salary, double bonus, int years)
    : BasePlusCommissionEmployee(first, last, ssn, sales, rate, salary) {
    setIncentive(bonus);
    setYearsOfService(years);
}

void SeniorBasePlusCommissionEmployee::setIncentive(double bonus) {
    if (bonus < 0.0)
        throw invalid_argument("Incentive must be >= 0.0");
    incentive = bonus;
}
double SeniorBasePlusCommissionEmployee::getIncentive() const { return incentive; }

void SeniorBasePlusCommissionEmployee::setYearsOfService(int years) {
    if (years < 0)
        throw invalid_argument("Years of service must be >= 0");
    yearsOfService = years;
}
int SeniorBasePlusCommissionEmployee::getYearsOfService() const { return yearsOfService; }

double SeniorBasePlusCommissionEmployee::earnings() const {
    // 직계 기반 클래스의 earnings를 재사용하고 성과급만 더한다
    return BasePlusCommissionEmployee::earnings() + incentive;
}

void SeniorBasePlusCommissionEmployee::print() const {
    cout << "senior ";                        // 기반 print의 첫 단어 앞에 붙인다
    BasePlusCommissionEmployee::print();      // 기반 클래스 출력 재사용
    cout << "\nincentive: " << incentive
         << "\nyears of service: " << yearsOfService;
}
