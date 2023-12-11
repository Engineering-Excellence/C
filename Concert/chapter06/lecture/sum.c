#include <stdio.h>

int main(void) {
    int sum = 0;
    int i = 0;

//    sum = 1000 * 1001 / 2;

    while (i++ < 1000) {
        sum += i;
    }

    printf("합은 %d입니다.\n", sum);

    return 0;
}
