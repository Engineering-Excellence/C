/* 포인터의 증감 연산 */
#include <stdio.h>

int main(void) {
    int i = 10;
    int *pi = &i;

    printf("i = %d, pi = %p\n", i, pi);

    (*pi)++;    // p가 가리키는 대상의 값을 증가
    printf("i = %d, pi = %p\n", i, pi);

    *pi++;  // p의 주소의 값에서 증가
    printf("i = %d, pi = %p\n", i, pi);

    printf("&i = %p\n", &i); // 실제 주솟값은 변하지 않음!

    return 0;
}
