/* 배열 원소의 개수를 계산하는 방법 */
#include <stdio.h>

int main(void) {
    int grade[] = {1, 2, 3, 4, 5, 6};
    int size;

    size = sizeof(grade) / sizeof(grade[0]);    // 배열 크기를 계산한다.

    for (int i = 0; i < size; ++i) {
        printf("grade[%d] = %d\n", i, grade[i]);
    }

    return 0;
}
