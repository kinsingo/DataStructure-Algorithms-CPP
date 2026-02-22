# Build & Run Guide

## Prerequisites

| OS | Required Tools |
|---|---|
| Windows | CMake 3.15+, MSVC (Visual Studio) or MinGW (g++) |
| macOS | CMake 3.15+, Xcode Command Line Tools (`xcode-select --install`) |
| Linux | CMake 3.15+, g++ (`sudo apt install cmake g++`) |

---

## Windows

### MSVC (Visual Studio)

```cmd
:: 빌드 디렉토리 생성 및 이동
mkdir build
cd build

:: CMake 구성 (Visual Studio 기본 제너레이터)
cmake ..

:: 빌드
cmake --build . --config Release

:: 실행
.\Release\main.exe
```

### MinGW (g++)

```cmd
mkdir build
cd build
cmake .. -G "MinGW Makefiles"
cmake --build .
```
---

## Linux & MacOS

```bash
mkdir build && cd build
cmake ..
cmake --build .
./main
```
---

## 빌드 결과물 정리 (전체 OS 공통)

```bash
# Windows
rmdir /s /q build

# macOS / Linux
rm -rf build
```

---

## Tip: 병렬 빌드로 속도 향상

```bash
cmake --build . --parallel
```
