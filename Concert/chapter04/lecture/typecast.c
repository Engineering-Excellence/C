#include <stdio.h>

int main(void) {
    int i;
    double f;

    f = 5 / 4;  // 정수 간 연산 결과는 정수
    printf("%f\n", f);

    f = (double) 5 / 4;
    printf("%f\n", f);

    f = 5 / (double) 4;
    printf("%f\n", f);

    f = (double) 5 / (double) 4;
    printf("%f\n", f);

    i = 1.3 + 1.8;
    printf("%d\n", i);

    i = (int) 1.3 + (int) 1.8;
    printf("%d\n", i);

    return 0;
}