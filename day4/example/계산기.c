#include <stdio.h>

int main() {
    double a, b, answer;
    char op;
    int quit = 0;

    printf("============================\n");
    printf("   [C 계산기 프로그램]   \n");
    printf("----------------------------\n");
    printf("수식을 입력하세요 (예: 1 + 3)\n");
    printf("0 / 0을 입력하면 프로그램이 종료됩니다.\n");
    printf("============================\n");

    while (!quit) {
        printf("\n>> ");
        int result = scanf("%lf %c %lf", &a, &op, &b);
        if (result == EOF) break;
        if (result != 3) {
            printf("입력 형식이 올바르지 않습니다. 예: 1 + 3\n");
            while (getchar() != '\n' && !feof(stdin));
            continue;
        }
        if (op != '+' && op != '-' && op != '*' && op != '/') {
            printf("잘못된 연산자입니다. +, -, *, / 중 하나를 입력하세요.\n");
            continue;
        }
        // 0 / 0 입력 시 종료
        if (op == '/' && a == 0.0 && b == 0.0) {
            printf("프로그램을 종료합니다.\n");
            break;
        }
        // 0으로 나누기 예외처리
        if (op == '/' && b == 0.0) {
            printf("0으로 나눌 수 없습니다.\n");
            continue;
        }
        switch (op) {
        case '+': answer = a + b; break;
        case '-': answer = a - b; break;
        case '*': answer = a * b; break;
        case '/': answer = a / b; break;
        }
        printf("= %.6g\n", answer);
    }
    return 0;
}
