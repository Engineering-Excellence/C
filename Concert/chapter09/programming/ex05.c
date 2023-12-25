/* 사칙연산 */
#include <stdio.h>

extern double add(double x, double y);

extern double sub(double x, double y);

extern double mul(double x, double y);

extern double div(double x, double y);

extern double (*pf[4])(double x, double y);


int main(void) {
    int menu, a, b;

    printf("=================================\n");
    printf("0. 덧셈\n");
    printf("1. 뺄셈\n");
    printf("2. 곱셈\n");
    printf("3. 나눗셈\n");
    printf("=================================\n");

    printf("메뉴를 선택하세요.: ");
    scanf("%d", &menu);
    printf("두 개의 정수를 공백으로 구분해서 입력하세요.: ");
    scanf("%d %d", &a, &b);

    printf("연산의 값은 %.f입니다.\n", (*pf[menu])(a, b));

    return 0;
}
