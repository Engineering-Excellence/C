#include <stdio.h>

#define SIZE 5

int main(void) {
    int grade[SIZE];

    printf("5명의 점수를 입력하세요.\n");

    for (int i = 0; i < SIZE; ++i) {
        scanf("%d", &grade[i]); // 배열 원소의 주소를 보내준다.
    }

    for (int i = 0; i < SIZE; ++i) {
        printf("grade[%d]=%d\n", i, grade[i]);
    }

    return 0;
}
