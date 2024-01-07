/* 비트 회전 */
#include <stdio.h>
#include "../include/bit_rotate.h"

int main(void) {
    char number[65];
    int direction;
    unsigned int rotations;

    printf("2진수를 입력하세요: ");
    scanf("%s", number);

    printf("회전 비트 수를 입력하세요: ");
    scanf("%u", &rotations);

    printf("회전 방향을 입력하세요 (왼쪽: -1, 오른쪽: 1): ");
    scanf("%d", &direction);

    rotate_bits(number, rotations, direction);

    printf("결과: %s\n", number);

    return 0;
}
