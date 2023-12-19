/* 2진수 변환 */
#include <stdio.h>

int main(void) {
    int n;
    int digits[64] = {0};

    printf("2진수로 변환할 10진수를 입력하세요.: ");
    scanf("%d", &n);

    for (int i = 63; i >= 0; i--) {
        digits[i] = n % 2;
        n /= 2;
    }

    for (int i = 0; i < 64; ++i) {
        printf("%d", digits[i]);
    }
    printf("\n");

    return 0;
}
