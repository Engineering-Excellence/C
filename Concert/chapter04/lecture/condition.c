// 조건 연산자 프로그램
#include <stdio.h>

int main(void) {
    int x, y;

    printf("첫 번째 수 = ");
    scanf("%d", &x);
    printf("두 번째 수 = ");
    scanf("%d", &y);

    printf("큰 수 = %d\n", x > y ? x : y);
    printf("작은 수 = %d\n", x < y ? x : y);

    return 0;
}