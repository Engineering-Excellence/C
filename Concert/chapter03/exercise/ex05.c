// 아스키 코드력값을 문자로 변환
#include <stdio.h>

int main(void) {

    char ascii;

    printf("ASCII 코드를 입력하세요.: ");
    scanf("%d", &ascii);

    printf("%d에 해당하는 문자는 '%c'입니다.\n", ascii, ascii);

    return 0;
}