#include <stdio.h>

int main(void) {
    char ch = 'A';  // 변수 선언
    printf("'%c'의 아스키 코드 = %d\n", ch, ch);
    ch += 1;
    printf("'%c'의 아스키 코드 = %d\n", ch, ch);

    return 0;
}