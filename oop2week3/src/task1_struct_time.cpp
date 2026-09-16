// 과제 1 (하) · struct Time — 멤버 직접 접근의 위험
#include <iostream>
#include <iomanip>
using namespace std;

struct Time {           // 구조체 태그
    int hour;           // 0-23
    int minute;         // 0-59
    int second;         // 0-59
};

void printUniversal(const Time &t) {
    cout << setfill('0') << setw(2) << t.hour << ":"
         << setw(2) << t.minute << ":" << setw(2) << t.second;
}
void printStandard(const Time &t) {
    cout << ((t.hour == 0 || t.hour == 12) ? 12 : t.hour % 12)
         << ":" << setfill('0') << setw(2) << t.minute
         << ":" << setw(2) << t.second
         << (t.hour < 12 ? " AM" : " PM");
}

int main() {
    Time dinnerTime;
    cout << "시, 분, 초를 입력하세요: ";
    cin >> dinnerTime.hour >> dinnerTime.minute >> dinnerTime.second;

    cout << "Dinner will be held at ";
    printUniversal(dinnerTime);
    cout << " universal time,\nwhich is ";
    printStandard(dinnerTime);
    cout << " standard time.\n";

    cout << "\n[검증 없음] 잘못된 값 29시 73분을 그대로 대입합니다.\n";
    dinnerTime.hour = 29;
    dinnerTime.minute = 73;
    cout << "Time with invalid values: ";
    printUniversal(dinnerTime);
    cout << endl;
    return 0;
}
