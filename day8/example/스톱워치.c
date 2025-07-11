#include <stdio.h>
#include <time.h>

// 전역 변수
clock_t start_time = 0;    // 시작 시간
int is_running = 0;        // 0: 정지, 1: 실행중

// 현재 경과 시간을 분:초 형식으로 출력
void show_time(void) {
    if (!is_running && start_time == 0) {
        printf("현재 시간: 00:00");
        return;
    }
    
    clock_t current_time = clock();
    double elapsed = (double)(current_time - start_time) / CLOCKS_PER_SEC;
    
    int minutes = (int)elapsed / 60;
    int seconds = (int)elapsed % 60;
    
    printf("현재 시간: %02d:%02d", minutes, seconds);
}

// 화면 지우기
void clear_screen(void) {
    for (int i = 0; i < 30; i++) {
        printf("\n");
    }
}

// 스톱워치 시작
void start_stopwatch(void) {
    if (is_running) {
        printf("이미 실행 중입니다.\n\n");
    } else {
        start_time = clock();
        is_running = 1;
        printf("스톱워치 시작!\n\n");
    }
}

// 스톱워치 정지
void stop_stopwatch(void) {
    if (!is_running) {
        printf("이미 정지된 상태입니다.\n\n");
    } else {
        is_running = 0;
        
        clock_t current_time = clock();
        double elapsed = (double)(current_time - start_time) / CLOCKS_PER_SEC;
        int minutes = (int)elapsed / 60;
        int seconds = (int)elapsed % 60;
        
        printf("스톱워치 정지! 최종 시간: %02d:%02d\n\n", minutes, seconds);
    }
}

// 스톱워치 리셋
void reset_stopwatch(void) {
    start_time = 0;
    is_running = 0;
    printf("스톱워치 리셋 완료!\n\n");
}

// 메뉴 출력
void print_menu(void) {
    printf("============================\n");
    printf("    [C 스톱워치 프로그램]   \n");
    printf("============================\n");
    
    show_time();
    
    if (is_running) {
        printf(" (실행중)");
    }
    printf("\n\n");
    
    printf("1. 시작\n");
    printf("2. 정지\n");
    printf("3. 리셋\n");
    printf("4. 종료\n\n");
    printf("선택하세요: ");
}

// 메인 함수
int main() {
    int choice;
    
    printf("간단한 스톱워치 프로그램입니다!\n\n");
    
    while (1) {
        clear_screen();
        print_menu();
        
        if (scanf("%d", &choice) != 1) {
            while (getchar() != '\n');
            printf("숫자를 입력하세요.\n");
            printf("계속하려면 Enter를 누르세요...");
            getchar();
            continue;
        }
        
        switch (choice) {
            case 1:
                start_stopwatch();
                break;
            case 2:
                stop_stopwatch();
                break;
            case 3:
                reset_stopwatch();
                break;
            case 4:
                printf("스톱워치를 종료합니다. 안녕히 가세요!\n");
                return 0;
            default:
                printf("1~4 사이의 숫자를 입력하세요.\n\n");
        }
        
        printf("계속하려면 Enter를 누르세요...");
        while (getchar() != '\n');
        getchar();
    }
    
    return 0;
}