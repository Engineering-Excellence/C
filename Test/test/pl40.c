#include <stdio.h>

void main() {
    int x = 0x15213F10 >> 4;    // 16진수 자리당 4비트이므로, 오른쪽으로 한 자리 쉬프트 -> x = 0x15213F1
    char y = (char) x;  // char는 8비트이므로, 최하위 8비트만 추출 -> y = 0xF1 = 11110001 = -15
    unsigned char z = (unsigned char) x;    // MSB를 부호가 아닌 숫자로 취급 -> z = 11110001 = 241
    printf("%d, %u", y, z);
}
