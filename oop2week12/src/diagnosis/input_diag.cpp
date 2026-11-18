// input_diag.cpp — 12주차 02 진단 · 제공 코드 A (입력 계열)
// 13.4 get / getline / peek / putback / ignore, 13.5 read / write / gcount, 13.8 오류 상태
//
// 실행하면 아래 다섯 줄을 차례로 입력하세요.
//   Kim 3000
//   Development
//   A-17
//   x9
//   29
#include <iostream>
using namespace std;

// 스트림 상태 함수 네 개를 한 줄로 보여 준다
void showState(const char* tag)
{
    cout << "  [" << tag << "] good=" << cin.good() << " eof=" << cin.eof()
         << " fail=" << cin.fail() << " bad=" << cin.bad() << '\n';
}

// 다음 문자를 꺼내지 않고(peek) 보여 준다
void showNext()
{
    int c = cin.peek();
    if (c == EOF)
        cout << "next=EOF";
    else if (c == '\n')
        cout << "next='\\n'";
    else
        cout << "next='" << static_cast<char>(c) << "'";
}

int main()
{
    // ---- 1) >> 연산자 : 공백에서 멈춘다 ----
    char name[10];
    int pay = 0;
    cout << "name pay: ";
    cin >> name >> pay;                           // 입력 1
    cout << "name=[" << name << "] pay=" << pay << '\n';
    cin.ignore(100, '\n');                        // (A) 줄 끝의 '\n'까지 버린다
    showState("line1");

    // ---- 2) get 3인자 : n-1개까지, 구분자는 남긴다 ----
    char dept[8];
    cout << "dept: ";
    cin.get(dept, 8);                             // (B) 입력 2
    cout << "dept=[" << dept << "] ";
    showNext();
    cout << '\n';
    cin.ignore(100, '\n');                        // (C)
    cout << "ignored " << cin.gcount() << " chars\n";
    showState("line2");

    // ---- 3) get(char&) / peek / putback / read / write ----
    char grade = ' ';
    cout << "grade: ";
    cin.get(grade);                               // 입력 3
    cout << "grade=" << grade << ' ';
    showNext();
    cout << '\n';
    cin.putback(grade);                           // (D) 읽은 문자를 되돌린다
    char code[4] = {};
    cin.read(code, 4);                            // (E) 널 문자를 붙이지 않는다
    cout << "read " << cin.gcount() << ": ";
    cout.write(code, cin.gcount());              // 읽은 만큼만 출력
    cout << '\n';
    cin.ignore(100, '\n');
    showState("line3");

    // ---- 4) 서식 오류와 복구 ----
    int age = -1;
    cout << "age: ";
    cin >> age;                                   // 입력 4
    cout << "age=" << age << '\n';
    showState("bad age");
    cin.clear();                                  // (F) 상태를 goodbit로
    cin.ignore(100, '\n');                        // (G) 남은 문자 버리기
    cout << "age again: ";
    cin >> age;                                   // 입력 5
    cout << "age=" << age << '\n';
    showState("end");
    return 0;
}
