#!/usr/bin/env bash
set -euo pipefail

# ==================================================================
#  C++ 02장(변수와 연산자) 확인 학습 퀴즈 — GitHub Pages 수동 배포 스크립트
# ==================================================================
#  GitHub Actions(.github/workflows/deploy.yml)를 쓰지 않고,
#  gh-pages 브랜치로 직접 push해서 배포하고 싶을 때 사용합니다.
#
#  사용법:
#    ./deploy.sh <GitHub 저장소 URL>
#
#  예시:
#    ./deploy.sh https://github.com/your-id/cpp-quiz.git
#    ./deploy.sh git@github.com:your-id/cpp-quiz.git
# ==================================================================

REPO_URL="${1:-}"
BRANCH="gh-pages"
BUILD_DIR=".deploy-tmp"

if [ -z "$REPO_URL" ]; then
  echo "사용법: ./deploy.sh <GitHub 저장소 URL>"
  echo "예시:   ./deploy.sh https://github.com/your-id/cpp-quiz.git"
  exit 1
fi

if ! command -v git &> /dev/null; then
  echo "오류: git이 설치되어 있지 않습니다."
  exit 1
fi

if [ ! -f "index.html" ]; then
  echo "오류: index.html을 찾을 수 없습니다. 이 스크립트는 프로젝트 루트에서 실행하세요."
  exit 1
fi

echo "1) 배포용 임시 폴더 준비..."
rm -rf "$BUILD_DIR"
mkdir -p "$BUILD_DIR"
cp index.html "$BUILD_DIR/index.html"

echo "2) '$BRANCH' 브랜치로 배포..."
cd "$BUILD_DIR"
git init -q
git checkout -q -b "$BRANCH"
git add index.html
git -c user.name="deploy-bot" -c user.email="deploy-bot@users.noreply.github.com" \
    commit -q -m "Deploy: C++ 02장 변수와 연산자 퀴즈 ($(date +'%Y-%m-%d %H:%M'))"
git remote add origin "$REPO_URL"
git push -f origin "$BRANCH"
cd ..
rm -rf "$BUILD_DIR"

echo ""
echo "배포 완료!"
echo "GitHub 저장소 > Settings > Pages 에서"
echo "  Source: Deploy from a branch"
echo "  Branch: $BRANCH / (root)"
echo "로 설정하면 https://<계정명>.github.io/<저장소명>/ 에서 확인할 수 있습니다."
