// 과제 3 (중) · 객체 이름 / 레퍼런스 / 포인터로 멤버 접근하기
#include <iostream>
using namespace std;

class Count {
public:
    void setX(int _x) { x = _x; }   // set 함수
    int  getX() const { return x; } // get 함수
    void print() const { cout << x << endl; }
private:
    int x = 0;                      // 기본 private
};

int main() {
    Count counter;
    Count *counterPtr = &counter;   // 포인터
    Count &counterRef = counter;    // 레퍼런스

    cout << "Assign 1 to x and print using the object's name: ";
    counter.setX(1);
    counter.print();

    cout << "Assign 2 to x and print using a reference: ";
    counterRef.setX(2);
    counterRef.print();

    cout << "Assign 3 to x and print using a pointer: ";
    counterPtr->setX(3);
    counterPtr->print();

    cout << "\n세 핸들이 같은 객체를 가리키는지 확인\n";
    cout << "counter.getX()      = " << counter.getX() << endl;
    cout << "counterRef.getX()   = " << counterRef.getX() << endl;
    cout << "counterPtr->getX()  = " << counterPtr->getX() << endl;
    cout << "(*counterPtr).getX()= " << (*counterPtr).getX() << endl;
    return 0;
}
