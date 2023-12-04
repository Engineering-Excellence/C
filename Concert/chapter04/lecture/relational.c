// 관계 연산자
#include <stdio.h>

int main(void) {
    int x, y;

    printf("두 개의 정수를 입력하세요.: ");
    scanf("%d %d", &x, &y);

    printf("x == y의 결괏값: %d\n", x == y);
    printf("x != y의 결괏값: %d\n", x != y);
    printf("x > y의 결괏값: %d\n", x > y);
    printf("x < y의 결괏값: %d\n", x < y);
    printf("x >= y의 결괏값: %d\n", x >= y);
    printf("x <= y의 결괏값: %d\n", x <= y);

    return 0;
}
