# C++ 객체지향 프로그래밍 · 주차별 확인 학습

인하대학교 C++ 객체지향 프로그래밍 강의의 주차별 학생 확인 학습 자료입니다.
빌드 도구 없이 순수 HTML/CSS/JS로 되어 있어 GitHub Pages에 그대로 올라갑니다.

공개 주소: https://leeyeoninha.github.io/c-plus-programing/

## 구조

```
/
├── index.html          ← 전체 주차 목차 (새로 추가)
├── oop2week1/          ← 1주차 · 02장 변수와 연산자 (기존 루트 index.html을 이동)
├── oop2week2/          ← 2주차 · 03장 포인터와 메모리 구조
├── oop2week3/          ← 3주차 · 06장 클래스와 객체
│   ├── index.html
│   └── src/            모범 답안 소스
└── oop2week4/          ← 4주차 · 09장 클래스 심화와 예외 던지기
    ├── index.html
    └── src/            모범 답안 소스
```

각 주차 페이지는 세 파트로 구성됩니다.

- **01 이해도 점검 퀴즈** — 객관식. 채점 후 문항별 정답·해설 표시
- **02 코드 오류 찾기** — 컴파일 오류·실행 결과 예측. 정답 접기/펼치기
- **03 직접 구현해 보기** — 조건·실행 예시·모범 답안

## 주차별 범위

| 주차 | 장 | 주요 내용 |
|------|-----|-----------|
| 1주차 | Do it! C++ 02장 | 표준 입출력, 데이터 형식과 변수, 연산자, 유효 범위 |
| 2주차 | Do it! C++ 03장 | 포인터와 메모리 주소, 배열과 포인터, 구조체, static·const, 레퍼런스 |
| 3주차 | Do it! C++ 06장 / C++ How to Program 06장 | 객체지향 4대 특징, 클래스와 인스턴스, struct→class, 접근 지정자, 생성자·소멸자, 인터페이스와 구현 분리 |
| 4주차 | C++ How to Program 09장 | std::format, 생성·소멸 호출 순서, 합성(has-a), const 객체·const 멤버 함수, friend, 예외 던지기 |

## 빌드 환경

실습과제는 Visual Studio에서 빈 프로젝트를 만들고 소스 파일을 추가해 빌드합니다.

**4주차는 `std::format`을 사용하므로 C++20 이상이 필요합니다.**
프로젝트 속성 → C/C++ → 언어 → C++ 언어 표준 → `ISO C++20 표준(/std:c++20)` 으로 설정하세요.

## 로컬에서 미리보기

목차 페이지의 주차 링크가 동작하려면 폴더 단위로 열어야 합니다.

```bash
cd c-plus-programing
python -m http.server 8000
```

그다음 브라우저에서 `http://localhost:8000/` 을 엽니다.

## 배포

`main` 브랜치에 push하면 `.github/workflows/deploy.yml`이 저장소 루트 전체를 GitHub Pages로 자동 배포합니다. 별도 명령은 필요하지 않습니다.

```bash
git add .
git commit -m "..."
git push origin main
```

저장소 Actions 탭에서 「Deploy quiz to GitHub Pages」가 완료되면 1~2분 내에 반영됩니다.

## 교재

- 이지스퍼블리싱 「Do it! C++」
- Deitel 「C++ How to Program」 10/e
