/* 포인터와 배열의 관계 */
#include <stdio.h>

int main(void) {
    int a[] = {10, 20, 30, 40, 50};

    for (int i = 0; i < sizeof(a) / sizeof(a[0]); ++i) {
        printf("&a[%d] = %p\n", i, &a[i]);
    }

    printf("a = %p\n", a);  // 배열의 이름은 배열의 주소를 가리킨다.

    return 0;
}
