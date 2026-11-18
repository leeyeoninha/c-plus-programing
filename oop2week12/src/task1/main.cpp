// task1/main.cpp — 문제 1 [하] 시작 파일
// 상속과 다형성 복습: TODO 자리를 채워 완성하세요.
// 이 파일은 그대로도 컴파일됩니다. 완성하면 출력이 문제의 예시와 같아야 합니다.
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
    // TODO 1: 기반 포인터로 delete 해도 파생 소멸자가 불리도록 소멸자를 선언하세요.

    const string& getName() const { return name; }
    int getId() const { return id; }

    // TODO 2: earnings()와 kind()를 순수 가상 함수로 선언하세요.
    //         earnings()는 double, kind()는 string을 돌려줍니다.

    // 모든 사원이 같은 모양으로 출력한다.
    virtual void print() const
    {
        // TODO 3: 아래 주석을 풀고 완성하세요. earnings()와 kind()는 가상 호출입니다.
        // cout << kind() << " " << name << " (id " << id << ") earns "
        //      << earnings() << '\n';
    }

private:
    string name;
    int id;
};

// ---------- 월급제 (완성된 예) ----------
class SalariedEmployee : public Employee
{
public:
    SalariedEmployee(const string& name, int id, double salary)
        : Employee(name, id), salary(salary) {}

    // TODO 2를 마치면 아래 두 줄의 주석을 푸세요.
    // double earnings() const override { return salary; }
    // string kind() const override { return "Salaried"; }

private:
    double salary;
};

// TODO 4: HourlyEmployee — 시급(wage)과 근무 시간(hours)
//         40시간까지는 wage * hours, 초과분은 1.5배.  kind()는 "Hourly"

// TODO 5: CommissionEmployee — 판매액(sales)과 수수료율(rate)
//         earnings()는 sales * rate.  kind()는 "Commission"

int main()
{
    vector<unique_ptr<Employee>> staff;
    staff.push_back(make_unique<SalariedEmployee>("Kim", 161, 800.0));
    // TODO 6: 아래 세 명을 추가하세요.
    //   Hourly     "Lee"  162  wage 16.80  hours 45
    //   Commission "Park" 163  sales 10000.0  rate 0.06
    //   Hourly     "Choi" 164  wage 20.0  hours 38

    cout << fixed << setprecision(2);

    // TODO 7: 기반 클래스 포인터만으로 모든 사원을 print() 하고 earnings()를 합산하세요.
    //         사원 종류를 묻는 if / switch 를 쓰지 마세요.
    double total = 0.0;

    cout << "employees: " << staff.size() << ", total: " << total << '\n';
    return 0;
}
