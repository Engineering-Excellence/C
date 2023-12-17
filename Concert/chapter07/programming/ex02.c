/* 소수 찾기 함수 */
#include <stdio.h>

void prime(int n) {
    for (int i = 2; i <= n / 2; ++i) {
        if (n % i == 0) return;
    }
    printf("%d\n", n);
}

int main(void) {
    for (int i = 2; i <= 100; ++i) {
        prime(i);
    }

    return 0;
}
