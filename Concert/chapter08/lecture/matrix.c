/* 두 개의 행렬을 더하는 프로그램 */
#include <stdio.h>

#define ROWS 3
#define COLS 3

int main(void) {
    // 행렬을 2차원 배열로 표현
    int A[ROWS][COLS] = {{2, 3, 0},
                         {8, 9, 1},
                         {7, 0, 5}};
    int B[ROWS][COLS] = {{1, 0, 0},
                         {1, 0, 0},
                         {1, 0, 0}};
    int C[ROWS][COLS];

    // 두 개의 행렬을 더한다.
    for (int r = 0; r < ROWS; ++r) {
        for (int c = 0; c < COLS; ++c) {
            C[r][c] = A[r][c] + B[r][c];
        }
    }

    // 행렬을 출력한다.
    for (int r = 0; r < ROWS; ++r) {
        for (int c = 0; c < COLS; ++c) {
            printf("%d ", C[r][c]);
        }
        printf("\n");
    }

    return 0;
}
