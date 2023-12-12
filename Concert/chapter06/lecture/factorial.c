/* 반복을 이용한 팩토리얼 구하기 */
#include <stdio.h>

int main(void) {
    long fact = 1;
    int n;

    printf("정수를 입력하세요.: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; ++i) {
        fact *= i;
    }

    printf("%d! = %ld\n", n, fact);

    return 0;
}
