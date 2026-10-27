#pragma once
#include <string>

// 상속 없이 만든 버전: CommissionEmployee의 멤버와 함수를 그대로 복사해 왔다.
class BasePlusCommissionEmployee {
public:
    BasePlusCommissionEmployee(const std::string&, const std::string&,
        const std::string&, double = 0.0, double = 0.0, double = 0.0);

    void setFirstName(const std::string&);
    std::string getFirstName() const;

    void setLastName(const std::string&);
    std::string getLastName() const;

    void setSocialSecurityNumber(const std::string&);
    std::string getSocialSecurityNumber() const;

    void setGrossSales(double);
    double getGrossSales() const;

    void setCommissionRate(double);
    double getCommissionRate() const;

    void setBaseSalary(double);
    double getBaseSalary() const;

    double earnings() const;
    void print() const;

private:
    std::string firstName;
    std::string lastName;
    std::string socialSecurityNumber;
    double grossSales;
    double commissionRate;
    double baseSalary;
};
