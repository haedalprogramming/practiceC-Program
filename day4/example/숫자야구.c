#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int a, b, c; // 컴퓨터 숫자
    int num, x, y, z; // 사용자 입력 및 자리 분리
    int strike, ball;
    int try = 0;

    // 랜덤 시드 설정
    srand((unsigned int)time(NULL));

    // 1~9 서로 다른 세 자리 수 생성
    do {
        a = rand() % 9 + 1;
        b = rand() % 9 + 1;
        c = rand() % 9 + 1;
    } while (a == b || a == c || b == c);

    printf("============================\n");
    printf("   [C 숫자야구 게임]\n");
    printf("----------------------------\n");
    printf("세 자리 숫자를 입력하세요 (예: 123)\n");
    printf("1~9의 서로 다른 세 자리 수만 입력 가능합니다.\n");
    printf("============================\n");

    while (1) {
        printf("입력: ");
        scanf("%d", &num);

        // 자리 분리
        x = num / 100;
        y = (num / 10) % 10;
        z = num % 10;

        // 입력값 검증
        if (num < 100 || num > 999 || x == y || x == z || y == z || x == 0 || y == 0 || z == 0) {
            printf("잘못된 입력입니다. 1~9의 서로 다른 세 자리 수를 입력하세요.\n");
            continue;
        }

        strike = 0;
        ball = 0;

        // 스트라이크 판정
        if (x == a) strike++;
        if (y == b) strike++;
        if (z == c) strike++;

        // 볼 판정
        if (x == b || x == c) ball++;
        if (y == a || y == c) ball++;
        if (z == a || z == b) ball++;

        printf("%d스트라이크 %d볼\n", strike, ball);
        try++;

        if (strike == 3) {
            printf("정답입니다! 게임을 종료합니다. (시도: %d번)\n", try);
            break;
        }
    }
    return 0;
}
