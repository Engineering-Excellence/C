/* 모든 양의 약수를 구하는 함수 */
#include <stdio.h>

void get_divisor(int n) {
    for (int i = 1; i <= n / 2; ++i) {
        if (n % i == 0) printf("%d\n", i);
    }
    printf("%d\n", n);
}

int main(void) {
    int n;

    printf("약수를 찾을 정수를 입력하세요.: ");
    scanf("%d", &n);

    get_divisor(n);

    return 0;
}
