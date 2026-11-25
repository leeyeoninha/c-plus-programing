// task1/main.cpp — 문제 1 [하] 시작 파일
// 순차 파일 만들기(그림 14.3)와 읽기(그림 14.6)를 한 프로그램으로 완성하세요.
// 이 파일은 그대로도 컴파일됩니다.
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

void outputLine(int account, const string& name, double balance)
{
    cout << left << setw(10) << account << setw(13) << name
         << right << setw(10) << balance << '\n';
}

int main()
{
    // ---- 1) 열기 모드 고르기 ----
    char mode = ' ';
    cout << "mode (w = new file, a = append): ";
    cin >> mode;
    // TODO 1: mode가 'a'이면 ios::app, 아니면 ios::out 으로 clients.txt를 여는
    //         ofstream outClientFile 을 만드세요.
    // TODO 2: 열기에 실패하면 cerr에 "File could not be opened"를 출력하고 1을 돌려주세요.

    // ---- 2) 파일 끝(Ctrl+Z)까지 입력해 파일에 쓰기 ----
    cout << "Enter the account, name, and balance.\n"
         << "Enter end-of-file to end input.\n? ";
    int account = 0;
    string name;
    double balance = 0.0;
    int written = 0;
    // TODO 3: cin >> account >> name >> balance 가 성공하는 동안
    //         한 줄씩 파일에 쓰고(공백으로 구분, 줄 끝 '\n'), written을 늘리고, "? "를 출력하세요.

    // TODO 4: 읽기 전에 outClientFile을 닫으세요. (닫지 않으면 어떻게 되는지 02 토론 3에서 확인합니다.)
    cout << '\n' << written << " records written\n\n";

    // ---- 3) 같은 파일을 처음부터 읽어 표로 출력 ----
    // TODO 5: clients.txt를 입력용으로 여는 ifstream inClientFile 을 만들고 실패를 검사하세요.
    cout << left << setw(10) << "Account" << setw(13) << "Name"
         << right << setw(10) << "Balance" << '\n';
    cout << fixed << setprecision(2);

    int count = 0;
    double total = 0.0;
    // TODO 6: 레코드를 끝까지 읽으며 outputLine으로 출력하고 count와 total을 구하세요.
    //         while (!inClientFile.eof()) 형태는 쓰지 마세요.
    cout << count << " records in file, total " << total << '\n';
    return 0;
}
