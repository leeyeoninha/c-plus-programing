// 과제 4 (중) · 생성자와 소멸자의 호출 순서
#include <iostream>
#include <string>
using namespace std;

class CreateAndDestroy {
public:
    CreateAndDestroy(int _id, string _message) {
        objectID = _id;
        message  = _message;
        cout << "Object " << objectID << "   constructor runs   "
             << message << endl;
    }
    ~CreateAndDestroy() {
        cout << "Object " << objectID << "   destructor runs    "
             << message << endl;
    }
private:
    int objectID;
    string message;
};

void create();                                  // 프로토타입

CreateAndDestroy first(1, "(global before main)");   // 전역 객체

int main() {
    cout << "\nMAIN FUNCTION: EXECUTION BEGINS" << endl;
    CreateAndDestroy second(2, "(local automatic in main)");
    static CreateAndDestroy third(3, "(local static in main)");

    create();                                   // 다른 함수 호출

    cout << "\nMAIN FUNCTION: EXECUTION RESUMES" << endl;
    CreateAndDestroy fourth(4, "(local automatic in main)");
    cout << "\nMAIN FUNCTION: EXECUTION ENDS" << endl;
    return 0;
}

void create() {
    cout << "\nCREATE FUNCTION: EXECUTION BEGINS" << endl;
    CreateAndDestroy fifth(5, "(local automatic in create)");
    static CreateAndDestroy sixth(6, "(local static in create)");
    CreateAndDestroy seventh(7, "(local automatic in create)");
    cout << "\nCREATE FUNCTION: EXECUTION ENDS" << endl;
}
