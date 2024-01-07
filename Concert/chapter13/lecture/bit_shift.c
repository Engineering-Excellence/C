/* 비트 이동 연산자(<<, >>) */
#include <stdio.h>

int main(void) {
    int x = 9;  // 1001

    printf("비트 << = %08X\n", x << 2);   // 100100
    printf("비트 >> = %08X\n", x >> 2);   // 000010

    return 0;
}
