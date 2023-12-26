/* getchar()의 사용 */
#include <stdio.h>

int main(void) {
    int ch; // 정수형에 주의 → int getchar(void)

    while (1) {
        ch = getchar(); // 문자 입력(버퍼 사용)
        if (ch == 'q') break;
        putchar(ch);    // 문자 출력(버퍼 사용)
    }

    return 0;
}
