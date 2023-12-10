/* 이차방정식의 근을 구하는 프로그램 */
#include <stdio.h>
#include <math.h>

int main(void) {
    double x, a, b, c, D;

    printf("이차방정식의 계수 a, b, c를 공백으로 구분하여 순서대로 입력하세요(a ≠ 0).: ");
    scanf("%lf %lf %lf", &a, &b, &c);

    if (a == 0) {
        printf("잘못된 입력입니다.\n");
        return 1;
    }

    D = pow(b, 2) - 4 * a * c;

    if (D > 0) {
        printf("x = %lf 또는 x = %lf\n", (-b + sqrt(D)) / (2 * a), (-b - sqrt(D)) / (2 * a));
    } else if (D < 0) {
        printf("x = %lf ± %lfi\n", -b / (2 * a), sqrt(-D) / (2 * a));
    } else {
        printf("x = %lf\n", -b / (2 * a));
    }

    return 0;
}
