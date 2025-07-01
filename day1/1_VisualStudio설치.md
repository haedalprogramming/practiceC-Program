# Chapter 1. Visual Studio 설치와 Hello World 출력

## 1. Visual Studio 설치하기

1. **Visual Studio 다운로드**
   - [Visual Studio 공식 홈페이지](https://visualstudio.microsoft.com/ko/downloads/)에 접속합니다.
   - "무료 다운로드" 버튼을 클릭하여 "Community" 버전을 다운로드합니다.
   ![visual studio 다운로드 페이지](image.png)

2. **설치 프로그램 실행**
   - 다운로드한 설치 파일을 실행합니다.
   - "C++를 사용한 데스크톱 개발" 워크로드를 선택합니다. (C언어도 C++ 워크로드에 포함되어 있습니다)
      ![alt text](image-1.png)
   - "설치" 버튼을 눌러 설치를 진행합니다.
   

3. **설치 완료 후 Visual Studio 실행**
   - 설치가 완료되면 Visual Studio를 실행합니다.
   ![alt text](image-2.png)
---

## 2. 새 프로젝트 만들기

1. **새 프로젝트 생성**
   - Visual Studio를 실행한 후, "새 프로젝트 만들기"를 클릭합니다.
   - "빈 프로젝트(Empty Project)"를 선택한 후 "다음"을 클릭합니다.
      ![alt text](image-3.png)

2. **솔루션 및 프로젝트 이름 지정**
   - 솔루션 이름을 입력합니다(예: clang)
   - 프로젝트 이름을 입력합니다(예: helloWorld).
   - 저장 위치를 지정한 후 "만들기"를 클릭합니다.
      ![alt text](image-4.png)

3. **C 소스 파일 추가**
   - 솔루션 탐색기에서 "소스 파일" 폴더를 마우스 오른쪽 버튼으로 클릭 → "추가" → "새 항목"을 선택합니다.
      ![alt text](image-5.png)
   - "C++ 파일(.cpp)"이 기본으로 보이지만, 파일 이름을 반드시 `.c`로 끝나게 입력하세요. (예: `main.c`)
   ![alt text](image-6.png)
   - "추가"를 클릭합니다.

---

## 3. Hello World 코드 작성

1. **기본 코드 작성**
   - 생성한 `main.c` 파일에 아래와 같이 코드를 작성합니다.

```c
#include <stdio.h>

int main() {
    printf("Hello, World!\n");
    return 0;
}
```

2. **코드 저장**
   - Ctrl + S를 눌러 코드를 저장합니다.

---

## 4. 프로그램 빌드 및 실행

1. **빌드**
   - 상단 메뉴에서 "디버그" → "디버깅하지 않고 시작(Ctrl+F5)"을 클릭합니다.

2. **실행 결과 확인**
   - 콘솔 창에 `Hello, World!`가 출력되는지 확인합니다.
   ![alt text](image-7.png)
---

## 5. 마무리

- 이제 Visual Studio에서 C언어로 첫 번째 프로그램을 성공적으로 실행했습니다!
- 다음 장에서는 변수와 자료형에 대해 배워봅시다.