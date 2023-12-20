/* 변수의 주소를 포인터에 저장하여 포인터의 값을 변경 */
#include <stdio.h>

int main(void) {
    int x = 10, y = 20;
    int *p;

    p = &x; // p는 x를 가리킨다.
    printf("p = %p\n", p);
    printf("*p = %d\n", *p);

    p = &y; // p는 y를 가리킨다.
    printf("p = %p\n", p);
    printf("*p = %d\n", *p);

    return 0;
}
