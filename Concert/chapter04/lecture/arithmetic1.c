#include <stdio.h>

int main(void) {
    double x, y, result;

    printf("두 개의 실수를 입력하세요.: ");
    scanf("%lf %lf", &x, &y);

    result = x + y; // 덧셈 연산을 해서 결과를 result에 대입
    printf("%f + %f = %f\n", x, y, result);

    result = x - y; // 뺄셈 연산
    printf("%f - %f = %f\n", x, y, result);

    result = x * y; // 곱셈 연산
    printf("%f * %f = %f\n", x, y, result);

    result = x / y; // 나눗셈 연산
    printf("%f / %f = %f\n", x, y, result);

    return 0;
}
