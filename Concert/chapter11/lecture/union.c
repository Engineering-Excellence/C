/* 공용체 */
#include <stdio.h>

union example { // 공용체 정의
    int i;
    char c;
};

int main(void) {
    union example v;    // 공용체 변수 선언

    v.c = 'A';
    printf("v.c=%c, v.i=%i\n", v.c, v.i);

    v.i = 10000;
    printf("v.c=%c, v.i=%i\n", v.c, v.i);

    return 0;
}
