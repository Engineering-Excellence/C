/* 값에 의한 호출 */
#include <stdio.h>

void swap(int x, int y);

int main(void) {
    int a = 100, b = 200;

    printf("swap() 호출 전: a = %d, b = %d\n", a, b);

    swap(a, b); // 인수가 값으로 전달된다.

    printf("swap() 호출 후: a = %d, b = %d\n", a, b);

    return 0;
}

void swap(int x, int y) {
    int tmp;

    printf("swap() 호출 전: x = %d, y = %d\n", x, y);

    tmp = x;
    x = y;
    y = tmp;

    printf("swap() 호출 후: x = %d, y = %d\n", x, y);
}
