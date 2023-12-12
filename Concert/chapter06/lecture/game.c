#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    srand(time(0));
    int answer = 1 + rand() % 100;  // 1 ~ 100 사이의 랜덤한 정답 생성
    int tries = 0;
    int guess;

    // 반복 구조
    do {
        printf("정답을 입력하세요.: ");
        scanf("%d", &guess);
        tries++;

        printf("정답보다 %s.\n", guess > answer ? "높습니다" : "낮습니다");
    } while (guess != answer);

    printf("정답입니다! 시도횟수: %d\n", tries);

    return 0;
}
