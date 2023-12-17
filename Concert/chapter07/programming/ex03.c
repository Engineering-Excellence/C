/* 거듭제곱 계산 함수 */
#include <stdio.h>

int ipower(int n, int k) {
    int res = 1;
    for (int i = 0; i < k; ++i) {
        res *= n;
    }
    return res;
}

int main(void) {
    for (int i = 0; i <= 10; ++i) {
        printf("3^%d = %d\n", i, ipower(3, i));
    }

    return 0;
}
