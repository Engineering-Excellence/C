#include <stdio.h>

//#define DEBUG

int average(int x, int y);

int main(void) {
    printf("평균: %d\n", average(3, 5));

    return 0;
}

int average(int x, int y) {
#ifdef DEBUG
    printf("x=%d, y=%d\n", x, y);   // DEBUG 주석 처리시 컴파일에 포함되지 않음
#endif
    return (x + y) / 2;
}
