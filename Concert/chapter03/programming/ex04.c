// 자료형의 크기 출력
#include <stdio.h>

int main(void) {

    printf("char형의 크기: %d byte\n", (short) sizeof(char));
    printf("unsigned char형의 크기: %d byte\n", (short) sizeof(unsigned char));
    printf("short형의 크기: %d byte\n", (short) sizeof(short));
    printf("unsigned short형의 크기: %d byte\n", (short) sizeof(unsigned short));
    printf("int형의 크기: %d byte\n", (short) sizeof(int));
    printf("unsigned int형의 크기: %d byte\n", (short) sizeof(unsigned int));
    printf("long형의 크기: %d byte\n", (short) sizeof(long));
    printf("unsigned long형의 크기: %d byte\n", (short) sizeof(unsigned long));
    printf("float형의 크기: %d byte\n", (short) sizeof(float));
//    printf("unsigned float형의 크기: %d byte\n", (short) sizeof(unsigned float));
    printf("double형의 크기: %d byte\n", (short) sizeof(double));
//    printf("unsigned double형의 크기: %d byte\n", (short) sizeof(unsigned double));

    return 0;
}