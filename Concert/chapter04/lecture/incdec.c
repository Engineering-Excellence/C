#include <stdio.h>

int main(void) {
    int x = 0, nextx = 0;
    nextx = ++x;    // 사용되기 전에 증가
    printf("nextx = %d, x = %d\n", nextx, x);

    x = 0;
    nextx = x++;    // 사용된 후에 증가
    printf("nextx = %d, x = %d\n", nextx, x);

    x = 0;
    nextx = --x;
    printf("nextx = %d, x = %d\n", nextx, x);

    x = 0;
    nextx = x--;
    printf("nextx = %d, x = %d\n", nextx, x);

    return 0;
}