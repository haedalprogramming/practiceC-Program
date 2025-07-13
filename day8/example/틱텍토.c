#include <stdio.h>

char board[3][3] = {{'1','2','3'}, {'4','5','6'}, {'7','8','9'}};
int current_player = 1; // 1: X, 2: O

// 함수 원형 선언
void print_board();
int make_move(int position);
int check_win();
int is_board_full();
void reset_board();

// 게임판 출력 함수
void print_board() {
    printf("\n");
    printf(" %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
    printf("-----------\n");
    printf(" %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
    printf("-----------\n");
    printf(" %c | %c | %c \n", board[2][0], board[2][1], board[2][2]);
    printf("\n");
}

// 수 놓기 함수
int make_move(int position) {
    int row = (position - 1) / 3;
    int col = (position - 1) % 3;
    
    if (board[row][col] != 'X' && board[row][col] != 'O') {
        board[row][col] = (current_player == 1) ? 'X' : 'O';
        return 1; // 성공
    }
    return 0; // 실패
}

// 승리 조건 체크 함수
int check_win() {
    // 가로 체크
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return 1;
    }
    
    // 세로 체크
    for (int i = 0; i < 3; i++) {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
            return 1;
    }
    
    // 대각선 체크
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return 1;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return 1;
        
    return 0;
}

// 게임판이 가득 찼는지 체크하는 함수
int is_board_full() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O') {
                return 0; // 아직 빈 칸이 있음
            }
        }
    }
    return 1; // 게임판이 가득 참
}

// 게임판 초기화 함수
void reset_board() {
    char initial_board[3][3] = {{'1','2','3'}, {'4','5','6'}, {'7','8','9'}};
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = initial_board[i][j];
        }
    }
}

// 메인 함수
int main() {
    int position;
    char play_again;
    
    do {
        printf("============================\n");
        printf("     [C 틱텍토 게임]\n");
        printf("----------------------------\n");
        printf(" 1 | 2 | 3 \n");
        printf("-----------\n");
        printf(" 4 | 5 | 6 \n");
        printf("-----------\n");
        printf(" 7 | 8 | 9 \n");
        printf("============================\n");
        
        while (1) {
            print_board();
            
            printf("플레이어 %d(%c) 차례입니다. 위치를 선택하세요 (1-9): ", 
                   current_player, (current_player == 1) ? 'X' : 'O');
            scanf("%d", &position);
            
            if (position < 1 || position > 9) {
                printf("1~9 사이의 숫자를 입력하세요.\n");
                continue;
            }
            
            if (!make_move(position)) {
                printf("이미 선택된 위치입니다. 다른 위치를 선택하세요.\n");
                continue;
            }
            
            if (check_win()) {
                print_board();
                printf("플레이어 %d 승리!\n", current_player);
                break;
            }
            
            if (is_board_full()) {
                print_board();
                printf("무승부!\n");
                break;
            }
            
            current_player = (current_player == 1) ? 2 : 1;
        }
        
        printf("게임을 다시 하시겠습니까? (y/n): ");
        scanf(" %c", &play_again);
        
        if (play_again == 'y' || play_again == 'Y') {
            reset_board();
            current_player = 1;
        }
        
    } while (play_again == 'y' || play_again == 'Y');
    
    printf("게임을 종료합니다. 감사합니다!\n");
    return 0;
} 