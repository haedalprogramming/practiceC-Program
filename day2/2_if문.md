# C언어의 if문

---

## 1. if문이란?

- **if문**은 프로그램에서 "조건"에 따라 실행할 코드를 선택할 때 사용하는 **조건문**입니다.
- 예를 들어, "점수가 60점 이상이면 합격, 아니면 불합격"처럼 상황에 따라 다르게 동작하게 만들 수 있습니다.

---

## 2. if문의 기본 구조

```c
if (조건식) {
    // 조건식이 참(1)이면 실행되는 코드
}
```

- **조건식**: 참(1) 또는 거짓(0)이 되는 식(예: `a > 10`, `score == 100`)
- **중괄호 { }**: 조건이 참일 때 실행할 여러 줄의 코드를 묶어줍니다. 한 줄만 쓸 때는 생략 가능하지만, 초보자는 항상 { }를 쓰는 습관을 들이세요!

---

## 3. if-else문

- 조건이 참일 때와 거짓일 때 각각 다른 코드를 실행하고 싶을 때 사용합니다.

```c
if (조건식) {
    // 조건식이 참(1)일 때 실행
} else {
    // 조건식이 거짓(0)일 때 실행
}
```

---

## 4. if-else if-else문

- 여러 조건 중 하나를 선택해서 실행할 때 사용합니다.

```c
if (조건1) {
    // 조건1이 참일 때 실행
} else if (조건2) {
    // 조건1은 거짓이고, 조건2가 참일 때 실행
} else {
    // 위의 모든 조건이 거짓일 때 실행
}
```

---

## 5. 다양한 if문 예제 코드

### (1) 점수가 60점 이상이면 "합격" 출력

```c
#include <stdio.h>
int main() {
    int score;
    printf("점수를 입력하세요: ");
    scanf("%d", &score);

    if (score >= 60) {
        printf("합격입니다!\n");
    }
    return 0;
}
```

### (2) 짝수/홀수 판별

```c
#include <stdio.h>
int main() {
    int num;
    printf("정수를 입력하세요: ");
    scanf("%d", &num);

    if (num % 2 == 0) {
        printf("짝수입니다.\n");
    } else {
        printf("홀수입니다.\n");
    }
    return 0;
}
```

### (3) 세 개의 수 중 가장 큰 값 찾기

```c
#include <stdio.h>
int main() {
    int a, b, c;
    printf("세 정수를 입력하세요: ");
    scanf("%d %d %d", &a, &b, &c);

    int max = a;
    if (b > max) {
        max = b;
    }
    if (c > max) {
        max = c;
    }
    printf("가장 큰 값: %d\n", max);
    return 0;
}
```

### (4) 중첩 if문: 점수에 따라 등급 출력

```c
#include <stdio.h>
int main() {
    int score;
    printf("점수를 입력하세요: ");
    scanf("%d", &score);

    if (score >= 90) {
        printf("A등급\n");
    } else if (score >= 80) {
        printf("B등급\n");
    } else if (score >= 70) {
        printf("C등급\n");
    } else if (score >= 60) {
        printf("D등급\n");
    } else {
        printf("F등급(불합격)\n");
    }
    return 0;
}
```

### (5) 문자 입력받아 대/소문자 판별

```c
#include <stdio.h>
int main() {
    char ch;
    printf("영문자 한 글자를 입력하세요: ");
    scanf(" %c", &ch); // 공백 추가로 버퍼 문제 방지

    if (ch >= 'A' && ch <= 'Z') {
        printf("대문자입니다.\n");
    } else if (ch >= 'a' && ch <= 'z') {
        printf("소문자입니다.\n");
    } else {
        printf("영문자가 아닙니다.\n");
    }
    return 0;
}
```

### (6) 문자열 비교 (strcmp 함수 사용)

```c
#include <stdio.h>
#include <string.h>
int main() {
    char pw[20];
    printf("비밀번호를 입력하세요: ");
    scanf("%s", pw);

    if (strcmp(pw, "1234") == 0) {
        printf("비밀번호 일치!\n");
    } else {
        printf("비밀번호 불일치!\n");
    }
    return 0;
}
```

### (7) 실수 비교 (주의점)

```c
#include <stdio.h>
int main() {
    float a, b;
    printf("두 실수를 입력하세요: ");
    scanf("%f %f", &a, &b);

    if (a == b) {
        printf("두 수가 정확히 같습니다.\n");
    } else if (a > b) {
        printf("첫 번째 수가 더 큽니다.\n");
    } else {
        printf("두 번째 수가 더 큽니다.\n");
    }
    return 0;
}
```

### (8) 입력값에 따라 분기: 메뉴 선택

```c
#include <stdio.h>
int main() {
    int menu;
    printf("메뉴를 선택하세요 (1: 저장, 2: 불러오기, 3: 종료): ");
    scanf("%d", &menu);

    if (menu == 1) {
        printf("저장합니다.\n");
    } else if (menu == 2) {
        printf("불러옵니다.\n");
    } else if (menu == 3) {
        printf("프로그램을 종료합니다.\n");
    } else {
        printf("잘못된 입력입니다.\n");
    }
    return 0;
}
```

---

## 6. if문 사용시 주의사항

- **조건식은 반드시 괄호 ( )로 감싸야 합니다.**
- **중괄호 { }는 항상 쓰는 습관을 들이세요.** (실수 방지)
- **조건식에 = (대입)과 == (비교)를 혼동하지 않기!**
  - `if (a = 10)` (X) → 대입, 항상 참
  - `if (a == 10)` (O) → 비교
- **여러 조건을 동시에 검사할 때는 논리 연산자(&&, ||)를 사용하세요.**
- **else if, else는 if문과 붙여서 사용해야 합니다.**

---

## 7. 실습 문제

1. **정수를 입력받아 0보다 크면 "양수", 0이면 "0", 0보다 작으면 "음수"를 출력하는 코드를 작성해보세요.**
2. **두 정수를 입력받아, 두 수가 모두 10 이상이면 "두 수 모두 10 이상", 아니면 "10 미만이 있습니다"를 출력해보세요.**
3. **세 정수를 입력받아, 모두 같으면 "모두 같습니다", 아니면 "모두 같지 않습니다"를 출력해보세요.**
4. **나이를 입력받아 20세 이상이면 "성인", 아니면 "미성년자"를 출력하는 코드를 작성해보세요.**
5. **문자열을 입력받아 "hello"면 "인사", "bye"면 "작별", 그 외에는 "모름"을 출력하는 코드를 작성해보세요.**
6. **실수를 입력받아 0.0 이상 1.0 이하이면 "범위 내", 아니면 "범위 밖"을 출력하는 코드를 작성해보세요.**

