// 과제1 [하] — main (모범답안)
// VS: EmployeeLib.lib 와 Employee.h 를 이 프로젝트 폴더에 두고 아래 한 줄을 쓴다.
#pragma comment(lib, "EmployeeLib.lib")

#include <iostream>
#include "Employee.h"
#include "SalariedEmployee.h"

int main() {
    SalariedEmployee e("Kim", 3200.0);

    e.print();
    std::cout << "earnings: " << e.earnings() << std::endl;

    // 라이브러리 안 기반 클래스에 virtual 이 선언되어 있으므로 파생 값이 나온다
    Employee* p = &e;
    p->print();
    std::cout << "earnings: " << p->earnings() << std::endl;

    return 0;
}
