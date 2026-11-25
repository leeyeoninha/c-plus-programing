// position.cpp — 13주차 02 토론·검증 · 제공 코드 B (파일 위치 포인터와 다시 읽기)
// 14.4 seekg/seekp/tellg/tellp, 슬라이드 22쪽의 clear + seekg(0), 14.5 순차 파일 갱신
//
// 입력은 없습니다. 실행하면 같은 폴더에 accounts.txt를 만들고 위치를 옮겨 가며 읽습니다.
// 레코드를 줄바꿈 없이 공백으로 이어 씁니다. 줄바꿈은 운영체제마다 저장되는 바이트 수가
// 다르지만(Windows는 2바이트), 공백은 어디서나 1바이트라 위치 값이 같게 나옵니다.
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// 다음 문자를 꺼내지 않고 보여 준다
void showNext(istream& in)
{
    int c = in.peek();
    if (c == EOF)
        cout << "EOF";
    else if (c == '\n')
        cout << "'\\n'";
    else
        cout << "'" << static_cast<char>(c) << "'";
}

// 현재 위치부터 끝까지 레코드를 읽어 이름만 출력한다
void listAll(istream& in, const char* tag)
{
    int account;
    string name;
    double balance;
    int n = 0;
    cout << "[" << tag << "]";
    while (in >> account >> name >> balance) {
        cout << ' ' << name;
        ++n;
    }
    cout << "  (" << n << " records)\n";
}

int main()
{
    // ---- 1) 파일 만들기 ----
    {
        ofstream out("accounts.txt", ios::out);
        out << "100 Jones 24.98 " << "200 Doe 345.67 " << "300 White 0.00";
        cout << "written, tellp=" << out.tellp() << '\n';
    }   // 블록이 끝나면 소멸자가 파일을 닫는다

    ifstream in("accounts.txt", ios::in);
    if (!in) {
        cerr << "cannot open accounts.txt\n";
        return 1;
    }

    // ---- 2) 위치 포인터 옮기기 ----
    in.seekg(0, ios::end);                                 // (A) 파일 끝으로
    cout << "size=" << in.tellg() << '\n';
    in.seekg(-4, ios::end);                                // (B) 끝에서 4바이트 앞
    cout << "tellg=" << in.tellg() << " next=";
    showNext(in);
    cout << '\n';
    in.seekg(4);                                           // (C) 처음에서 4바이트
    string word;
    in >> word;
    cout << "word=" << word << " tellg=" << in.tellg() << '\n';

    // ---- 3) 처음부터 두 번 읽기 (슬라이드 22쪽 방식) ----
    in.seekg(0);
    listAll(in, "pass 1");
    in.clear();                                            // (D) eofbit·failbit 지우기
    in.seekg(0);                                           // (E) 처음으로 되감기
    listAll(in, "pass 2");
    in.close();

    // ---- 4) 제자리 갱신 (14.5) ----
    fstream io("accounts.txt", ios::in | ios::out);
    io.seekp(20);                                          // (F) 둘째 레코드의 이름 자리
    io << "Kim";                                           // (G) 같은 길이(3자)로 덮어쓰기
    io.close();

    ifstream again("accounts.txt", ios::in);
    string line;
    while (getline(again, line))
        cout << "  |" << line << "|\n";
    return 0;
}
