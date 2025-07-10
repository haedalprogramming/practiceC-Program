# math.h 헤더파일

---

## 1. math.h란?

- **math.h**는 C언어에서 수학 계산을 위한 표준 헤더파일입니다.
- 삼각함수, 지수함수, 로그함수, 제곱근 등 다양한 수학 함수들을 제공합니다.
- 대부분의 함수는 **double** 타입을 사용하여 정밀한 계산을 지원합니다.
- 컴파일 시 **-lm** 옵션을 추가해야 합니다 (Linux/Unix 환경).

---

## 2. 컴파일 방법

math.h를 사용하는 프로그램은 다음과 같이 컴파일합니다:

```bash
# Linux/Unix/Mac
gcc program.c -lm -o program

# Windows (MinGW)
gcc program.c -lm -o program.exe

# Visual Studio (Windows)는 -lm 옵션 불필요
```

---

## 3. 기본 수학 함수들

### (1) 제곱근과 거듭제곱

```c
#include <stdio.h>
#include <math.h>

int main() {
    double x = 16.0;
    double y = 2.0;
    double z = 3.0;
    
    // 제곱근
    printf("√%.1f = %.3f\n", x, sqrt(x));
    
    // 거듭제곱
    printf("%.1f^%.1f = %.3f\n", y, z, pow(y, z));
    
    // 절댓값
    printf("|%.1f| = %.1f\n", -5.7, fabs(-5.7));
    
    // 올림, 내림, 반올림
    double num = 3.7;
    printf("%.1f -> 올림: %.0f, 내림: %.0f, 반올림: %.0f\n", 
           num, ceil(num), floor(num), round(num));
    
    return 0;
}
```

### (2) 삼각함수

```c
#include <stdio.h>
#include <math.h>

int main() {
    double angle_deg = 45.0;  // 각도 (도)
    double angle_rad = angle_deg * M_PI / 180.0;  // 라디안으로 변환
    
    printf("각도: %.1f도 (%.3f 라디안)\n", angle_deg, angle_rad);
    
    // 삼각함수 (라디안 단위)
    printf("sin(%.1f°) = %.3f\n", angle_deg, sin(angle_rad));
    printf("cos(%.1f°) = %.3f\n", angle_deg, cos(angle_rad));
    printf("tan(%.1f°) = %.3f\n", angle_deg, tan(angle_rad));
    
    // 역삼각함수 (결과는 라디안)
    double sin_val = 0.707;
    double asin_result = asin(sin_val) * 180.0 / M_PI;  // 도로 변환
    printf("arcsin(%.3f) = %.1f도\n", sin_val, asin_result);
    
    return 0;
}
```

### (3) 지수함수와 로그함수

```c
#include <stdio.h>
#include <math.h>

int main() {
    double x = 2.0;
    
    // 지수함수
    printf("e^%.1f = %.3f\n", x, exp(x));  // 자연지수
    printf("2^%.1f = %.3f\n", x, pow(2, x));  // 임의 밑 지수
    
    // 로그함수
    printf("ln(%.1f) = %.3f\n", x, log(x));    // 자연로그
    printf("log10(%.1f) = %.3f\n", x, log10(x));  // 상용로그 (밑이 10)
    printf("log2(%.1f) = %.3f\n", x, log2(x));   // 이진로그 (밑이 2)
    
    // 상수들
    printf("π = %.6f\n", M_PI);
    printf("e = %.6f\n", M_E);
    
    return 0;
}
```

---

## 4. 주요 수학 상수들

math.h에서 제공하는 유용한 상수들:

```c
#include <stdio.h>
#include <math.h>

int main() {
    printf("수학 상수들:\n");
    printf("π (파이) = %.10f\n", M_PI);
    printf("e (자연상수) = %.10f\n", M_E);
    printf("ln(2) = %.10f\n", M_LN2);
    printf("ln(10) = %.10f\n", M_LN10);
    printf("log10(e) = %.10f\n", M_LOG10E);
    printf("log2(e) = %.10f\n", M_LOG2E);
    printf("√2 = %.10f\n", M_SQRT2);
    printf("1/√2 = %.10f\n", M_SQRT1_2);
    
    return 0;
}
```

---

## 5. 실용적인 math.h 활용 예제

### (1) 원의 넓이와 둘레 계산기

```c
#include <stdio.h>
#include <math.h>

double circle_area(double radius) {
    return M_PI * radius * radius;
}

double circle_circumference(double radius) {
    return 2 * M_PI * radius;
}

int main() {
    double radius;
    
    printf("원의 반지름을 입력하세요: ");
    scanf("%lf", &radius);
    
    if (radius <= 0) {
        printf("반지름은 양수여야 합니다.\n");
        return 1;
    }
    
    printf("\n=== 원의 정보 ===\n");
    printf("반지름: %.2f\n", radius);
    printf("넓이: %.2f\n", circle_area(radius));
    printf("둘레: %.2f\n", circle_circumference(radius));
    
    return 0;
}
```

### (2) 이차방정식 해 구하기

```c
#include <stdio.h>
#include <math.h>

void solve_quadratic(double a, double b, double c) {
    if (a == 0) {
        printf("이차방정식이 아닙니다 (a = 0).\n");
        return;
    }
    
    double discriminant = b * b - 4 * a * c;
    
    printf("방정식: %.2fx² + %.2fx + %.2f = 0\n", a, b, c);
    printf("판별식: %.2f\n", discriminant);
    
    if (discriminant > 0) {
        double x1 = (-b + sqrt(discriminant)) / (2 * a);
        double x2 = (-b - sqrt(discriminant)) / (2 * a);
        printf("서로 다른 두 실근: x₁ = %.3f, x₂ = %.3f\n", x1, x2);
    } else if (discriminant == 0) {
        double x = -b / (2 * a);
        printf("중근: x = %.3f\n", x);
    } else {
        double real_part = -b / (2 * a);
        double imaginary_part = sqrt(-discriminant) / (2 * a);
        printf("복소수 해: x = %.3f ± %.3fi\n", real_part, imaginary_part);
    }
}

int main() {
    double a, b, c;
    
    printf("이차방정식 ax² + bx + c = 0의 계수를 입력하세요\n");
    printf("a, b, c: ");
    scanf("%lf %lf %lf", &a, &b, &c);
    
    solve_quadratic(a, b, c);
    
    return 0;
}
```

### (3) 두 점 사이의 거리 계산

```c
#include <stdio.h>
#include <math.h>

typedef struct {
    double x;
    double y;
} Point;

double distance(Point p1, Point p2) {
    double dx = p2.x - p1.x;
    double dy = p2.y - p1.y;
    return sqrt(dx * dx + dy * dy);
}

double angle_between_points(Point p1, Point p2) {
    double dx = p2.x - p1.x;
    double dy = p2.y - p1.y;
    return atan2(dy, dx) * 180.0 / M_PI;  // 각도를 도로 변환
}

int main() {
    Point p1, p2;
    
    printf("첫 번째 점의 좌표 (x y): ");
    scanf("%lf %lf", &p1.x, &p1.y);
    
    printf("두 번째 점의 좌표 (x y): ");
    scanf("%lf %lf", &p2.x, &p2.y);
    
    double dist = distance(p1, p2);
    double angle = angle_between_points(p1, p2);
    
    printf("\n=== 두 점 사이의 관계 ===\n");
    printf("점1: (%.2f, %.2f)\n", p1.x, p1.y);
    printf("점2: (%.2f, %.2f)\n", p2.x, p2.y);
    printf("거리: %.3f\n", dist);
    printf("각도: %.1f도\n", angle);
    
    return 0;
}
```

### (4) 과학 계산기

```c
#include <stdio.h>
#include <math.h>
#include <string.h>

void print_menu() {
    printf("\n=== 과학 계산기 ===\n");
    printf("1. 제곱근\n");
    printf("2. 거듭제곱\n");
    printf("3. 삼각함수 (sin, cos, tan)\n");
    printf("4. 로그함수 (ln, log10)\n");
    printf("5. 팩토리얼\n");
    printf("0. 종료\n");
    printf("선택: ");
}

double factorial(int n) {
    if (n <= 1) return 1.0;
    return n * factorial(n - 1);
}

int main() {
    int choice;
    double num, base, exponent, angle;
    
    while (1) {
        print_menu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("수를 입력하세요: ");
                scanf("%lf", &num);
                if (num >= 0) {
                    printf("√%.3f = %.6f\n", num, sqrt(num));
                } else {
                    printf("음수의 제곱근은 계산할 수 없습니다.\n");
                }
                break;
                
            case 2:
                printf("밑과 지수를 입력하세요 (밑 지수): ");
                scanf("%lf %lf", &base, &exponent);
                printf("%.3f^%.3f = %.6f\n", base, exponent, pow(base, exponent));
                break;
                
            case 3:
                printf("각도를 입력하세요 (도): ");
                scanf("%lf", &angle);
                double rad = angle * M_PI / 180.0;
                printf("sin(%.1f°) = %.6f\n", angle, sin(rad));
                printf("cos(%.1f°) = %.6f\n", angle, cos(rad));
                printf("tan(%.1f°) = %.6f\n", angle, tan(rad));
                break;
                
            case 4:
                printf("수를 입력하세요 (양수): ");
                scanf("%lf", &num);
                if (num > 0) {
                    printf("ln(%.3f) = %.6f\n", num, log(num));
                    printf("log10(%.3f) = %.6f\n", num, log10(num));
                } else {
                    printf("양수를 입력해야 합니다.\n");
                }
                break;
                
            case 5:
                int n;
                printf("정수를 입력하세요 (0-20): ");
                scanf("%d", &n);
                if (n >= 0 && n <= 20) {
                    printf("%d! = %.0f\n", n, factorial(n));
                } else {
                    printf("0 이상 20 이하의 수를 입력하세요.\n");
                }
                break;
                
            case 0:
                printf("계산기를 종료합니다.\n");
                return 0;
                
            default:
                printf("잘못된 선택입니다.\n");
        }
    }
    
    return 0;
}
```

### (5) 통계 계산 (평균, 표준편차)

```c
#include <stdio.h>
#include <math.h>

double calculate_mean(double data[], int n) {
    double sum = 0.0;
    for (int i = 0; i < n; i++) {
        sum += data[i];
    }
    return sum / n;
}

double calculate_variance(double data[], int n, double mean) {
    double sum_squared_diff = 0.0;
    for (int i = 0; i < n; i++) {
        double diff = data[i] - mean;
        sum_squared_diff += diff * diff;
    }
    return sum_squared_diff / n;
}

double calculate_std_deviation(double variance) {
    return sqrt(variance);
}

int main() {
    int n;
    
    printf("데이터 개수를 입력하세요: ");
    scanf("%d", &n);
    
    if (n <= 0) {
        printf("잘못된 데이터 개수입니다.\n");
        return 1;
    }
    
    double data[n];
    
    printf("%d개의 데이터를 입력하세요:\n", n);
    for (int i = 0; i < n; i++) {
        printf("데이터 %d: ", i + 1);
        scanf("%lf", &data[i]);
    }
    
    double mean = calculate_mean(data, n);
    double variance = calculate_variance(data, n, mean);
    double std_dev = calculate_std_deviation(variance);
    
    printf("\n=== 통계 결과 ===\n");
    printf("데이터 개수: %d\n", n);
    printf("평균: %.3f\n", mean);
    printf("분산: %.3f\n", variance);
    printf("표준편차: %.3f\n", std_dev);
    
    // 최댓값과 최솟값
    double max = data[0], min = data[0];
    for (int i = 1; i < n; i++) {
        if (data[i] > max) max = data[i];
        if (data[i] < min) min = data[i];
    }
    
    printf("최댓값: %.3f\n", max);
    printf("최솟값: %.3f\n", min);
    printf("범위: %.3f\n", max - min);
    
    return 0;
}
```

---

## 6. 주요 math.h 함수 정리

| 함수 | 설명 | 예시 |
|------|------|------|
| `sqrt(x)` | 제곱근 | `sqrt(16.0)` → 4.0 |
| `pow(x, y)` | x의 y제곱 | `pow(2, 3)` → 8.0 |
| `fabs(x)` | 절댓값 | `fabs(-5.5)` → 5.5 |
| `ceil(x)` | 올림 | `ceil(3.2)` → 4.0 |
| `floor(x)` | 내림 | `floor(3.8)` → 3.0 |
| `round(x)` | 반올림 | `round(3.6)` → 4.0 |
| `sin(x)` | 사인 (라디안) | `sin(M_PI/2)` → 1.0 |
| `cos(x)` | 코사인 (라디안) | `cos(0)` → 1.0 |
| `tan(x)` | 탄젠트 (라디안) | `tan(M_PI/4)` → 1.0 |
| `exp(x)` | e의 x제곱 | `exp(1)` → 2.718... |
| `log(x)` | 자연로그 | `log(M_E)` → 1.0 |
| `log10(x)` | 상용로그 | `log10(100)` → 2.0 |

---

## 7. math.h 사용시 주의사항

### (1) 라디안과 도 변환

```c
#include <stdio.h>
#include <math.h>

// 도를 라디안으로 변환
double deg_to_rad(double degrees) {
    return degrees * M_PI / 180.0;
}

// 라디안을 도로 변환
double rad_to_deg(double radians) {
    return radians * 180.0 / M_PI;
}

int main() {
    double angle_deg = 45.0;
    double angle_rad = deg_to_rad(angle_deg);
    
    printf("%.0f도 = %.3f라디안\n", angle_deg, angle_rad);
    printf("sin(%.0f도) = %.3f\n", angle_deg, sin(angle_rad));
    
    return 0;
}
```

### (2) 정밀도 문제

```c
#include <stdio.h>
#include <math.h>

int main() {
    double x = 0.1;
    double result = pow(x, 2);
    
    printf("0.1² = %.20f\n", result);
    printf("정확히 0.01인가? %s\n", (result == 0.01) ? "Yes" : "No");
    
    // 부동소수점 비교시 주의
    if (fabs(result - 0.01) < 1e-10) {
        printf("충분히 가깝습니다.\n");
    }
    
    return 0;
}
```

---

## 8. 실습 문제

1. **삼각형의 넓이를 계산하는 프로그램을 작성해보세요:**
   - 세 변의 길이를 입력받아 헤론의 공식 사용
   - 공식: 넓이 = √(s(s-a)(s-b)(s-c)), s = (a+b+c)/2

2. **복리 계산기를 만들어보세요:**
   - 원금, 이자율, 기간을 입력받기
   - 공식: 최종금액 = 원금 × (1 + 이자율)^기간

3. **간단한 물리 계산기를 만들어보세요:**
   - 자유낙하 시간과 거리 계산
   - 포물선 운동 계산
   - 원주율을 이용한 원운동 계산

4. **수학 함수 그래프 데이터를 생성하는 프로그램을 작성해보세요:**
   - sin, cos 함수의 x, y 값을 파일로 저장
   - 0도부터 360도까지 10도 간격으로 계산 