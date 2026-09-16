// 과제 2 (중) · class Time — 캡슐화와 유효성 검사
#include <iostream>
#include <iomanip>
using namespace std;

class Time {
public:
    Time();                               // 생성자
    void setTime(int, int, int);          // 유효성 검사 포함
    void printUniversal() const;
    void printStandard() const;
private:
    int hour;    // 0-23
    int minute;  // 0-59
    int second;  // 0-59
};

Time::Time() { hour = minute = second = 0; }

void Time::setTime(int h, int m, int s) {
    hour   = (h >= 0 && h < 24) ? h : 0;
    minute = (m >= 0 && m < 60) ? m : 0;
    second = (s >= 0 && s < 60) ? s : 0;
}
void Time::printUniversal() const {
    cout << setfill('0') << setw(2) << hour << ":"
         << setw(2) << minute << ":" << setw(2) << second;
}
void Time::printStandard() const {
    cout << ((hour == 0 || hour == 12) ? 12 : hour % 12)
         << ":" << setfill('0') << setw(2) << minute
         << ":" << setw(2) << second
         << (hour < 12 ? " AM" : " PM");
}

int main() {
    Time t;
    cout << "The initial universal time is ";
    t.printUniversal();
    cout << "\nThe initial standard time is ";
    t.printStandard();

    int h, m, s;
    cout << "\n\n시, 분, 초를 입력하세요: ";
    cin >> h >> m >> s;
    t.setTime(h, m, s);

    cout << "Universal time after setTime is ";
    t.printUniversal();
    cout << "\nStandard time after setTime is ";
    t.printStandard();
    cout << endl;
    return 0;
}
