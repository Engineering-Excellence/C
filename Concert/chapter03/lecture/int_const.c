#include <stdio.h>

int main(void) {

    int x = 10; // 10은 10진수이고 십진수로 10이다.
    int y = 010;    // 010은 8진수이고 십진수로 8이다.
    int z = 0x10;   // 010은 16진수이고 십진수로 16이다.

    printf("x_10 = %d\n", x);
    printf("y_10 = %d\n", y);
    printf("y_8 = %o\n", y);
    printf("z_10 = %d\n", z);
    printf("z_16 = %x\n", z);

    return 0;
}
