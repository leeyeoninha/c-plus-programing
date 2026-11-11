// 진단 제공 코드 B ─ 표준 입력을 get으로 한 글자씩 받아 put으로 출력 (13.4.1, 그림 13.4)
#include <iostream>
using namespace std;

int main() {
    int ch;                                        // EOF를 구분하려면 char가 아니라 int
    while ((ch = cin.get()) != EOF)
        cout.put(static_cast<char>(ch));
    cout << endl << "[end]" << endl;
}
