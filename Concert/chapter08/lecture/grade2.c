#include <stdio.h>
#include <stdlib.h>

#define SIZE 5  // 배열의 크기를 기호 상수로 표시

int main(void) {
    int grade[SIZE];    // 배열 선언

    for (int i = 0; i < SIZE; ++i) {
        grade[i] = rand() % 100;    // 배열을 0에서 99 사이의 난수로 채운다.
        printf("grade[%d]=%d\n", i, grade[i]);
    }

    return 0;
}
