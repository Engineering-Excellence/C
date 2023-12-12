// 아스키 코드와 이스케이프 문자 출력
#include <stdio.h>

int main(void) {

    printf("\"%c%c%c%c%c %c%c%c%c\", '%c', '%c', '%c',\n\\%c \\%c \\%c", 65, 83, 67, 73, 73, 99, 111, 100, 101, 65, 66,
           67, 116, 97, 110);

    return 0;
}