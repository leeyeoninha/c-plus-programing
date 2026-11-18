// format_diag.cpp — 12주차 02 진단 · 제공 코드 B (서식·상태 계열)
// 13.6 조작자, 13.7 서식 상태, 13.8 오류 상태(good/eof/fail/bad/rdstate/clear/operator!/operator bool)
//
// 실행하면 count: 에 차례로 입력하세요.
//   7
//   x
//   12
//   Ctrl+Z 를 누르고 Enter   (입력의 끝 = EOF)
#include <iostream>
#include <iomanip>
using namespace std;

struct Row
{
    const char* name;
    int id;
    double pay;
    bool fulltime;
};

// 상태 함수를 모두 호출해 본다. rdstate()의 정수값은 컴파일러마다 다르므로
// 비트 하나를 골라 0/1로 확인한다.
void showState(const char* tag)
{
    cout << left << setw(8) << tag << right
         << " good=" << cin.good() << " eof=" << cin.eof()
         << " fail=" << cin.fail() << " bad=" << cin.bad()
         << " rd&fail=" << ((cin.rdstate() & ios::failbit) != 0)
         << " !cin=" << !cin
         << " bool=" << static_cast<bool>(cin) << '\n';
}

int main()
{
    const Row rows[3] = {
        { "Kim", 161, 3000.0, true },
        { "Lee", 2748, 2512.345, false },
        { "Park", 31, 4100.5, true }
    };

    // ---- 1) 서식 표 ----
    cout << left << setw(6) << "name" << right << setw(9) << "id"
         << setw(11) << "pay" << setw(7) << "full" << '\n';
    cout << setfill('-') << setw(33) << "" << '\n';
    cout << setfill(' ');                                   // (A) 채움 문자 되돌리기
    cout << fixed << setprecision(2) << boolalpha;          // (B)
    for (const Row& r : rows) {
        cout << left << setw(6) << r.name << right
             << hex << showbase << uppercase << setw(9) << r.id
             << dec << noshowbase                           // (C) 진법 되돌리기
             << setw(11) << r.pay << setw(7) << r.fulltime << '\n';
    }
    cout << noboolalpha << '\n';                            // (D)

    // ---- 2) 오류 상태 확인 ----
    int n = -1;
    showState("start");

    cout << "count: ";
    cin >> n;                                               // 입력 7
    cout << "n=" << n << '\n';
    showState("read 7");

    cout << "count: ";
    cin >> n;                                               // 입력 x
    cout << "n=" << n << '\n';
    showState("read x");

    cin.clear();                                            // (E) goodbit로 초기화
    showState("clear");
    cin.ignore(100, '\n');                                  // (F) 남은 x 버리기

    cout << "count: ";
    cin >> n;                                               // 입력 12
    cout << "n=" << n << '\n';
    showState("read 12");

    cout << "count: ";
    cin >> n;                                               // Ctrl+Z
    cout << "n=" << n << '\n';
    showState("eof");
    return 0;
}
