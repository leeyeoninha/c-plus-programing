// 과제 2 · static 데이터 멤버와 static 멤버 함수 (교재 그림 9.27~9.29 기반)
#include <iostream>
#include <string>
using namespace std;

class Employee
{
public:
   Employee( const string &, const string & );
   ~Employee();
   string getFirstName() const;
   string getLastName() const;
   unsigned int getId() const;

   // static 멤버 함수 — 객체가 없어도 호출할 수 있다
   static unsigned int getCount();   // 현재 메모리에 있는 객체 수
   static unsigned int getIssued();  // 지금까지 발급한 사번 수
private:
   string firstName;
   string lastName;
   unsigned int id; // 객체마다 고유한 사번

   // static 데이터 멤버 — 모든 객체가 하나를 공유한다
   static unsigned int count;
   static unsigned int nextId;
};

// 클래스 밖에서 정의하고 초기화 — static 키워드는 쓰지 않는다
unsigned int Employee::count = 0;
unsigned int Employee::nextId = 0;

unsigned int Employee::getCount() { return count; }
unsigned int Employee::getIssued() { return nextId; }

Employee::Employee( const string &first, const string &last )
   : firstName( first ), lastName( last ), id( ++nextId )
{
   ++count;
   cout << "Employee constructor for " << firstName << ' ' << lastName
      << " (id " << id << ") called." << endl;
}

Employee::~Employee()
{
   cout << "~Employee() called for " << firstName << ' ' << lastName << endl;
   --count; // 사번(nextId)은 되돌리지 않는다
}

string Employee::getFirstName() const { return firstName; }
string Employee::getLastName() const { return lastName; }
unsigned int Employee::getId() const { return id; }

int main()
{
   cout << "객체 생성 전: count = " << Employee::getCount()
      << ", issued = " << Employee::getIssued() << "\n\n";

   Employee e1( "Susan", "Baker" );

   {
      Employee e2( "Robert", "Jones" );
      Employee e3( "Lisa", "Kim" );
      cout << "블록 안: count = " << Employee::getCount()
         << ", issued = " << Employee::getIssued() << "\n\n";
   } // e3, e2 소멸

   cout << "\n블록 밖: count = " << Employee::getCount()
      << ", issued = " << Employee::getIssued() << "\n\n";

   Employee e4( "Tom", "Lee" );
   cout << "e4의 사번 = " << e4.getId()
      << ", count = " << Employee::getCount()
      << ", issued = " << Employee::getIssued() << "\n\n";
}
