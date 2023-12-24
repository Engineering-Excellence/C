/* 참조에 의한 호출 */
#include <stdio.h>

void swap(int *px, int *py);

int main(void) {
    int a = 100, b = 200;

    printf("swap() 호출 전: a = %d, b = %d\n", a, b);

    swap(&a, &b); // 변수의 주소가 전달된다.

    printf("swap() 호출 후: a = %d, b = %d\n", a, b);

    return 0;
}

void swap(int *px, int *py) {
    int tmp;

    tmp = *px;
    *px = *py;
    *py = tmp;
}
