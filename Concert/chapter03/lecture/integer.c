/* 정수형 자료형의 크기를 계산하는 프로그램 */
#include <stdio.h>

int main(void) {

    short year = 0; // 0으로 초기화한다.
    int sale = 0;   // 0으로 초기화한다.
    long total_sale = 0l;    // 0으로 초기화한다.

    year = 10;  // short <= 32767
    sale = 21000000;   // 약 21억을 넘지 않도록 주의
    total_sale = year * sale;   // 약 21억을 넘지 않도록 주의

    printf("total_sale = %ld\n", total_sale);

    printf("short형의 크기: %d byte\n", (short) sizeof(short));
    printf("int형의 크기: %d byte\n", (short) sizeof(int));
    printf("long형의 크기: %d byte\n", (short) sizeof(long));

    return 0;
}