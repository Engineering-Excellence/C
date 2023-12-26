/* 소문자를 대문자로 변환 */
#include <stdio.h>
#include <ctype.h>

int main(void) {
    int c;

    while ((c = getchar()) != EOF) {    // 파일의 끝이 아니면 반복, 여기서는 입력의 끝을 나타낸다.
        if (islower(c)) {
            c = toupper(c); // 소문자를 대문자로 변환한다.
        }
        putchar(c);
    }

    return 0;
}
