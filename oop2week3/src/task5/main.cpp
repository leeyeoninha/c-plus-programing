// main.cpp — Time 클래스 사용(구현을 몰라도 헤더만 보고 사용)
// 컴파일: g++ -std=c++17 main.cpp time2.cpp -o app
#include <iostream>
#include "time2.h"
using namespace std;

int main() {
    cout << "--- 기본 인자 생성자 4가지 호출 ---" << endl;
    Time t1;                  // 인자 0개 → 00:00:00
    Time t2(2);               // 시만 지정 → 02:00:00
    Time t3(21, 34);          // 시, 분   → 21:34:00
    Time t4(12, 25, 42);      // 전부 지정 → 12:25:42

    cout << "\n--- 잘못된 값으로 생성 ---" << endl;
    Time t5(27, 74, 99);      // 모두 범위 밖 → 00:00:00

    cout << "\n--- 각 객체 출력 (24시간 / 12시간) ---" << endl;
    Time *list[5] = { &t1, &t2, &t3, &t4, &t5 };
    for (int i = 0; i < 5; ++i) {
        cout << "t" << (i + 1) << " : ";
        list[i]->printUniversal();
        cout << "  |  ";
        list[i]->printStandard();
        cout << endl;
    }

    cout << "\n--- setTime으로 값 변경 ---" << endl;
    t1.setTime(13, 27, 6);
    cout << "t1 변경 후 : ";
    t1.printUniversal();
    cout << "  |  ";
    t1.printStandard();
    cout << endl;

    cout << "\n--- main 종료(소멸자는 생성의 역순) ---" << endl;
    return 0;
}
