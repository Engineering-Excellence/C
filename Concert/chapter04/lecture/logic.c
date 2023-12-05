// 논리 연산자
#include <stdio.h>

int main(void) {
    int x, y;

    printf("두 개의 정수를 입력하세요.: ");
    scanf("%d %d", &x, &y);

    printf("%d && %d의 결괏값: %d\n", x, y, x && y);    // 논리적인 AND
    printf("%d || %d의 결괏값: %d\n", x, y, x || y);    // 논리적인 OR
    printf("!%d의 결괏값: %d\n", x, !x);                // 논리적인 NOT

    return 0;
}