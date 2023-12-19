/* Tic-Tac-Toe */
#include <stdio.h>

#define SIZE 3

int main(void) {
    int x, y, cnt = 0;
    int board[SIZE][SIZE] = {0};

    while (1) {
        // 수평 또는 수직 승리 조건
        for (int i = 0; i < SIZE; ++i) {
            if (((board[i][0] == board[i][1]) && (board[i][1] == board[i][2]) && (board[i][0] != 0))
                || ((board[0][i] == board[1][i]) && (board[1][i] == board[2][i]) && (board[0][i] != 0))) {
                printf("승패를 확인하세요.\n");
                return 0;
            }
        }

        // 대각선 승리조건
        if (((board[0][0] == board[1][1]) && (board[1][1] == board[2][2]) && (board[0][0] != 0))
            || ((board[2][0] == board[1][1]) && (board[1][1] == board[0][2]) && (board[2][0] != 0))) {
            printf("승패를 확인하세요.\n");
            return 0;
        }

        printf("좌표를 공백으로 구분하여 입력하세요(음수 입력시 종료).: ");
        scanf("%d %d", &y, &x);
        if (x < 0 || y < 0) {
            printf("게임을 종료합니다.\n"); // 음수 입력시 종료
        } else if (x >= 0 && x < SIZE && y >= 0 && y < SIZE) {
            if (board[y][x] == 0) {
                board[y][x] = 1 + cnt++ % 2;
            } else {
                printf("이미 돌이 놓인 자리입니다.\n");
            }
        } else {
            printf("잘못 입력하셨습니다.\n");
        }

        // 현황 출력
        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                printf("%d ", board[i][j]);
            }
            printf("\n");
        }

        int res = 1;
        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                res *= board[i][j];
            }
        }
        if (res != 0) {
            printf("필드가 가득 찼습니다.\n");
            return 0;
        }
    }
}
