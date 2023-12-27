/* 문자열 복사 & 연결 */
#include <stdio.h>
#include <string.h>

int main(void) {
    char string[80];

    strcpy(string, "Hello world from ");    // 문자열 복사
    strcat(string, "strcpy ");  // 문자열 추가
    strcat(string, "and ");
    strcat(string, "strcat!");

    printf("string = %s\n", string);

    return 0;
}
