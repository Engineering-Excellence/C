// 아스키 코드와 숫자를 더한 값을 문자 형식으로 출력
#include <stdio.h>

int main(void) {

    char ch = 'a';

    for (int i = 1; i < 4; ++i) {
        printf("'%c' + %d = %c\n", ch, i, ch + i);
    }

    return 0;
}