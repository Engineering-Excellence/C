/* 복소수 덧셈 */
#include <stdio.h>

struct complex {
    float re;
    float im;
};

int main(void) {
    struct complex complex1, complex2, result;

    printf("첫 번째 복소수를 입력하세요(a, b).: ");
    scanf("%f %f", &complex1.re, &complex1.im);
    printf("두 번째 복소수를 입력하세요(c, d).: ");
    scanf("%f %f", &complex2.re, &complex2.im);

    result.re = complex1.re + complex2.re;
    result.im = complex1.im + complex2.im;

    printf("복소수의 합은 %.f+%.fi입니다.\n", result.re, result.im);

    return 0;
}
