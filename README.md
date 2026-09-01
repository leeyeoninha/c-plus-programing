# C++ 02장 · 변수와 연산자 — 확인 학습 퀴즈

「Do it! C++」 첫째마당 02장(변수와 연산자) 학습 확인용 웹페이지입니다.
빌드 도구 없이 순수 HTML/CSS/JS 한 파일(`index.html`)로 되어 있어 GitHub Pages에 바로 올릴 수 있습니다.

- 8문항 객관식 퀴즈 (채점 시 정답/오답 표시 + 해설 제공)
- 컴파일 오류·데이터 유실·실행 결과 예측 등 코드 디버깅 문제 4개 (정답 접기/펼치기)

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
   git commit -m "Initial commit: C++ 02장 퀴즈"
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
cpp-quiz/
├── index.html                      # 퀴즈 + 디버깅 문제 페이지 (배포 대상)
├── deploy.sh                       # gh-pages 브랜치 수동 배포 스크립트
├── .github/workflows/deploy.yml    # GitHub Actions 자동 배포 워크플로
└── README.md
```

## 문항/문제 수정하기

`index.html` 안의 `<script>` 영역에 있는 `questions`(퀴즈)와
`debugProblems`(디버깅 문제) 배열 값만 수정하면 문항을 바꾸거나 추가할 수 있습니다.
