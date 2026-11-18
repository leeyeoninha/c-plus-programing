// task2/main.cpp — 문제 2 [중] 모범 답안
// 문제 1의 사원 계층 + 13장: 표준 입력 검증(오류 상태 복구) + 서식 조작자로 리포트
//
// 입력 형식 (한 줄에 한 명, END 로 끝내거나 Ctrl+Z)
//   S 이름 월급
//   H 이름 시급 시간
//   C 이름 판매액 수수료율
//   # 로 시작하는 줄은 주석
#include <iostream>
#include <iomanip>
#include <limits>
#include <memory>
#include <string>
#include <vector>
using namespace std;

// ---------- 추상 기반 클래스 ----------
class Employee
{
public:
    Employee(const string& name, int id) : name(name), id(id) {}
    virtual ~Employee() = default;

    virtual double earnings() const = 0;
    virtual string kind() const = 0;

    // 한 줄을 out에 출력한다. 바꾼 서식 상태는 끝에서 되돌린다.
    virtual void print(ostream& out) const
    {
        ios_base::fmtflags oldFlags = out.flags();
        char oldFill = out.fill();
        streamsize oldPrec = out.precision();

        out << left << setw(8) << name << setw(11) << kind()
            << right << internal << hex << showbase << uppercase
            << setfill('0') << setw(6) << id
            << setfill(' ') << dec << noshowbase << right
            << fixed << setprecision(2) << setw(12) << earnings();

        out.flags(oldFlags);
        out.fill(oldFill);
        out.precision(oldPrec);
    }

private:
    string name;
    int id;
};

// 기반 클래스 참조 하나로 모든 사원을 출력한다 — print()가 가상이므로 파생 버전이 불린다
ostream& operator<<(ostream& out, const Employee& e)
{
    e.print(out);
    return out;
}

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

// 실패한 줄을 정리한다: 상태를 되돌리고(clear) 줄 끝까지 버린다(ignore)
void skipLine()
{
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int main()
{
    vector<unique_ptr<Employee>> staff;
    int lineNo = 0;
    int skipped = 0;
    int nextId = 0xA1;

    cout << "type name values  (S salary | H wage hours | C sales rate), END to stop\n";

    while (true) {
        cin >> ws;                              // 앞쪽 공백·빈 줄 건너뛰기
        if (cin.peek() == EOF)                  // Ctrl+Z
            break;
        if (cin.peek() == '#') {                // 주석 줄은 꺼내지 않고 확인한 뒤 통째로 버린다
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        string type, name;
        cin >> type;
        if (type == "END")
            break;
        ++lineNo;
        cin >> name;

        unique_ptr<Employee> e;
        if (type == "S") {
            double salary;
            if (cin >> salary)
                e = make_unique<SalariedEmployee>(name, nextId, salary);
        }
        else if (type == "H") {
            double wage, hours;
            if (cin >> wage >> hours)
                e = make_unique<HourlyEmployee>(name, nextId, wage, hours);
        }
        else if (type == "C") {
            double sales, rate;
            if (cin >> sales >> rate)
                e = make_unique<CommissionEmployee>(name, nextId, sales, rate);
        }
        else {
            cerr << "line " << lineNo << ": unknown type '" << type << "', skipped\n";
            ++skipped;
            skipLine();
            continue;
        }

        if (!cin) {                             // operator! : failbit 또는 badbit
            cerr << "line " << lineNo << ": bad number, skipped\n";
            ++skipped;
            skipLine();
            continue;
        }
        staff.push_back(std::move(e));
        ++nextId;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    bool endedByEof = cin.eof();

    // ---------- 리포트 ----------
    cout << '\n';
    cout << left << setw(8) << "name" << setw(11) << "type"
         << right << setw(6) << "id" << setw(12) << "earnings" << '\n';
    cout << setfill('-') << setw(37) << "" << setfill(' ') << '\n';

    double total = 0.0;
    for (const auto& e : staff) {
        cout << *e << '\n';                     // operator<< → 가상 print()
        total += e->earnings();
    }
    cout << setfill('-') << setw(37) << "" << setfill(' ') << '\n';
    cout << left << setw(25) << "total" << right
         << fixed << setprecision(2) << setw(12) << total << '\n';

    cout << '\n' << "lines " << lineNo << ", stored " << staff.size()
         << ", skipped " << skipped << ", ended by "
         << (endedByEof ? "EOF" : "END") << '\n';
    return 0;
}
