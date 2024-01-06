/* 다중 소스 파일 */
#include <stdio.h>
#include "../include/power.h"

int main(void) {
    int x, y;

    printf("x의 값을 입력하세요.: ");
    scanf("%d", &x);
    printf("y의 값을 입력하세요.: ");
    scanf("%d", &y);

    printf("%d의 %d 제곱값은 %.2f\n", x, y, power(x, y));

    return 0;
}
