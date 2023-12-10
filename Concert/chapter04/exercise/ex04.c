#include <stdio.h>

int main(void) {
    int num;

    printf("세 자리 정수를 입력하세요.: ");
    scanf("%d", &num);

    printf("백의 자릿수: %d\n", num / 100);
    printf("십의 자릿수: %d\n", num % 100 / 10);
    printf("일의 자릿수: %d\n", num % 10);

    return 0;
}
