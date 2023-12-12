/* 반복을 이용한 네모 그리기 */
#include <stdio.h>

int main(void) {
    for (int i = 0; i < 7; ++i) {
        if (i == 0 || i == 6)
            printf("**********\n");
        else
            printf("*        *\n");
    }

    return 0;
}
