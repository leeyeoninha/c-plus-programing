// 과제 1 (하) · Time 클래스 — std::format 출력과 예외를 던지는 set 함수
#include <iostream>
#include <format>
#include <stdexcept>
using namespace std;

class Time {
public:
    explicit Time(int h = 0, int m = 0, int s = 0);
    void setHour(int h);
    void setMinute(int m);
    void setSecond(int s);
    unsigned int getHour() const;
    unsigned int getMinute() const;
    unsigned int getSecond() const;
    void printUniversal() const;   // 24시간 형식
    void printStandard() const;    // 12시간 형식
private:
    unsigned int hour;    // 0-23
    unsigned int minute;  // 0-59
    unsigned int second;  // 0-59
};

Time::Time(int h, int m, int s) {
    setHour(h);
    setMinute(m);
    setSecond(s);
}

void Time::setHour(int h) {
    if (h >= 0 && h < 24)
        hour = h;
    else
        throw invalid_argument("hour must be 0-23");
}
void Time::setMinute(int m) {
    if (m >= 0 && m < 60)
        minute = m;
    else
        throw invalid_argument("minute must be 0-59");
}
void Time::setSecond(int s) {
    if (s >= 0 && s < 60)
        second = s;
    else
        throw invalid_argument("second must be 0-59");
}

unsigned int Time::getHour() const   { return hour; }
unsigned int Time::getMinute() const { return minute; }
unsigned int Time::getSecond() const { return second; }

void Time::printUniversal() const {
    cout << format("{:02}:{:02}:{:02}", hour, minute, second);
}
void Time::printStandard() const {
    cout << format("{}:{:02}:{:02} {}",
                   ((hour == 0 || hour == 12) ? 12 : hour % 12),
                   minute, second,
                   (hour < 12 ? "AM" : "PM"));
}

int main() {
    Time t{13, 27, 6};
    cout << "24시간 형식: ";  t.printUniversal();  cout << '\n';
    cout << "12시간 형식: ";  t.printStandard();   cout << '\n';

    cout << "\n시, 분, 초를 입력하세요: ";
    int h = 0, m = 0, s = 0;
    if (!(cin >> h >> m >> s)) {          // 입력 실패 검사
        cout << "숫자를 입력해야 합니다.\n";
        return 1;
    }

    try {
        t.setHour(h);
        t.setMinute(m);
        t.setSecond(s);
        cout << "설정 성공 -> ";
        t.printUniversal();
        cout << " / ";
        t.printStandard();
        cout << '\n';
    }
    catch (const invalid_argument &e) {
        cout << "예외 발생: " << e.what() << '\n';
        cout << "현재 객체 상태 -> ";
        t.printUniversal();
        cout << '\n';
    }
    return 0;
}
