#include <stdio.h>

int main(void) {
    int grade[5];   //  배열 선언

    // 배열 원소에 값을 대입한다.
    grade[0] = 10;
    grade[1] = 20;
    grade[2] = 30;
    grade[3] = 40;
    grade[4] = 50;

    for (int i = 0; i < 5; ++i) {
        printf("grade[%d]=%d\n", i, grade[i]);
    }

    return 0;
}
