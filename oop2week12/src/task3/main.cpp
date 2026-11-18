// task3/main.cpp — 문제 3 [상] 모범 답안
// 클래스로 만든 조작자: 매개변수 없는 것 / 매개변수 있는 것 / 입력용
//
// 4) 단계에서 입력할 줄 (id:pay, 0 이면 끝)
//   161:3000
//   162-2500
//   abc:100
//   163 : 2512.5
//   164:4100.25
//   0
#include <iostream>
#include <iomanip>
#include <limits>
#include "Manip.h"
using namespace std;

int main()
{
    // ---- 1) 매개변수 없는 조작자: 함수형(교재) vs 클래스형 ----
    cout << "[1] no parameter" << endLine;
    cout << "a" << sep << "b" << sep << "c" << endLine;
    cout << hex << showbase << uppercase << 255 << sep
         << resetfmt << 255 << endLine;

    // ---- 2) 매개변수 있는 조작자: 인자를 생략한 호출과 준 호출 ----
    cout << "[2] with parameters" << endLine;
    cout << Line();
    cout << Line('=');
    cout << Line('*', 12);
    cout << HexId(161) << sep << HexId(161, 6) << sep << 161 << endLine;
    cout << Money(3000) << sep << Money(2512.75, 9) << sep
         << Money(2512.75, 9, 0) << sep << 2512.75 << endLine;

    // ---- 3) 조작자가 서식을 되돌렸는지 확인 ----
    cout << "[3] state after manipulators" << endLine;
    cout << "flags dec? " << ((cout.flags() & ios::dec) != 0)
         << "  precision " << cout.precision()
         << "  fill '" << cout.fill() << "'" << endLine;

    // ---- 4) 입력 조작자 Expect 와 오류 상태 복구 ----
    cout << "[4] input id:pay (0 to stop)" << endLine;
    const int MAX = 10;
    int ids[MAX];
    double pays[MAX];
    int count = 0;

    while (count < MAX) {
        int id = 0;
        double pay = 0.0;
        cout << "id:pay> ";
        if (!(cin >> id)) {
            if (cin.eof())
                break;
            cerr << "  bad id, line skipped\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        if (id == 0)
            break;
        if (!(cin >> Expect(':') >> pay)) {
            cerr << "  expected id:pay, line skipped\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        ids[count] = id;
        pays[count] = pay;
        ++count;
    }

    // ---- 5) 리포트: 만든 조작자만으로 서식을 맞춘다 ----
    cout << Line('=', 21);
    double total = 0.0;
    for (int i = 0; i < count; ++i) {
        cout << HexId(ids[i]) << sep << Money(pays[i]) << endLine;
        total += pays[i];
    }
    cout << Line('-', 21);
    cout << "total " << Money(total, 15) << endLine;
    return 0;
}
