#include <stdio.h>

int main(void) {

    char c; // 변수 선언

    printf("문자를 입력하세요.: ");
    scanf("%c", &c);

    printf("입력된 문자는 '%c'(%d)입니다.\n", c, c);

    return 0;
}