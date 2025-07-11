# string.h 헤더파일

---

## 1. string.h란?

- `string.h`는 C언어에서 문자열 처리를 위한 표준 헤더파일입니다.
- 문자열 복사, 비교, 연결, 검색 등의 다양한 함수들을 제공합니다.
- C언어에서는 문자열이 문자 배열로 표현되므로, 이를 쉽게 다루기 위한 함수들이 포함되어 있습니다.
- `null 종료 문자열('\0')`을 기준으로 동작합니다.

---

## 2. 주요 문자열 함수들

### (1) 문자열 길이 - strlen()

문자열의 길이를 반환합니다 (null 문자 제외).

```c
#include <stdio.h>
#include <string.h>

int main() {
    char str1[] = "Hello";
    char str2[] = "Hello World";
    char str3[] = "안녕하세요";
    
    printf("'%s'의 길이: %lu\n", str1, strlen(str1));
    printf("'%s'의 길이: %lu\n", str2, strlen(str2));
    printf("'%s'의 길이: %lu\n", str3, strlen(str3));
    
    return 0;
}
```

### (2) 문자열 복사 - strcpy(), strncpy()

```c
#include <stdio.h>
#include <string.h>

int main() {
    char source[] = "Hello World";
    char dest1[20];
    char dest2[20];
    
    // strcpy - 전체 문자열 복사
    strcpy(dest1, source);
    printf("복사된 문자열: %s\n", dest1);
    
    // strncpy - 지정한 개수만큼 복사
    strncpy(dest2, source, 5);
    dest2[5] = '\0';  // null 문자 추가
    printf("부분 복사: %s\n", dest2);
    
    return 0;
}
```

### (3) 문자열 연결 - strcat(), strncat()

```c
#include <stdio.h>
#include <string.h>

int main() {
    char str1[50] = "Hello";
    char str2[] = " World";
    char str3[] = "!!!";
    
    // strcat - 문자열 연결
    strcat(str1, str2);
    printf("연결 후: %s\n", str1);
    
    // strncat - 지정한 개수만큼 연결
    strncat(str1, str3, 2);
    printf("부분 연결 후: %s\n", str1);
    
    return 0;
}
```

### (4) 문자열 비교 - strcmp(), strncmp()

```c
#include <stdio.h>
#include <string.h>

int main() {
    char str1[] = "Apple";
    char str2[] = "Banana";
    char str3[] = "Apple";
    
    // strcmp - 전체 문자열 비교
    int result1 = strcmp(str1, str2);
    int result2 = strcmp(str1, str3);
    
    printf("%s vs %s: %d\n", str1, str2, result1);  // 음수
    printf("%s vs %s: %d\n", str1, str3, result2);  // 0
    
    if (strcmp(str1, str3) == 0) {
        printf("%s와 %s는 같습니다.\n", str1, str3);
    }
    
    // strncmp - 지정한 개수만큼 비교
    char str4[] = "Application";
    int result3 = strncmp(str1, str4, 3);
    printf("첫 3글자 비교: %d\n", result3);  // 0 (App == App)
    
    return 0;
}
```

---

## 3. 문자열 검색 함수들

### (1) 문자 검색 - strchr(), strrchr()

```c
#include <stdio.h>
#include <string.h>

int main() {
    char text[] = "Hello World Programming";
    char ch = 'o';
    
    // strchr - 첫 번째 문자 위치
    char* first = strchr(text, ch);
    if (first != NULL) {
        printf("첫 번째 '%c'의 위치: %ld\n", ch, first - text);
    }
    
    // strrchr - 마지막 문자 위치
    char* last = strrchr(text, ch);
    if (last != NULL) {
        printf("마지막 '%c'의 위치: %ld\n", ch, last - text);
    }
    
    return 0;
}
```

### (2) 문자열 검색 - strstr()

```c
#include <stdio.h>
#include <string.h>

int main() {
    char text[] = "C Programming is fun and Programming is useful";
    char pattern[] = "Programming";
    
    // strstr - 부분 문자열 검색
    char* found = strstr(text, pattern);
    if (found != NULL) {
        printf("'%s' 발견 위치: %ld\n", pattern, found - text);
        printf("발견된 부분: %s\n", found);
    }
    
    // 모든 위치 찾기
    char* current = text;
    int count = 0;
    while ((current = strstr(current, pattern)) != NULL) {
        count++;
        printf("%d번째 발견 위치: %ld\n", count, current - text);
        current++;  // 다음 검색을 위해 포인터 이동
    }
    
    return 0;
}
```

---

## 4. 문자열 토큰화 - strtok()

문자열을 구분자로 나누어 토큰으로 분리합니다.

```c
#include <stdio.h>
#include <string.h>

int main() {
    char sentence[] = "apple,banana,orange,grape";
    char delim[] = ",";
    
    printf("원본 문자열: %s\n", sentence);
    printf("토큰들:\n");
    
    // 첫 번째 토큰
    char* token = strtok(sentence, delim);
    int count = 1;
    
    while (token != NULL) {
        printf("%d. %s\n", count++, token);
        token = strtok(NULL, delim);  // 다음 토큰
    }
    
    return 0;
}
```

### 공백으로 구분된 단어 분리 예제

```c
#include <stdio.h>
#include <string.h>

int main() {
    char sentence[] = "C Programming is very interesting";
    char delim[] = " ";
    
    printf("문장: %s\n", sentence);
    printf("단어들:\n");
    
    char* word = strtok(sentence, delim);
    while (word != NULL) {
        printf("- %s\n", word);
        word = strtok(NULL, delim);
    }
    
    return 0;
}
```

---

## 5. 메모리 관련 함수들

### (1) 메모리 복사 - memcpy(), memmove()

```c
#include <stdio.h>
#include <string.h>

int main() {
    char source[] = "Hello World";
    char dest1[20];
    char dest2[20];
    
    // memcpy - 메모리 복사
    memcpy(dest1, source, strlen(source) + 1);
    printf("memcpy 결과: %s\n", dest1);
    
    // memmove - 겹치는 메모리 영역도 안전하게 복사
    char text[] = "Hello World";
    memmove(text + 2, text, 5);  // 앞의 5글자를 2칸 뒤로 이동
    printf("memmove 결과: %s\n", text);
    
    return 0;
}
```

### (2) 메모리 설정 - memset()

```c
#include <stdio.h>
#include <string.h>

int main() {
    char buffer[20];
    
    // 메모리를 특정 값으로 초기화
    memset(buffer, 'A', 10);
    buffer[10] = '\0';
    printf("memset 결과: %s\n", buffer);
    
    // 배열 전체를 0으로 초기화
    int numbers[10];
    memset(numbers, 0, sizeof(numbers));
    
    printf("초기화된 배열: ");
    for (int i = 0; i < 10; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");
    
    return 0;
}
```

---

## 6. 실용적인 string.h 활용 예제

### (1) 문자열 뒤집기

```c
#include <stdio.h>
#include <string.h>

void reverse_string(char* str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - 1 - i];
        str[len - 1 - i] = temp;
    }
}

int main() {
    char text[] = "Hello World";
    printf("원본: %s\n", text);
    
    reverse_string(text);
    printf("뒤집기: %s\n", text);
    
    return 0;
}
```

### (2) 단어 개수 세기

```c
#include <stdio.h>
#include <string.h>

int count_words(char* sentence) {
    if (strlen(sentence) == 0) return 0;
    
    char temp[1000];
    strcpy(temp, sentence);  // 원본 보존
    
    int count = 0;
    char* word = strtok(temp, " \t\n");
    while (word != NULL) {
        count++;
        word = strtok(NULL, " \t\n");
    }
    
    return count;
}

int main() {
    char sentence[] = "C Programming is very interesting and useful";
    
    printf("문장: %s\n", sentence);
    printf("단어 개수: %d개\n", count_words(sentence));
    
    return 0;
}
```

### (3) 간단한 문자열 검증

```c
#include <stdio.h>
#include <string.h>

int is_palindrome(char* str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        if (str[i] != str[len - 1 - i]) {
            return 0;  // 회문이 아님
        }
    }
    return 1;  // 회문임
}

int main() {
    char words[][20] = {"level", "hello", "radar", "world", "madam"};
    int count = sizeof(words) / sizeof(words[0]);
    
    printf("회문 검사:\n");
    for (int i = 0; i < count; i++) {
        if (is_palindrome(words[i])) {
            printf("'%s' - 회문입니다.\n", words[i]);
        } else {
            printf("'%s' - 회문이 아닙니다.\n", words[i]);
        }
    }
    
    return 0;
}
```

### (4) 문자열 정리 (공백 제거)

```c
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void trim_string(char* str) {
    int len = strlen(str);
    
    // 뒤쪽 공백 제거
    while (len > 0 && isspace(str[len - 1])) {
        str[--len] = '\0';
    }
    
    // 앞쪽 공백 제거
    int start = 0;
    while (str[start] && isspace(str[start])) {
        start++;
    }
    
    if (start > 0) {
        memmove(str, str + start, len - start + 1);
    }
}

int main() {
    char text[] = "   Hello World   ";
    
    printf("원본: '%s'\n", text);
    trim_string(text);
    printf("정리 후: '%s'\n", text);
    
    return 0;
}
```

---

## 7. string.h 사용시 주의사항

### (1) 버퍼 오버플로우 주의

```c
#include <stdio.h>
#include <string.h>

int main() {
    char small_buffer[5];
    char large_string[] = "This is a very long string";
    
    // 위험! 버퍼 오버플로우 발생 가능
    // strcpy(small_buffer, large_string);
    
    // 안전한 방법
    strncpy(small_buffer, large_string, sizeof(small_buffer) - 1);
    small_buffer[sizeof(small_buffer) - 1] = '\0';
    
    printf("안전한 복사: %s\n", small_buffer);
    
    return 0;
}
```

### (2) strtok 사용시 주의점

```c
#include <stdio.h>
#include <string.h>

int main() {
    char original[] = "apple,banana,orange";
    char copy[50];
    
    // strtok은 원본 문자열을 수정함
    strcpy(copy, original);
    
    printf("원본: %s\n", original);
    
    char* token = strtok(copy, ",");
    while (token != NULL) {
        printf("토큰: %s\n", token);
        token = strtok(NULL, ",");
    }
    
    printf("원본 유지: %s\n", original);
    printf("수정된 복사본: %s\n", copy);  // 수정됨
    
    return 0;
}
```

---

## 8. 실습 문제

1. **사용자로부터 문자열을 입력받아 다음을 수행하는 프로그램을 작성해보세요:**
   - 문자열 길이 출력
   - 특정 문자의 개수 세기
   - 문자열 뒤집어서 출력

2. **두 개의 문자열을 입력받아 다음을 수행하는 프로그램을 작성해보세요:**
   - 두 문자열이 같은지 비교
   - 첫 번째 문자열에 두 번째 문자열 연결
   - 첫 번째 문자열에서 두 번째 문자열 검색

3. **쉼표로 구분된 문자열을 입력받아 각 단어를 분리하여 출력하는 프로그램을 작성해보세요.**
   - 예: "apple,banana,orange" → apple, banana, orange

4. **문자열이 회문(팰린드롬)인지 확인하는 함수를 작성하고 테스트해보세요.**
   - 대소문자 구분하지 않고 검사
   - 공백은 무시하고 검사 