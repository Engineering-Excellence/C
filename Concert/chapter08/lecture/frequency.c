#include <stdio.h>

#define SIZE 101

int main(void) {
    int freq[SIZE]; // 배열 선언
    int score;

    for (int i = 0; i < SIZE; ++i) {
        freq[i] = 0;    // 배열 원소 초기화
    }

    while (1) {
        printf("숫자를 입력하세요(종료 -1): ");
        scanf("%d", &score);
        if (score < 0 || score > 100) break;
        freq[score]++;
    }

    printf(" 값    빈도\n");

    for (int i = 0; i < SIZE; ++i) {
        printf("%3d   %3d\n", i, freq[i]);
    }

    return 0;
}
