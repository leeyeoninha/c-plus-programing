// 진단 제공 코드 A ─ 정상 동작하는 기준선 (12.5~12.6)
// 이 파일을 그대로 컴파일·실행해 출력 4줄 + 소멸 4줄을 먼저 적어 둡니다.
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Employee {
public:
    Employee(const string& name) : name_(name) {}
    virtual ~Employee() { cout << "[dtor] Employee(" << name_ << ")" << endl; }

    const string& getName() const { return name_; }

    virtual double earnings() const = 0;          // 순수 가상 ─ Employee는 답을 모른다
    virtual void print() const { cout << "name: " << name_ << ", "; }

private:
    string name_;
};

class SalariedEmployee : public Employee {
public:
    SalariedEmployee(const string& name, double salary)
        : Employee(name), salary_(salary) {}
    ~SalariedEmployee() { cout << "[dtor] Salaried(" << getName() << ")" << endl; }

    double earnings() const override { return salary_; }
    void print() const override { Employee::print(); cout << "salary: " << earnings() << endl; }

private:
    double salary_;
};

class CommissionEmployee : public Employee {
public:
    CommissionEmployee(const string& name, double rate, double sales)
        : Employee(name), rate_(rate), sales_(sales) {}
    ~CommissionEmployee() { cout << "[dtor] Commission(" << getName() << ")" << endl; }

    double earnings() const override { return rate_ * sales_; }
    void print() const override { Employee::print(); cout << "commission: " << earnings() << endl; }

private:
    double rate_, sales_;
};

int main() {
    vector<Employee*> staff;
    staff.push_back(new SalariedEmployee("Kim", 3000));
    staff.push_back(new CommissionEmployee("Lee", 0.25, 8000));

    double total = 0;
    for (Employee* e : staff) { e->print(); total += e->earnings(); }
    cout << "total: " << total << endl;

    for (Employee* e : staff) delete e;            // 소멸 순서를 눈으로 확인
}
