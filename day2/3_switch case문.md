# C언어의 switch case문

---

## 1. switch문이란?

- **switch문**은 변수의 값에 따라 여러 경우(case) 중 하나를 선택해 실행하는 조건문입니다.
- 주로 값이 정수, 문자 등 "딱 떨어지는 경우"에 따라 분기할 때 사용합니다.
- if-else if문보다 코드가 더 간결하고 읽기 쉬울 때가 많습니다.

---

## 2. switch문의 기본 구조

```c
switch (변수 또는 식) {
    case 값1:
        // 값1일 때 실행
        break;
    case 값2:
        // 값2일 때 실행
        break;
    ...
    default:
        // 위의 어떤 case에도 해당하지 않을 때 실행
}
```

- **switch (식)**: 식의 결과(주로 정수, 문자)에 따라 분기
- **case 값:**: 값이 일치하면 해당 코드 실행
- **break;**: 해당 case 실행 후 switch문을 빠져나감(없으면 아래 case까지 계속 실행됨)
- **default:**: 모든 case에 해당하지 않을 때 실행(생략 가능)

---

## 3. switch문 예제 코드

### (1) 1~3 입력에 따라 다른 메시지 출력

```c
#include <stdio.h>
int main() {
    int num;
    printf("1~3 중 하나를 입력하세요: ");
    scanf("%d", &num);

    switch (num) {
        case 1:
            printf("1을 입력했습니다.\n");
            break;
        case 2:
            printf("2를 입력했습니다.\n");
            break;
        case 3:
            printf("3을 입력했습니다.\n");
            break;
        default:
            printf("1~3이 아닌 값을 입력했습니다.\n");
    }
    return 0;
}
```

### (2) 월(1~12) 입력에 따라 사계절 출력

```c
#include <stdio.h>
int main() {
    int month;
    printf("월(1~12)을 입력하세요: ");
    scanf("%d", &month);

    switch (month) {
        case 3: case 4: case 5:
            printf("봄입니다.\n");
            break;
        case 6: case 7: case 8:
            printf("여름입니다.\n");
            break;
        case 9: case 10: case 11:
            printf("가을입니다.\n");
            break;
        case 12: case 1: case 2:
            printf("겨울입니다.\n");
            break;
        default:
            printf("잘못된 월 입력입니다.\n");
    }
    return 0;
}
```

### (3) 학점(알파벳) 입력에 따라 결과 메시지 출력

```c
#include <stdio.h>
int main() {
    char grade;
    printf("학점(A~D, F)을 입력하세요: ");
    scanf(" %c", &grade);

    switch (grade) {
        case 'A':
            printf("장학금 대상입니다!\n");
            break;
        case 'B':
            printf("합격입니다!\n");
            break;
        case 'C':
            printf("재시험 대상입니다.\n");
            break;
        case 'D':
            printf("불합격입니다.\n");
            break;
        case 'F':
            printf("낙제입니다.\n");
            break;
        default:
            printf("잘못된 학점 입력입니다.\n");
    }
    return 0;
}
```

### (4) 간단한 사칙연산 계산기

```c
#include <stdio.h>
int main() {
    int a, b, result;
    char op;
    printf("두 정수와 연산자(+,-,*,/)를 입력하세요 (예: 3 5 +): ");
    scanf("%d %d %c", &a, &b, &op);

    switch (op) {
        case '+':
            result = a + b;
            printf("%d + %d = %d\n", a, b, result);
            break;
        case '-':
            result = a - b;
            printf("%d - %d = %d\n", a, b, result);
            break;
        case '*':
            result = a * b;
            printf("%d * %d = %d\n", a, b, result);
            break;
        case '/':
            if (b != 0)
                printf("%d / %d = %d\n", a, b, a / b);
            else
                printf("0으로 나눌 수 없습니다.\n");
            break;
        default:
            printf("지원하지 않는 연산자입니다.\n");
    }
    return 0;
}
```

### (5) 정수 입력받아 요일 출력

```c
#include <stdio.h>
int main() {
    int day;
    printf("요일(1~7)을 입력하세요: ");
    scanf("%d", &day);

    switch (day) {
        case 1:
            printf("일요일\n");
            break;
        case 2:
            printf("월요일\n");
            break;
        case 3:
            printf("화요일\n");
            break;
        case 4:
            printf("수요일\n");
            break;
        case 5:
            printf("목요일\n");
            break;
        case 6:
            printf("금요일\n");
            break;
        case 7:
            printf("토요일\n");
            break;
        default:
            printf("잘못된 입력입니다.\n");
    }
    return 0;
}
```

### (6) 메뉴 선택 프로그램

```c
#include <stdio.h>
int main() {
    int menu;
    printf("메뉴를 선택하세요 (1: 저장, 2: 불러오기, 3: 종료): ");
    scanf("%d", &menu);

    switch (menu) {
        case 1:
            printf("저장합니다.\n");
            break;
        case 2:
            printf("불러옵니다.\n");
            break;
        case 3:
            printf("프로그램을 종료합니다.\n");
            break;
        default:
            printf("잘못된 입력입니다.\n");
    }
    return 0;
}
```

### (7) 점수에 따라 등급 출력 (if-else if → switch 변환)

#### if-else if문 버전
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

#### switch문 버전
```c
#include <stdio.h>
int main() {
    int score;
    printf("점수를 입력하세요: ");
    scanf("%d", &score);

    switch (score / 10) {
        case 10: // 100점
        case 9:
            printf("A등급\n");
            break;
        case 8:
            printf("B등급\n");
            break;
        case 7:
            printf("C등급\n");
            break;
        case 6:
            printf("D등급\n");
            break;
        default:
            printf("F등급(불합격)\n");
    }
    return 0;
}
```

---

## 4. switch문 사용시 주의사항

- **case 값은 반드시 상수(리터럴)여야 하며, 변수나 범위(예: case x > 5:)는 사용할 수 없습니다.**
- **break;를 빼먹으면 아래 case까지 계속 실행됩니다(이를 'fall-through'라고 함).**
- **default는 생략 가능하지만, 예외 처리를 위해 넣는 것이 좋습니다.**
- **실수(float, double)나 문자열(char 배열)은 switch문의 case 값으로 쓸 수 없습니다.**
- **if문은 복잡한 조건, 범위, 논리 연산에 적합하고, switch문은 값이 딱 떨어지는 경우에 적합합니다.**

---

## 5. 실습 문제

1. **월(1~12)을 입력받아 계절(봄, 여름, 가을, 겨울)을 출력하는 switch문 코드를 작성해보세요.**
2. **문자 하나를 입력받아 모음(a, e, i, o, u)이면 "모음", 아니면 "자음 또는 기타"를 출력하는 switch문 코드를 작성해보세요.**
3. **아래 if-else if문으로 작성된 코드를 switch문으로 바꿔보세요.**

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
