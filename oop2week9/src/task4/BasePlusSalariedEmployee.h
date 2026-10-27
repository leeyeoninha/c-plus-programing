#pragma once
#include <string>
#include "../common/CommissionEmployee.h"

// 상속 대신 컴포지션(has-a): CommissionEmployee 객체를 멤버로 "가지고" 있다
class BasePlusSalariedEmployee {
public:
    BasePlusSalariedEmployee(const std::string&, const std::string&,
        const std::string&, double = 0.0, double = 0.0, double = 0.0);

    // 기반 클래스의 서비스를 하나하나 위임(delegation)해야 한다
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
    CommissionEmployee base;   // has-a 관계
    double baseSalary;
};
