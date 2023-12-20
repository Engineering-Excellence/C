/* 간접 참조(Dereferencing) 연산자 */
#include <stdio.h>

int main(void) {
    int i = 3000;
    int *p; // 포인터의 선언

    p = &i; // 변수 i의 주소를 p에 대입한다.

    printf("i = %d\n", i);  // 변수의 값 출력
    printf("&i = %u\n\n", &i);  // 변수의 주소 출력

    printf("p = %u\n", p);  // 포인터의 값 출력
    printf("*p = %d\n", *p/* 간접 참조 */);    // 포인터를 통한 간접 참조 값 출력

    return 0;
}
