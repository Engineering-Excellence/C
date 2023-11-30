// a ~ e 문자의 아스키 코드값을 출력
#include <stdio.h>

int main(void) {

    for (unsigned char i = 'a'; i < 'f'; ++i) {
        printf("'%c' = %d = 0%o = 0x%x\n", i, i, i, i);
    }

    return 0;
}