# oop2week3 — C++ 06장 · 클래스와 객체 확인 학습

인하대 객체지향 프로그래밍 3주차 학생 배포물입니다.

## 구성
- `index.html` — 배포용 단일 페이지 (01 이해도 점검 퀴즈 10문항 / 02 코드 오류 찾기 4문항 / 03 직접 구현해 보기 5과제)
- `src/` — 실습과제 모범 답안 원본 소스
  - `task1_struct_time.cpp` (하) struct Time — 멤버 직접 접근의 위험
  - `task2_class_time.cpp` (중) class Time — 캡슐화와 유효성 검사
  - `task3_member_access.cpp` (중) 객체 이름 · 레퍼런스 · 포인터로 멤버 접근
  - `task4_create_destroy.cpp` (중) 생성자와 소멸자의 호출 순서
  - `task5/` (상) 인터페이스와 구현 분리 — time2.h / time2.cpp / main.cpp

## 강의자료 범위
- Do it! C++ 06장 — 프로그래밍 패러다임, 객체지향 4대 특징, 클래스와 인스턴스
- C++ How to Program 6장 — struct/class, 멤버 접근, 접근 지정자, 생성자·소멸자, 인터페이스와 구현 분리

상속·가상 함수·다형성의 구현과 동적 메모리 할당(new/delete)은 이번 주 범위에서 제외했습니다.

## 컴파일 확인
```
g++ -std=c++17 src/task1_struct_time.cpp -o t1
g++ -std=c++17 src/task2_class_time.cpp -o t2
g++ -std=c++17 src/task3_member_access.cpp -o t3
g++ -std=c++17 src/task4_create_destroy.cpp -o t4
g++ -std=c++17 src/task5/main.cpp src/task5/time2.cpp -o t5
```
페이지의 모든 실행 예시는 위 명령으로 실제 실행한 출력입니다.
