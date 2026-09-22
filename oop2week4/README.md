# 4주차 · C++ 09장 클래스 심화와 예외 던지기

Deitel 「C++ How to Program」 10/e 9장 학습 확인용 자료입니다.
학습 범위는 9.12 프렌드 함수·프렌드 클래스까지이며, 강의자료의 [보충] 항목과
상속·다형성의 구현은 확인 범위에서 제외했습니다.

## 구성
- `index.html` — 배포용 단일 페이지
  - 01 이해도 점검 퀴즈 14문항
  - 02 코드 오류 찾기 5문항
  - 03 직접 구현해 보기 3과제 (난이도 하 1 · 중 2)
- `src/` — 실습과제 모범 답안 원본 소스
  - `task1_time_format_exception.cpp` (하) Time 클래스 — std::format 출력과 예외를 던지는 set 함수
  - `task2_composition_employee.cpp` (중) 합성(has-a) — Date를 멤버로 가지는 Employee
  - `task3_friend_order.cpp` (중) 프렌드 함수·프렌드 클래스와 생성자·소멸자 호출 순서

## 다루는 내용
std::format 출력 · 기본 인수를 갖는 생성자와 위임 생성자 · 소멸자 규칙 ·
생성자와 소멸자의 호출 순서(전역 / 자동 지역 / static 지역, exit와 abort) ·
기본 멤버별 대입 · const 객체와 const 멤버 함수 · 합성(composition, has-a) ·
멤버 초기화자 목록과 실행 순서 · 프렌드 함수와 프렌드 클래스 ·
invalid_argument 던지기와 try / catch / what()

## 빌드 환경 (중요)

**`std::format`을 사용하므로 C++20 이상으로 빌드해야 합니다.**

Visual Studio에서 프로젝트 속성을 다음과 같이 설정하세요.

```
프로젝트 속성 → 구성 속성 → C/C++ → 언어
  → C++ 언어 표준 : ISO C++20 표준(/std:c++20)
```

설정하지 않으면 `std::format`을 찾을 수 없다는 컴파일 오류가 발생합니다.
과제별로 소스 파일 하나씩 빈 프로젝트에 추가해 빌드하면 됩니다.

페이지의 모든 실행 예시는 실제로 컴파일·실행한 출력입니다.
