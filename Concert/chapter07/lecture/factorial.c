/* 순환적인 팩토리얼 함수 계산 */
#include <stdio.h>

long factorial(int n);

int main(void) {
    int x = 0;
    long f;

    printf("정수를 입력하세요.: ");
    scanf("%d", &x);

    f = factorial(x);
    printf("%d! = %ld\n", x, f);

    return 0;
}

long factorial(int n) {
    printf("factorial(%d)\n", n);

    if (n <= 1) return 1;
    else return n * factorial(n - 1);   // 순환(재귀) 호출
}
