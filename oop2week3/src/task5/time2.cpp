// time2.cpp — class Time의 멤버 함수 정의(구현)
#include <iostream>
#include <iomanip>
#include "time2.h"
using namespace std;

// 기본 인자를 가진 생성자: setTime을 재사용해 유효성 검사까지 수행
Time::Time(int h, int m, int s) {
    setTime(h, m, s);
    cout << "[생성] ";
    printUniversal();
    cout << " 객체가 만들어졌습니다." << endl;
}

Time::~Time() {
    cout << "[소멸] ";
    printUniversal();
    cout << " 객체가 소멸됩니다." << endl;
}

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
