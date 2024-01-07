/* 정수를 비트 형태로 출력 */
#include <stdio.h>

#define GET_BIT(w, k) (((unsigned int) (w) >> (k)) & 0x01)

int main(void) {
//    int num = 2100000000;
    short num = 5; // 비트로 표현하면 0101

    printf("비트 단위 출력은 ");
    for(int i = sizeof(num) * 8 - 1; i >= 0; --i) {
        printf("%u", GET_BIT(num, i));

        if (i % 4 == 0 && i != 0) { // 4비트마다 공백 추가
            printf(" ");
        }
    }
    printf(" 입니다.\n");

    return 0;
}
