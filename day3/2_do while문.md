# do while문

---

## 1. do while문이란?
- do while문은 조건에 상관없이 코드 블록을 최소 한 번은 실행한 후, 조건을 검사하여 반복 실행 여부를 결정하는 반복문입니다.
- 일반적인 while문과의 차이점은, while문은 조건을 먼저 검사한 후 실행하지만, do while문은 먼저 실행하고 나서 조건을 검사합니다.

---

## 2. 기본 구조
```c
do {
    // 반복 실행할 코드
} while (조건식);
```
- do 블록 안의 코드는 무조건 한 번 실행됩니다.
- 조건식이 참이면 반복, 거짓이면 반복 종료.

---

## 3. 예제 코드
### 1부터 5까지 출력하는 do while문
```c
#include <stdio.h>

int main() {
    int i = 1;
    do {
        printf("%d\n", i);
        i++;
    } while (i <= 5);
    return 0;
}
```

### 예제 2: 비밀번호 맞출 때까지 반복 입력
```c
#include <stdio.h>

int main() {
    int password;
    do {
        printf("비밀번호를 입력하세요: ");
        scanf("%d", &password);
    } while (password != 1234);
    printf("비밀번호가 맞습니다!\n");
    return 0;
}
```

### 예제 3: 메뉴 선택 프로그램
```c
#include <stdio.h>

int main() {
    int menu;
    do {
        printf("1. 저장\n2. 불러오기\n3. 종료\n메뉴를 선택하세요: ");
        scanf("%d", &menu);
        switch(menu) {
            case 1: printf("저장합니다.\n"); break;
            case 2: printf("불러옵니다.\n"); break;
            case 3: printf("프로그램을 종료합니다.\n"); break;
            default: printf("잘못된 선택입니다.\n");
        }
    } while (menu != 3);
    return 0;
}
```

### 예제 4: 1~10까지의 짝수만 출력
```c
#include <stdio.h>

int main() {
    int i = 1;
    do {
        if (i % 2 == 0) {
            printf("%d\n", i);
        }
        i++;
    } while (i <= 10);
    return 0;
}
```

---

## 4. while문과의 차이점
| while문 | do while문 |
|---------|------------|
| 조건을 먼저 검사 | 코드를 먼저 실행 후 조건 검사 |
| 조건이 거짓이면 한 번도 실행 안 됨 | 조건이 거짓이어도 최소 한 번 실행됨 |

### 예시
```c
int i = 10;
while (i < 5) {
    printf("while문 실행\n");
}
// 출력 없음

do {
    printf("do while문 실행\n");
} while (i < 5);
// "do while문 실행" 한 번 출력
```

---

## 5. 활용 예시
- 사용자에게 입력을 반복적으로 받되, 최소 한 번은 입력을 받아야 할 때 유용
- 메뉴 선택, 비밀번호 입력 등

### 예제: 사용자에게 0이 아닌 수를 입력받아 합계 구하기
```c
#include <stdio.h>

int main() {
    int num, sum = 0;
    do {
        printf("숫자를 입력하세요(0 입력시 종료): ");
        scanf("%d", &num);
        sum += num;
    } while (num != 0);
    printf("합계: %d\n", sum);
    return 0;
}
```

---

## 6. 실습문제

1. 아래의 while문 코드를 do while문으로 바꿔보세요.

```c
// 사용자가 100보다 작은 수를 입력할 때마다 입력받은 수를 출력하는 코드
int num;
printf("100보다 작은 수를 입력하세요(100 이상 입력 시 종료): ");
scanf("%d", &num);
while (num < 100) {
    printf("입력한 수: %d\n", num);
    printf("100보다 작은 수를 입력하세요(100 이상 입력 시 종료): ");
    scanf("%d", &num);
}
printf("프로그램 종료\n");
```

---

2. 아래의 do while문 코드를 while문으로 바꿔보세요.

```c
// 1부터 사용자가 입력한 n까지의 홀수만 출력하는 코드
int n, i = 1;
printf("n을 입력하세요: ");
scanf("%d", &n);
do {
    if (i % 2 == 1) {
        printf("%d\n", i);
    }
    i++;
} while (i <= n);
```
