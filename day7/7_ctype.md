# ctype.h 헤더파일

---

## 1. ctype.h란?

- **ctype.h**는 C언어에서 문자 분류 및 변환을 위한 표준 헤더파일입니다.
- 문자가 알파벳인지, 숫자인지, 공백인지 등을 판별하는 함수들을 제공합니다.
- 대문자와 소문자 간의 변환 기능도 포함되어 있습니다.
- **문자 하나씩 처리**하며, 매개변수로 **int** 타입을 받습니다.

---

## 2. 문자 분류 함수들

### (1) 기본 문자 분류

```c
#include <stdio.h>
#include <ctype.h>

int main() {
    char test_chars[] = {'A', 'z', '5', ' ', '!', '\n'};
    int count = sizeof(test_chars) / sizeof(test_chars[0]);
    
    printf("문자 분류 테스트:\n");
    printf("문자  알파벳  숫자  공백  출력가능\n");
    printf("--------------------------------\n");
    
    for (int i = 0; i < count; i++) {
        char ch = test_chars[i];
        printf(" %c     %s     %s    %s     %s\n",
               (ch == '\n') ? 'N' : ch,  // 개행문자는 N으로 표시
               isalpha(ch) ? "O" : "X",
               isdigit(ch) ? "O" : "X", 
               isspace(ch) ? "O" : "X",
               isprint(ch) ? "O" : "X");
    }
    
    return 0;
}
```

### (2) 상세 문자 분류

```c
#include <stdio.h>
#include <ctype.h>

void analyze_character(char ch) {
    printf("\n'%c' (ASCII: %d) 분석:\n", ch, ch);
    
    if (isalpha(ch)) {
        printf("- 알파벳입니다\n");
        if (isupper(ch)) printf("- 대문자입니다\n");
        if (islower(ch)) printf("- 소문자입니다\n");
    }
    
    if (isdigit(ch)) printf("- 숫자입니다\n");
    if (isalnum(ch)) printf("- 알파벳 또는 숫자입니다\n");
    if (isspace(ch)) printf("- 공백 문자입니다\n");
    if (ispunct(ch)) printf("- 구두점입니다\n");
    if (isprint(ch)) printf("- 출력 가능한 문자입니다\n");
    if (iscntrl(ch)) printf("- 제어 문자입니다\n");
}

int main() {
    char characters[] = {'A', 'b', '3', ' ', '!', '\t'};
    int count = sizeof(characters) / sizeof(characters[0]);
    
    for (int i = 0; i < count; i++) {
        analyze_character(characters[i]);
    }
    
    return 0;
}
```

---

## 3. 문자 변환 함수들

### (1) 대소문자 변환

```c
#include <stdio.h>
#include <ctype.h>
#include <string.h>

void convert_string_case(char* str) {
    printf("원본: %s\n", str);
    
    // 대문자로 변환
    printf("대문자: ");
    for (int i = 0; str[i] != '\0'; i++) {
        printf("%c", toupper(str[i]));
    }
    printf("\n");
    
    // 소문자로 변환  
    printf("소문자: ");
    for (int i = 0; str[i] != '\0'; i++) {
        printf("%c", tolower(str[i]));
    }
    printf("\n");
}

int main() {
    char text1[] = "Hello World!";
    char text2[] = "C Programming 123";
    char text3[] = "MiXeD CaSe TeXt";
    
    convert_string_case(text1);
    printf("\n");
    convert_string_case(text2);
    printf("\n");
    convert_string_case(text3);
    
    return 0;
}
```

### (2) 문자열 대소문자 변환 (직접 수정)

```c
#include <stdio.h>
#include <ctype.h>
#include <string.h>

void to_uppercase(char* str) {
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = toupper(str[i]);
    }
}

void to_lowercase(char* str) {
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = tolower(str[i]);
    }
}

void capitalize_words(char* str) {
    int capitalize_next = 1;  // 첫 글자는 대문자
    
    for (int i = 0; str[i] != '\0'; i++) {
        if (isspace(str[i])) {
            capitalize_next = 1;
        } else if (capitalize_next && isalpha(str[i])) {
            str[i] = toupper(str[i]);
            capitalize_next = 0;
        } else {
            str[i] = tolower(str[i]);
        }
    }
}

int main() {
    char text1[] = "hello world programming";
    char text2[] = "CONVERT TO lowercase";
    char text3[] = "cApItAlIzE eAcH wOrD";
    
    printf("대문자 변환:\n");
    printf("원본: %s\n", text1);
    to_uppercase(text1);
    printf("결과: %s\n\n", text1);
    
    printf("소문자 변환:\n");
    printf("원본: %s\n", text2);
    to_lowercase(text2);
    printf("결과: %s\n\n", text2);
    
    printf("단어별 첫 글자 대문자:\n");
    printf("원본: %s\n", text3);
    capitalize_words(text3);
    printf("결과: %s\n", text3);
    
    return 0;
}
```

---

## 4. 주요 ctype.h 함수 정리

### (1) 문자 분류 함수

| 함수 | 설명 | 참(True)인 경우 |
|------|------|----------------|
| `isalpha(c)` | 알파벳 여부 | A-Z, a-z |
| `isdigit(c)` | 숫자 여부 | 0-9 |
| `isalnum(c)` | 알파벳 또는 숫자 | A-Z, a-z, 0-9 |
| `islower(c)` | 소문자 여부 | a-z |
| `isupper(c)` | 대문자 여부 | A-Z |
| `isspace(c)` | 공백 여부 | ' ', '\t', '\n', '\r' 등 |
| `ispunct(c)` | 구두점 여부 | !, @, #, $ 등 |
| `isprint(c)` | 출력 가능 문자 | 화면에 출력 가능한 문자 |
| `iscntrl(c)` | 제어 문자 여부 | '\n', '\t', '\0' 등 |

### (2) 문자 변환 함수

| 함수 | 설명 | 변환 결과 |
|------|------|-----------|
| `toupper(c)` | 대문자로 변환 | 소문자 → 대문자, 나머지는 그대로 |
| `tolower(c)` | 소문자로 변환 | 대문자 → 소문자, 나머지는 그대로 |

---

## 5. 실용적인 ctype.h 활용 예제

### (1) 사용자 입력 검증

```c
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int is_valid_name(char* name) {
    if (strlen(name) == 0) return 0;  // 빈 문자열
    
    for (int i = 0; name[i] != '\0'; i++) {
        if (!isalpha(name[i]) && name[i] != ' ') {
            return 0;  // 알파벳과 공백 외의 문자가 있음
        }
    }
    return 1;  // 유효한 이름
}

int is_valid_phone(char* phone) {
    for (int i = 0; phone[i] != '\0'; i++) {
        if (!isdigit(phone[i]) && phone[i] != '-') {
            return 0;  // 숫자와 하이픈 외의 문자가 있음
        }
    }
    return 1;  // 유효한 전화번호
}

int is_valid_email_simple(char* email) {
    int at_count = 0;
    int has_alpha = 0;
    
    for (int i = 0; email[i] != '\0'; i++) {
        if (email[i] == '@') {
            at_count++;
        } else if (isalpha(email[i])) {
            has_alpha = 1;
        } else if (!isalnum(email[i]) && email[i] != '.' && 
                   email[i] != '_' && email[i] != '-') {
            return 0;  // 허용되지 않는 문자
        }
    }
    
    return (at_count == 1 && has_alpha);  // @가 정확히 1개, 알파벳 포함
}

int main() {
    char name[100], phone[100], email[100];
    
    printf("이름을 입력하세요: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';  // 개행문자 제거
    
    if (is_valid_name(name)) {
        printf("유효한 이름입니다.\n");
    } else {
        printf("이름은 알파벳과 공백만 포함해야 합니다.\n");
    }
    
    printf("전화번호를 입력하세요 (예: 010-1234-5678): ");
    scanf("%s", phone);
    
    if (is_valid_phone(phone)) {
        printf("유효한 전화번호 형식입니다.\n");
    } else {
        printf("전화번호는 숫자와 하이픈만 포함해야 합니다.\n");
    }
    
    printf("이메일을 입력하세요: ");
    scanf("%s", email);
    
    if (is_valid_email_simple(email)) {
        printf("유효한 이메일 형식입니다.\n");
    } else {
        printf("유효하지 않은 이메일 형식입니다.\n");
    }
    
    return 0;
}
```

### (2) 문자열 통계 분석

```c
#include <stdio.h>
#include <ctype.h>
#include <string.h>

typedef struct {
    int alphabets;
    int digits;
    int spaces;
    int punctuation;
    int uppercase;
    int lowercase;
    int total;
} CharStats;

CharStats analyze_string(char* str) {
    CharStats stats = {0};
    
    for (int i = 0; str[i] != '\0'; i++) {
        char ch = str[i];
        stats.total++;
        
        if (isalpha(ch)) {
            stats.alphabets++;
            if (isupper(ch)) stats.uppercase++;
            if (islower(ch)) stats.lowercase++;
        }
        if (isdigit(ch)) stats.digits++;
        if (isspace(ch)) stats.spaces++;
        if (ispunct(ch)) stats.punctuation++;
    }
    
    return stats;
}

void print_stats(CharStats stats) {
    printf("\n=== 문자열 통계 ===\n");
    printf("총 문자 수: %d\n", stats.total);
    printf("알파벳: %d개\n", stats.alphabets);
    printf("  - 대문자: %d개\n", stats.uppercase);
    printf("  - 소문자: %d개\n", stats.lowercase);
    printf("숫자: %d개\n", stats.digits);
    printf("공백: %d개\n", stats.spaces);
    printf("구두점: %d개\n", stats.punctuation);
    printf("기타: %d개\n", stats.total - stats.alphabets - 
           stats.digits - stats.spaces - stats.punctuation);
}

int main() {
    char text[] = "Hello World! This is C Programming 123.";
    
    printf("분석할 문자열: %s\n", text);
    
    CharStats stats = analyze_string(text);
    print_stats(stats);
    
    return 0;
}
```

### (3) 비밀번호 강도 검사

```c
#include <stdio.h>
#include <ctype.h>
#include <string.h>

typedef struct {
    int has_upper;
    int has_lower;  
    int has_digit;
    int has_punct;
    int length;
} PasswordCheck;

PasswordCheck check_password(char* password) {
    PasswordCheck check = {0};
    check.length = strlen(password);
    
    for (int i = 0; password[i] != '\0'; i++) {
        char ch = password[i];
        
        if (isupper(ch)) check.has_upper = 1;
        if (islower(ch)) check.has_lower = 1;
        if (isdigit(ch)) check.has_digit = 1;
        if (ispunct(ch)) check.has_punct = 1;
    }
    
    return check;
}

int calculate_strength(PasswordCheck check) {
    int score = 0;
    
    // 길이 점수
    if (check.length >= 8) score += 2;
    else if (check.length >= 6) score += 1;
    
    // 문자 종류 점수
    if (check.has_upper) score += 1;
    if (check.has_lower) score += 1;
    if (check.has_digit) score += 1;
    if (check.has_punct) score += 1;
    
    return score;
}

void print_password_feedback(PasswordCheck check, int strength) {
    printf("\n=== 비밀번호 분석 ===\n");
    printf("길이: %d자\n", check.length);
    printf("대문자 포함: %s\n", check.has_upper ? "O" : "X");
    printf("소문자 포함: %s\n", check.has_lower ? "O" : "X");
    printf("숫자 포함: %s\n", check.has_digit ? "O" : "X");
    printf("특수문자 포함: %s\n", check.has_punct ? "O" : "X");
    
    printf("\n강도: ");
    if (strength >= 6) {
        printf("강함 ⭐⭐⭐\n");
    } else if (strength >= 4) {
        printf("보통 ⭐⭐\n");
    } else {
        printf("약함 ⭐\n");
    }
    
    // 개선 제안
    printf("\n개선 제안:\n");
    if (check.length < 8) printf("- 8자 이상으로 늘리세요\n");
    if (!check.has_upper) printf("- 대문자를 추가하세요\n");
    if (!check.has_lower) printf("- 소문자를 추가하세요\n");
    if (!check.has_digit) printf("- 숫자를 추가하세요\n");
    if (!check.has_punct) printf("- 특수문자(!@#$ 등)를 추가하세요\n");
}

int main() {
    char password[100];
    
    printf("비밀번호를 입력하세요: ");
    scanf("%s", password);
    
    PasswordCheck check = check_password(password);
    int strength = calculate_strength(check);
    
    print_password_feedback(check, strength);
    
    return 0;
}
```

### (4) 단어 정리 도구

```c
#include <stdio.h>
#include <ctype.h>
#include <string.h>

void clean_text(char* text) {
    int write_pos = 0;
    int in_word = 0;
    
    for (int read_pos = 0; text[read_pos] != '\0'; read_pos++) {
        char ch = text[read_pos];
        
        if (isalnum(ch)) {
            text[write_pos++] = tolower(ch);
            in_word = 1;
        } else if (in_word) {
            text[write_pos++] = ' ';
            in_word = 0;
        }
    }
    
    // 마지막 공백 제거
    if (write_pos > 0 && text[write_pos - 1] == ' ') {
        write_pos--;
    }
    
    text[write_pos] = '\0';
}

int count_words(char* text) {
    int count = 0;
    int in_word = 0;
    
    for (int i = 0; text[i] != '\0'; i++) {
        if (isalnum(text[i])) {
            if (!in_word) {
                count++;
                in_word = 1;
            }
        } else {
            in_word = 0;
        }
    }
    
    return count;
}

int main() {
    char text[] = "Hello,  World!!!  This   is  C-Programming  123.";
    
    printf("원본 텍스트: %s\n", text);
    printf("단어 개수: %d개\n\n", count_words(text));
    
    clean_text(text);
    
    printf("정리된 텍스트: %s\n", text);
    printf("정리 후 단어 개수: %d개\n", count_words(text));
    
    return 0;
}
```

---

## 6. ctype.h 사용시 주의사항

### (1) 매개변수 타입 주의

```c
#include <stdio.h>
#include <ctype.h>

int main() {
    // 올바른 사용법
    char ch = 'A';
    printf("isalpha('%c'): %d\n", ch, isalpha(ch));
    
    // 주의: unsigned char를 사용하는 것이 안전
    unsigned char uch = 200;  // 확장 ASCII
    printf("isalpha(%d): %d\n", uch, isalpha(uch));
    
    // 음수 값 주의
    signed char sch = -1;
    printf("isalpha(%d): %d\n", sch, isalpha((unsigned char)sch));
    
    return 0;
}
```

### (2) 로케일 의존성

```c
#include <stdio.h>
#include <ctype.h>
#include <locale.h>

int main() {
    char ch = 'ñ';  // 확장 문자
    
    printf("기본 로케일에서 isalpha('ñ'): %d\n", isalpha(ch));
    
    // 로케일 변경 (시스템에 따라 다를 수 있음)
    setlocale(LC_ALL, "");
    printf("설정된 로케일에서 isalpha('ñ'): %d\n", isalpha(ch));
    
    return 0;
}
```

---

## 7. 실습 문제

1. **문자열에서 각 문자 종류의 개수를 세는 프로그램을 작성해보세요:**
   - 사용자로부터 문자열 입력받기
   - 알파벳, 숫자, 공백, 특수문자 개수 출력

2. **단어의 첫 글자만 대문자로 만드는 함수를 작성해보세요:**
   - 입력: "hello world programming"
   - 출력: "Hello World Programming"

3. **사용자 ID 검증 프로그램을 만들어보세요:**
   - 첫 글자는 반드시 알파벳
   - 나머지는 알파벳, 숫자, 언더스코어만 허용
   - 길이는 3-20자

4. **텍스트에서 숫자만 추출하여 합을 구하는 프로그램을 작성해보세요:**
   - 입력: "abc123def456ghi789"
   - 출력: 123 + 456 + 789 = 1368 