# C++ 03장 · 포인터와 메모리 구조 — 확인 학습 퀴즈

「Do it! C++」 첫째마당 03장(포인터와 메모리 구조) 학습 확인용 웹페이지입니다.
빌드 도구 없이 순수 HTML/CSS/JS 한 파일(`index.html`)로 되어 있어 GitHub Pages에 바로 올릴 수 있습니다.

- **객관식 10문항** — 포인터와 주소, 역참조, 포인터 크기, 배열과 포인터, 다중 포인터, 구조체, static, const, 레퍼런스
  (채점 시 정답/오답 표시 + 해설 제공)
- **코드 오류 찾기 4문제** — 컴파일 오류·논리 오류·실행 결과 예측 (정답 접기/펼치기)
- **직접 구현 과제 4개** — 포인터 연산 피보나치 / 구조체 정적 배열 + check_age / static 고유 번호 / 레퍼런스 swap·grow_older
  (모범 답안 접기/펼치기)

> ⚠️ 이번 주 학습 범위에서는 **동적 메모리 할당(`new`/`delete`)을 제외**합니다.
> 퀴즈·디버깅·구현 과제 모두 정적 배열 기준으로 구성되어 있습니다.

## 로컬에서 미리보기

별도 서버 없이 `index.html`을 브라우저로 바로 열어서 확인할 수 있습니다.

```bash
open index.html        # macOS
start index.html        # Windows
xdg-open index.html     # Linux
```

## 배포 방법 (택 1)

### 방법 A. GitHub Actions로 자동 배포 (권장)

1. 이 폴더 전체를 새 GitHub 저장소에 push합니다.

   ```bash
   git init
   git add .
   git commit -m "Initial commit: C++ 03장 퀴즈"
   git branch -M main
   git remote add origin https://github.com/<계정명>/<저장소명>.git
   git push -u origin main
   ```

2. GitHub 저장소 페이지에서 **Settings → Pages → Build and deployment → Source**를
   **GitHub Actions**로 설정합니다.
3. `main` 브랜치에 push할 때마다 `.github/workflows/deploy.yml`이 자동으로 실행되어
   `https://<계정명>.github.io/<저장소명>/` 주소에 배포됩니다.

### 방법 B. 스크립트로 수동 배포 (gh-pages 브랜치)

GitHub Actions를 쓰지 않고 바로 배포하고 싶다면:

```bash
chmod +x deploy.sh
./deploy.sh https://github.com/<계정명>/<저장소명>.git
```

이후 저장소 **Settings → Pages**에서 **Source: Deploy from a branch**,
**Branch: gh-pages / (root)**로 지정하면 배포가 완료됩니다.

## 폴더 구조

```
oop2week2/
├── index.html                      # 퀴즈 + 디버깅 + 구현 과제 페이지 (배포 대상)
├── deploy.sh                       # gh-pages 브랜치 수동 배포 스크립트
├── .github/workflows/deploy.yml    # GitHub Actions 자동 배포 워크플로
└── README.md
```

## 문항/문제 수정하기

`index.html` 안의 `<script>` 영역에 있는 `questions`(퀴즈),
`debugProblems`(디버깅 문제) 배열과 과제 1~4 섹션의 HTML만 수정하면
문항을 바꾸거나 추가할 수 있습니다.

- **객관식**: `questions` 배열의 각 항목 — `prompt`(문제), `code`(코드, 없으면 생략),
  `options`(4지선다), `correct`(정답 인덱스, 0부터), `explanation`(해설)
- **디버깅**: `debugProblems` 배열 — `title`, `desc`, `code(문자열 배열)`,
  `highlight(하이라이트할 줄 번호)`, `answer`
- **구현 과제**: `<section id="impl-block">` 안의 `.icard` 블록 — `desc`(문제),
  `cond`(조건), `details`(모범 답안)
