// 과제3 [상] — 급여 시스템 (모범답안). 과제1의 EmployeeLib.lib 를 그대로 쓴다.
// VS: 프로젝트 폴더에 Employee.h / EmployeeLib.lib 복사 + #pragma comment(lib, "EmployeeLib.lib")
#include <iostream>
#include <iomanip>
#include <string>
#include "Employee.h"

class SalariedEmployee : public Employee {
public:
    SalariedEmployee(const std::string& name, double monthly)
        : Employee(name), monthly_(monthly) {
        std::cout << "[생성] SalariedEmployee(" << getName() << ")" << std::endl;
    }
    ~SalariedEmployee() { std::cout << "[소멸] SalariedEmployee(" << getName() << ")" << std::endl; }
    double earnings() const { return monthly_; }
    void print() const {
        Employee::print();
        std::cout << "  월급: " << monthly_ << std::endl;
    }
private:
    double monthly_;
};

class HourlyEmployee : public Employee {
public:
    HourlyEmployee(const std::string& name, double wage, double hours)
        : Employee(name), wage_(wage), hours_(hours) {
        std::cout << "[생성] HourlyEmployee(" << getName() << ")" << std::endl;
    }
    ~HourlyEmployee() { std::cout << "[소멸] HourlyEmployee(" << getName() << ")" << std::endl; }
    double earnings() const {
        if (hours_ <= 40.0) return wage_ * hours_;
        return wage_ * 40.0 + wage_ * 1.5 * (hours_ - 40.0);
    }
    bool isOvertime() const { return hours_ > 40.0; }
    void print() const {
        Employee::print();
        std::cout << "  시급: " << wage_ << ", 시간: " << hours_ << std::endl;
    }
private:
    double wage_, hours_;
};

class CommissionEmployee : public Employee {
public:
    CommissionEmployee(const std::string& name, double sales, double rate)
        : Employee(name), sales_(sales), rate_(rate) {
        std::cout << "[생성] CommissionEmployee(" << getName() << ")" << std::endl;
    }
    ~CommissionEmployee() { std::cout << "[소멸] CommissionEmployee(" << getName() << ")" << std::endl; }
    double earnings() const { return sales_ * rate_; }
    void print() const {
        Employee::print();
        std::cout << "  판매액: " << sales_ << ", 수수료율: " << rate_ << std::endl;
    }
private:
    double sales_, rate_;
};

int main() {
    Employee** staff = new Employee*[4];
    staff[0] = new SalariedEmployee("Kim", 3200.0);
    staff[1] = new HourlyEmployee("Lee", 20.0, 45.0);
    staff[2] = new CommissionEmployee("Park", 20000.0, 0.05);
    staff[3] = new SalariedEmployee("Choi", 2800.0);

    std::cout << "\n--- 명단 ---" << std::endl;
    double total = 0.0;
    for (int i = 0; i < 4; ++i) {
        staff[i]->print();
        total += staff[i]->earnings();
    }
    std::cout << "총 급여: " << std::fixed << std::setprecision(2) << total << std::endl;

    std::cout << "\n--- 시간외 근무자 ---" << std::endl;
    for (int i = 0; i < 4; ++i) {
        HourlyEmployee* h = dynamic_cast<HourlyEmployee*>(staff[i]);
        if (h != nullptr && h->isOvertime()) {
            std::cout << h->getName() << std::endl;
        }
    }

    std::cout << "\n--- 정리 ---" << std::endl;
    for (int i = 3; i >= 0; --i) delete staff[i];
    delete[] staff;
    return 0;
}
