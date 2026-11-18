// task1/solution/main.cpp — 문제 1 [하] 모범 답안
// 상속과 다형성 복습: 추상 기반 클래스 Employee와 파생 클래스 세 개
#include <iostream>
#include <iomanip>
#include <memory>
#include <string>
#include <vector>
using namespace std;

// ---------- 추상 기반 클래스 ----------
class Employee
{
public:
    Employee(const string& name, int id) : name(name), id(id) {}
    virtual ~Employee() = default;              // 기반 포인터로 delete 할 때 필요

    const string& getName() const { return name; }
    int getId() const { return id; }

    virtual double earnings() const = 0;        // 순수 가상 함수 → 추상 클래스
    virtual string kind() const = 0;

    // 모든 사원이 같은 모양으로 출력한다. earnings()와 kind()는 가상 호출이다.
    virtual void print() const
    {
        cout << kind() << " " << name << " (id " << id << ") earns "
             << earnings() << '\n';
    }

private:
    string name;
    int id;
};

// ---------- 월급제 ----------
class SalariedEmployee : public Employee
{
public:
    SalariedEmployee(const string& name, int id, double salary)
        : Employee(name, id), salary(salary) {}

    double earnings() const override { return salary; }
    string kind() const override { return "Salaried"; }

private:
    double salary;
};

// ---------- 시급제 : 40시간 초과분은 1.5배 ----------
class HourlyEmployee : public Employee
{
public:
    HourlyEmployee(const string& name, int id, double wage, double hours)
        : Employee(name, id), wage(wage), hours(hours) {}

    double earnings() const override
    {
        if (hours <= 40)
            return wage * hours;
        return 40 * wage + (hours - 40) * wage * 1.5;
    }
    string kind() const override { return "Hourly"; }

private:
    double wage;
    double hours;
};

// ---------- 수수료제 ----------
class CommissionEmployee : public Employee
{
public:
    CommissionEmployee(const string& name, int id, double sales, double rate)
        : Employee(name, id), sales(sales), rate(rate) {}

    double earnings() const override { return sales * rate; }
    string kind() const override { return "Commission"; }

private:
    double sales;
    double rate;
};

int main()
{
    vector<unique_ptr<Employee>> staff;
    staff.push_back(make_unique<SalariedEmployee>("Kim", 161, 800.0));
    staff.push_back(make_unique<HourlyEmployee>("Lee", 162, 16.80, 45));
    staff.push_back(make_unique<CommissionEmployee>("Park", 163, 10000.0, 0.06));
    staff.push_back(make_unique<HourlyEmployee>("Choi", 164, 20.0, 38));

    cout << fixed << setprecision(2);

    // 기반 클래스 포인터만으로 처리한다 — 사원 종류를 묻는 if/switch가 없다
    double total = 0.0;
    for (const auto& e : staff) {
        e->print();
        total += e->earnings();
    }
    cout << "employees: " << staff.size() << ", total: " << total << '\n';
    return 0;
}
