/* 소수 찾기 */
#include <stdio.h>

int main(void) {
    int flag;
    printf("2");
    for (int i = 3; i < 100; ++i) {
        flag = 1;
        for (int j = 2; j < i; ++j) {
            if (i % j == 0) {
                flag = 0;
                break;
            }
        }
        if (flag) printf(", %d", i);
    }

    return 0;
}
