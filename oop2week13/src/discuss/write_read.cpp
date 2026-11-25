// write_read.cpp — 13주차 02 토론·검증 · 제공 코드 A (순차 파일 쓰기와 읽기)
// 14.3 순차 파일 만들기, 파일 열기 모드, 14.4 순차 파일 읽기
//
// 입력은 없습니다. 실행하면 같은 폴더에 clients.txt를 만들고 다시 읽습니다.
// (Visual Studio에서 디버그 실행하면 "같은 폴더"는 프로젝트 폴더입니다.)
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Client
{
    int account;
    const char* name;
    double balance;
};

int main()
{
    const Client data[3] = {
        { 100, "Jones", 24.98 },
        { 200, "Doe", 345.67 },
        { 300, "White", 0.0 }
    };

    // ---- 1) 쓰기 ----
    ofstream out("clients.txt", ios::out);                 // (A) 열기 모드
    if (!out) {
        cerr << "cannot open clients.txt for writing\n";
        return 1;
    }
    for (const Client& c : data)
        out << c.account << ' ' << c.name << ' ' << c.balance << '\n';
    cout << "wrote 3 records\n";
    out.close();                                           // (B) 파일 닫기

    // ---- 2) 읽기 ----
    ifstream in("clients.txt");                            // (C) 입력용으로 열기
    if (!in) {
        cerr << "cannot open clients.txt for reading\n";
        return 1;
    }
    int account;
    string name;
    double balance;
    int count = 0;
    while (in >> account >> name >> balance) {             // (D) 읽기 루프
        cout << account << ' ' << name << ' ' << balance << '\n';
        ++count;
    }
    cout << "read " << count << " records, eof=" << in.eof()
         << " fail=" << in.fail() << '\n';
    return 0;
}
