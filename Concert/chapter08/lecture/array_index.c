#include <stdio.h>

int main(void) {
    int grade[5];

    for (int i = 0; i < 5; ++i) {
        grade[i] = 10 * i;
    }

    grade[5] = 60;  // 5는 범위를 벗어나는 인덱스이다.

    for (int i = 0; i <= 5; ++i) {
        printf("grade[%d]=%d\n", i, grade[i]);
    }

    return 0;
}
