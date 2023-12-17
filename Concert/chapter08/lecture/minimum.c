/* 최저 성적 찾기 */
#include <stdio.h>

#define SIZE 5

int main(void) {
    int grade[SIZE];
    int min;

    for (int i = 0; i < SIZE; ++i) {
        printf("성적을 입력하세요.: ");
        scanf("%d", &grade[i]);
    }

    min = grade[0]; // 일단 최솟값을 grade[0]라고 가정한다.

    for (int i = 0; i < SIZE; ++i) {
        if (grade[i] < min) {
            min = grade[i]; // 더 작은 값이 발견되면 그 값을 min으로 옮긴다.
        }
    }

    printf("최솟값은 %d입니다.\n", min);

    return 0;
}
