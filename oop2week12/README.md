# 12주차 · 스트림 입출력 — 서식, 오류 상태, 조작자 직접 만들기

Deitel, *C++ How to Program* 10/e, 13장 스트림 입출력 p1~73 (13.2 스트림 계층 ~ 13.8 스트림 오류 상태, `[추가]` 2쪽은 참고)

배포 주소: https://leeyeoninha.github.io/c-plus-programing/oop2week12/

## 구성

| 구역 | 문항 수 | 내용 |
|---|---|---|
| 01 이론 확인 문제 | 4지선다 16문항 | 스트림 계층, char * 출력, put, get/getline, peek/putback/ignore, read/gcount/write, 진법·정밀도·폭, 사용자 정의 조작자, 서식 상태, 오류 상태 |
| 02 진단 | 8문항 (실험형 7 + 설명형 1) | 제공 코드 A(입력 함수·복구), B(서식 조작자·오류 상태 함수)에 한 곳씩 변이를 만들고 기록 |
| 03 실습 | 3문제 (하 1 · 중 1 · 상 1) | 사원 계층(상속·다형성) → 입력 검증·서식 리포트 → 조작자 클래스 |

## 02 진단 하는 법

1. **A 기준선** — `input_diag.cpp`를 바꾸지 않고 실행하고, 파일 첫머리 주석의 다섯 줄을 차례로 입력해 화면 전체를 기준선으로 적습니다.
2. **진단 1~3** — A를 문항마다 한 곳만 바꿔 실행하고, 기준선과 달라진 줄을 기록표 네 칸(바꾼 줄 / 증상 / 원인 / 수정)에 적습니다. 다음 문항 전에 코드를 되돌립니다.
3. **B 기준선과 기준선 상태표** — `format_diag.cpp`를 바꾸지 않고 실행해 `7`, `x`, `12`를 넣고 마지막에 Ctrl+Z 를 누르고 Enter 를 칩니다. 기준선을 적은 뒤, `start`·`read 7`·`read x`·`clear`·`read 12`·`eof` 여섯 줄의 값과 그 이유를 기준선 상태표에 적습니다.
4. **진단 4~7** — 2단계와 같은 방법으로 B를 바꿔 실행하고, 상태 줄은 기준선 상태표와 비교합니다.
5. **진단 8** — 기준선 상태표의 `read x`·`eof` 줄을 근거로 글로 답합니다.

## 03 실습

- **문제 1 [하] 사원 계층** — 추상 기반 클래스 `Employee`와 `Salaried`·`Hourly`·`Commission` 파생 클래스를 만들고, 기반 포인터만으로 출력·합계를 처리합니다. 시작 파일 `src/task1/main.cpp`의 TODO를 채웁니다. 모범 답안 `src/task1/solution/main.cpp`.
- **문제 2 [중] 사원 리포트** — 문제 1의 계층에 가상 `print(ostream&)`와 `operator<<`를 붙이고, 표준 입력을 검증(`peek`·`ignore`·`clear`)하며 서식 표를 출력합니다. 입력 형식은 한 줄에 `S 이름 월급` / `H 이름 시급 시간` / `C 이름 판매액 수수료율`, `#` 주석, `END` 또는 Ctrl+Z 로 끝. 모범 답안 `src/task2/main.cpp`.
- **문제 3 [상] 조작자 클래스** — 추상 클래스 `OutManip`과 `operator<<` 하나로 매개변수 없는 조작자(`Sep`, `ResetFormat`)와 매개변수 있는 조작자(`Line`, `HexId`, `Money` — 기본 인자로 생략 가능), 입력 조작자 `Expect`를 만듭니다. 입력 형식은 `id:pay`, `0` 으로 끝. 모범 답안 `src/task3/Manip.h`, `src/task3/main.cpp`.

## 빌드 환경

- Visual Studio, C++20 (`/std:c++20`). 문제 3은 C++17 이상의 `inline` 변수를 씁니다.
- 헤더 가드는 `#pragma once`.
- 프로그램 출력은 영문(ASCII)만 씁니다. 주석은 한글입니다. 소스 파일의 한글 주석이 깨지면 프로젝트 속성 → C/C++ → 명령줄에 `/utf-8` 을 추가하세요.
- 파일마다 `main`이 있으므로 프로젝트 하나에 한 파일씩 넣어 빌드하세요.
- 콘솔에서 입력의 끝(EOF)은 줄 맨 앞에서 Ctrl+Z 를 누르고 Enter 입니다.

## 파일

```
oop2week12/
  index.html                  학생 페이지 (01 이론 · 02 진단 · 03 실습)
  README.md                   이 문서
  src/
    diagnosis/
      input_diag.cpp          제공 코드 A — get/getline/peek/putback/ignore/read/write/gcount + 복구
      format_diag.cpp         제공 코드 B — 서식 조작자 + 오류 상태 함수(good/eof/fail/bad/rdstate/clear/!/bool)
    task1/                    하 — 사원 계층 (상속·다형성)
      main.cpp                시작 파일 (TODO 1~7)
      solution/main.cpp       모범 답안
    task2/                    중 — 입력 검증 + 서식 리포트 (모범 답안)
      main.cpp
    task3/                    상 — 조작자 클래스 (모범 답안)
      Manip.h
      main.cpp
```
