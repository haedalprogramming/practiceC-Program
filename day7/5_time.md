# time.h 헤더파일

---

## 1. time.h란?

- `time.h`는 C언어에서 시간과 날짜를 처리하기 위한 표준 헤더파일입니다.
- 현재 시간 조회, 시간 계산, 형식 변환 등의 기능을 제공합니다.
- 프로그램 실행 시간 측정, 타이머 기능, 날짜 출력 등에 활용됩니다.
- `time_t`, `clock_t`, `struct tm` 등의 자료형을 제공합니다.

---

## 2. 주요 시간 자료형

### (1) time_t
- 1970년 1월 1일 00:00:00 UTC부터 경과된 초 수
- 시간을 정수로 표현하는 기본 타입

### (2) clock_t  
- 프로그램 실행 시간을 나타내는 타입
- CPU 클록 틱 단위로 측정

### (3) struct tm
- 년, 월, 일, 시, 분, 초 등을 개별적으로 저장하는 구조체

```c
struct tm {
    int tm_sec;    // 초 (0-59)
    int tm_min;    // 분 (0-59)  
    int tm_hour;   // 시 (0-23)
    int tm_mday;   // 일 (1-31)
    int tm_mon;    // 월 (0-11, 0=1월)
    int tm_year;   // 년 (1900년부터의 경과년수)
    int tm_wday;   // 요일 (0-6, 0=일요일)
    int tm_yday;   // 연중 일수 (0-365)
    int tm_isdst;  // 일광절약시간 여부
};
```

---

## 3. 현재 시간 조회

### (1) time() 함수 - 현재 시간 얻기

```c
#include <stdio.h>
#include <time.h>

int main() {
    time_t current_time;
    
    // 현재 시간 얻기
    current_time = time(NULL);
    
    printf("현재 시간 (초): %ld\n", current_time);
    printf("현재 시간: %s", ctime(&current_time));
    
    return 0;
}
```

### (2) localtime() 함수 - 로컬 시간으로 변환

```c
#include <stdio.h>
#include <time.h>

int main() {
    time_t raw_time;
    struct tm* time_info;
    
    time(&raw_time);
    time_info = localtime(&raw_time);
    
    printf("현재 날짜와 시간:\n");
    printf("년: %d\n", time_info->tm_year + 1900);
    printf("월: %d\n", time_info->tm_mon + 1);
    printf("일: %d\n", time_info->tm_mday);
    printf("시: %d\n", time_info->tm_hour);
    printf("분: %d\n", time_info->tm_min);
    printf("초: %d\n", time_info->tm_sec);
    
    // 요일 출력
    char* weekdays[] = {"일", "월", "화", "수", "목", "금", "토"};
    printf("요일: %s요일\n", weekdays[time_info->tm_wday]);
    
    return 0;
}
```

---

## 4. 시간 형식화 출력

### (1) strftime() 함수 - 사용자 정의 형식

```c
#include <stdio.h>
#include <time.h>

int main() {
    time_t raw_time;
    struct tm* time_info;
    char buffer[100];
    
    time(&raw_time);
    time_info = localtime(&raw_time);
    
    // 다양한 형식으로 시간 출력
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", time_info);
    printf("기본 형식: %s\n", buffer);
    
    strftime(buffer, sizeof(buffer), "%Y년 %m월 %d일", time_info);
    printf("한국식 날짜: %s\n", buffer);
    
    strftime(buffer, sizeof(buffer), "%A, %B %d, %Y", time_info);
    printf("영어 형식: %s\n", buffer);
    
    strftime(buffer, sizeof(buffer), "%p %I:%M", time_info);
    printf("12시간 형식: %s\n", buffer);
    
    return 0;
}
```

### (2) 주요 strftime 형식 지정자

| 지정자 | 의미 | 예시 |
|--------|------|------|
| `%Y` | 4자리 년도 | 2024 |
| `%m` | 월 (01-12) | 03 |
| `%d` | 일 (01-31) | 15 |
| `%H` | 시 (00-23) | 14 |
| `%M` | 분 (00-59) | 30 |
| `%S` | 초 (00-59) | 45 |
| `%A` | 요일 (전체) | Monday |
| `%B` | 월 이름 (전체) | March |
| `%p` | AM/PM | PM |

---

## 5. 프로그램 실행 시간 측정

### (1) clock() 함수 사용

```c
#include <stdio.h>
#include <time.h>

// 간단한 계산 함수
long long calculate_sum(int n) {
    long long sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += i;
    }
    return sum;
}

int main() {
    clock_t start, end;
    double cpu_time_used;
    
    printf("1부터 1000000까지의 합 계산...\n");
    
    // 시작 시간 기록
    start = clock();
    
    long long result = calculate_sum(1000000);
    
    // 종료 시간 기록
    end = clock();
    
    // 실행 시간 계산
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    
    printf("결과: %lld\n", result);
    printf("실행 시간: %.6f초\n", cpu_time_used);
    
    return 0;
}
```

### (2) 함수별 성능 비교

```c
#include <stdio.h>
#include <time.h>

// 버블 정렬
void bubble_sort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

// 선택 정렬
void selection_sort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        int min_idx = i;
        for (int j = i+1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

double measure_time(void (*sort_func)(int[], int), int arr[], int n) {
    clock_t start = clock();
    sort_func(arr, n);
    clock_t end = clock();
    return ((double)(end - start)) / CLOCKS_PER_SEC;
}

int main() {
    const int SIZE = 5000;
    int arr1[SIZE], arr2[SIZE];
    
    // 배열 초기화
    srand(time(NULL));
    for (int i = 0; i < SIZE; i++) {
        arr1[i] = arr2[i] = rand() % 1000;
    }
    
    // 버블 정렬 시간 측정
    double bubble_time = measure_time(bubble_sort, arr1, SIZE);
    
    // 선택 정렬 시간 측정  
    double selection_time = measure_time(selection_sort, arr2, SIZE);
    
    printf("정렬 성능 비교 (배열 크기: %d)\n", SIZE);
    printf("버블 정렬: %.6f초\n", bubble_time);
    printf("선택 정렬: %.6f초\n", selection_time);
    
    return 0;
}
```

---

## 6. 실용적인 시간 활용 예제

### (1) 디지털 시계

```c
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void clear_screen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

int main() {
    printf("디지털 시계 (Ctrl+C로 종료)\n\n");
    
    while (1) {
        time_t raw_time;
        struct tm* time_info;
        char time_str[100];
        
        time(&raw_time);
        time_info = localtime(&raw_time);
        
        // 시간 형식화
        strftime(time_str, sizeof(time_str), "%Y-%m-%d %H:%M:%S", time_info);
        
        clear_screen();
        printf("==========================================\n");
        printf("         디지털 시계\n");
        printf("==========================================\n");
        printf("    %s\n", time_str);
        printf("==========================================\n");
        
        // 1초 대기 (Windows에서는 Sleep(1000) 사용 가능)
        clock_t start = clock();
        while (clock() < start + CLOCKS_PER_SEC);
    }
    
    return 0;
}
```

### (2) 타이머 프로그램

```c
#include <stdio.h>
#include <time.h>

int main() {
    int minutes, seconds;
    
    printf("타이머 설정 (분 초): ");
    scanf("%d %d", &minutes, &seconds);
    
    int total_seconds = minutes * 60 + seconds;
    
    printf("\n%d분 %d초 타이머 시작!\n", minutes, seconds);
    
    clock_t start_time = clock();
    
    while (total_seconds > 0) {
        clock_t current_time = clock();
        double elapsed = ((double)(current_time - start_time)) / CLOCKS_PER_SEC;
        
        if (elapsed >= 1.0) {
            total_seconds--;
            int min_left = total_seconds / 60;
            int sec_left = total_seconds % 60;
            
            printf("\r남은 시간: %02d:%02d", min_left, sec_left);
            fflush(stdout);
            
            start_time = current_time;
        }
    }
    
    printf("\n\n⏰ 시간이 다 되었습니다!\n");
    
    return 0;
}
```

### (3) 생일까지 남은 일수 계산

```c
#include <stdio.h>
#include <time.h>

int main() {
    time_t raw_time;
    struct tm* current_time;
    struct tm birthday = {0};
    
    // 현재 시간 획득
    time(&raw_time);
    current_time = localtime(&raw_time);
    
    // 생일 입력
    printf("생일을 입력하세요 (월 일): ");
    scanf("%d %d", &birthday.tm_mon, &birthday.tm_mday);
    
    birthday.tm_mon -= 1;  // 월은 0부터 시작
    birthday.tm_year = current_time->tm_year;  // 올해로 설정
    
    // 만약 생일이 이미 지났다면 내년 생일로 설정
    if (birthday.tm_mon < current_time->tm_mon ||
        (birthday.tm_mon == current_time->tm_mon && 
         birthday.tm_mday < current_time->tm_mday)) {
        birthday.tm_year += 1;
    }
    
    // 날짜를 time_t로 변환
    time_t birthday_time = mktime(&birthday);
    
    // 날짜 차이 계산 (초 단위)
    double diff_seconds = difftime(birthday_time, raw_time);
    int days_left = (int)(diff_seconds / (60 * 60 * 24));
    
    printf("\n생일까지 %d일 남았습니다!\n", days_left);
    
    if (days_left == 0) {
        printf("🎉 오늘이 생일이네요! 축하합니다! 🎂\n");
    }
    
    return 0;
}
```

### (4) 로그 파일 생성

```c
#include <stdio.h>
#include <time.h>
#include <string.h>

void write_log(const char* message) {
    FILE* log_file = fopen("program.log", "a");
    if (log_file == NULL) {
        printf("로그 파일을 열 수 없습니다.\n");
        return;
    }
    
    time_t raw_time;
    struct tm* time_info;
    char time_str[100];
    
    time(&raw_time);
    time_info = localtime(&raw_time);
    strftime(time_str, sizeof(time_str), "%Y-%m-%d %H:%M:%S", time_info);
    
    fprintf(log_file, "[%s] %s\n", time_str, message);
    fclose(log_file);
}

int main() {
    write_log("프로그램 시작");
    
    printf("간단한 계산기 프로그램\n");
    
    int a, b;
    char op;
    
    printf("연산을 입력하세요 (예: 5 + 3): ");
    scanf("%d %c %d", &a, &op, &b);
    
    write_log("사용자 입력 받음");
    
    int result;
    switch (op) {
        case '+':
            result = a + b;
            write_log("덧셈 연산 수행");
            break;
        case '-':
            result = a - b;
            write_log("뺄셈 연산 수행");
            break;
        case '*':
            result = a * b;
            write_log("곱셈 연산 수행");
            break;
        case '/':
            if (b != 0) {
                result = a / b;
                write_log("나눗셈 연산 수행");
            } else {
                printf("0으로 나눌 수 없습니다.\n");
                write_log("오류: 0으로 나누기 시도");
                return 1;
            }
            break;
        default:
            printf("지원하지 않는 연산자입니다.\n");
            write_log("오류: 잘못된 연산자");
            return 1;
    }
    
    printf("결과: %d %c %d = %d\n", a, op, b, result);
    write_log("계산 완료 및 결과 출력");
    write_log("프로그램 종료");
    
    return 0;
}
```

---

## 7. time.h 사용시 주의사항

### (1) 시간대 문제
```c
#include <stdio.h>
#include <time.h>

int main() {
    time_t raw_time;
    time(&raw_time);
    
    // 로컬 시간
    struct tm* local_time = localtime(&raw_time);
    printf("로컬 시간: %s", asctime(local_time));
    
    // UTC 시간
    struct tm* utc_time = gmtime(&raw_time);
    printf("UTC 시간: %s", asctime(utc_time));
    
    return 0;
}
```

### (2) 정밀도 한계
```c
#include <stdio.h>
#include <time.h>

int main() {
    clock_t start = clock();
    
    // 매우 빠른 연산
    int sum = 0;
    for (int i = 0; i < 100; i++) {
        sum += i;
    }
    
    clock_t end = clock();
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    
    printf("실행 시간: %.10f초\n", time_taken);
    printf("클록 해상도가 낮아 0초로 측정될 수 있습니다.\n");
    
    return 0;
}
```

---

## 8. 실습 문제

1. **현재 날짜와 시간을 다양한 형식으로 출력하는 프로그램을 작성해보세요:**
   - YYYY-MM-DD HH:MM:SS 형식
   - "2024년 3월 15일 금요일" 형식
   - 12시간 형식 (AM/PM 포함)

2. **스톱워치 프로그램을 만들어보세요:**
   - 시작/정지 기능
   - 랩 타임 기록 기능
   - 결과를 파일로 저장

3. **두 날짜 사이의 차이를 계산하는 프로그램을 작성해보세요:**
   - 사용자로부터 두 날짜 입력받기
   - 일수 차이 계산하여 출력

4. **알람 프로그램을 만들어보세요:**
   - 특정 시간에 메시지 출력
   - 반복 알람 기능
   - 현재 시간과 알람 시간을 지속적으로 비교 