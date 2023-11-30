// 다항식의 값 계산
#include <stdio.h>
#include <math.h>

int main(void) {

    double x;
    double pn;

    printf("x의 값을 입력하세요: ");
    scanf("%lf", &x);

    pn = 3 * pow(x, 3) - 7 * pow(x, 2) + 9;
    printf("다항식의 값은 %lf입니다.\n", pn);

    return 0;
}