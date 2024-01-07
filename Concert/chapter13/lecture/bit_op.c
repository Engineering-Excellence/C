/* 비트 AND, OR, XOR, NOT */
#include <stdio.h>

int main(void) {
    int x = 9;
    int y = 10;

    printf("비트 AND = %08X\n", x & y);   // 1000
    printf("비트 OR = %08X\n", x | y);   // 1011
    printf("비트 XOR = %08X\n", x ^ y);   // 0011
    printf("비트 NOT = %08X\n", ~x);   // 0110

    return 0;
}
