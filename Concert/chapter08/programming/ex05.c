/* 각 행과 열의 합계 */
#include <stdio.h>

#define ROWS 3
#define COLS 5

int main(void) {
    int matrix[ROWS][COLS] = {{12, 56, 32, 16, 98},
                                {99, 56, 34, 41, 3},
                                {65, 3,  87, 78, 21}};
    int sum;

    for (int row = 0; row < ROWS; ++row) {
        sum = 0;
        for (int col = 0; col < COLS; ++col) {
            sum += matrix[row][col];
        }
        printf("%d행 합계: %d\n", row + 1, sum);
    }

    printf("\n");

    for (int col = 0; col < COLS; ++col) {
        sum = 0;
        for (int row = 0; row < ROWS; ++row) {
            sum += matrix[row][col];
        }
        printf("%d열 합계: %d\n", col + 1, sum);
    }

    return 0;
}
