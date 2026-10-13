# 7주차 · C++ 10장 동적 메모리와 Array 클래스

Deitel 「C++ How to Program」 10/e 학습 확인용 자료입니다.
학습 범위는 10장 10.9 동적 메모리 관리 ~ 10.13 explicit 생성자와 변환 연산자까지입니다.
강의자료의 [보충] 항목(Rule of Three / Rule of Five / Rule of Zero)은 확인 범위에서 제외했습니다.

## 구성
- `index.html` — 배포용 단일 페이지
  - 01 이해도 점검 퀴즈 19문항
  - 02 코드 오류 찾기 6문항
  - 03 직접 구현해 보기 3과제 (난이도 중 2 · 상 1)
- `src/` — 실습과제 모범 답안 원본 소스
  - `task1_dynamic_array.cpp` (중) 동적 메모리 할당 기초 — new / new[] / 값 초기화 / delete[]
  - `task2_array_deep_copy.cpp` `task2_array_deep_copy.h` (중) Array 클래스 — 동적 할당과 깊은 복사
  - `task3_array_operators.cpp` `task3_array_operators.h` (상) Array 클래스 완성 — 복사 대입, == / !=, >>, explicit와 static_cast

## 다루는 내용
new / delete, new[] / delete[], 자유 저장 공간(힙) · 값 초기화(new int() vs new int)와
목록 초기화자 · 포인터 기반 배열의 문제점 · Array 클래스 설계 · 복사 생성자와 호출 시점 ·
깊은 복사와 이중 해제 · 복사 대입 연산자의 자기 대입 검사와 return *this ·
operator[] 의 const / 비const 버전과 범위 검사 · operator== / != · << >> 를 비멤버 friend 로 ·
멤버 함수 vs 비멤버 함수 판별 · 변환 생성자와 암시적 변환 · explicit 와 static_cast ·
변환 연산자

## 빌드
Visual Studio에서 과제별로 소스 파일 하나씩 빈 프로젝트에 추가해 빌드하면 됩니다.
과제 2와 3은 헤더 파일(.h)과 소스 파일(.cpp)을 함께 추가하세요.
이번 주 소스는 C++20 전용 기능을 쓰지 않으므로 기본 언어 표준으로도 빌드됩니다.

페이지의 모든 실행 예시는 실제로 컴파일·실행한 출력입니다.
