// 과제 2 (중) · 합성(has-a) — Date를 멤버로 가지는 Employee
#include <iostream>
#include <format>
#include <string>
#include <stdexcept>
using namespace std;

class Date {
public:
    explicit Date(int m = 1, int d = 1, int y = 1900);
    ~Date();
    void print() const;                 // 월/일/연 출력
    int getMonth() const { return month; }
private:
    int month, day, year;
};

Date::Date(int m, int d, int y) {
    if (m < 1 || m > 12)
        throw invalid_argument("month must be 1-12");
    month = m;
    day   = d;
    year  = y;
    cout << format("  [Date 생성자] {}/{}/{}\n", month, day, year);
}
Date::~Date() {
    cout << format("  [Date 소멸자] {}/{}/{}\n", month, day, year);
}
void Date::print() const {
    cout << format("{}/{}/{}", month, day, year);
}

class Employee {
public:
    Employee(const string &first, const string &last,
             const Date &dateOfBirth, const Date &dateOfHire);
    ~Employee();
    void print() const;
private:
    string firstName;
    string lastName;
    Date birthDate;      // has-a : Employee는 Date를 가진다
    Date hireDate;       // has-a
};

// 멤버 초기화자 목록으로 멤버 객체의 생성자에 값을 전달
Employee::Employee(const string &first, const string &last,
                   const Date &dateOfBirth, const Date &dateOfHire)
    : firstName(first),
      lastName(last),
      birthDate(dateOfBirth),
      hireDate(dateOfHire)
{
    cout << format("[Employee 생성자] {} {}\n", firstName, lastName);
}

Employee::~Employee() {
    cout << format("[Employee 소멸자] {} {}\n", firstName, lastName);
}

void Employee::print() const {
    cout << format("{} {}  입사일: ", lastName, firstName);
    hireDate.print();                // const 멤버 함수만 호출 가능
    cout << "  생년월일: ";
    birthDate.print();
    cout << '\n';
}

int main() {
    cout << "--- Date 객체 2개 생성 ---\n";
    Date birth{7, 24, 1949};
    Date hire{3, 12, 1988};

    cout << "\n--- Employee 생성 (복사 생성자로 멤버 객체 초기화) ---\n";
    Employee manager{"Bob", "Blue", birth, hire};

    cout << "\n--- 정보 출력 ---\n";
    manager.print();

    cout << "\n--- const 객체 ---\n";
    const Employee advisor{"Ann", "Gray", birth, hire};
    advisor.print();                 // print가 const라 호출 가능

    cout << "\n--- 잘못된 월로 Date 생성 시도 ---\n";
    try {
        Date bad{13, 1, 2000};
    }
    catch (const invalid_argument &e) {
        cout << "예외 발생: " << e.what() << '\n';
    }

    cout << "\n--- main 종료 (소멸 순서 확인) ---\n";
    return 0;
}
