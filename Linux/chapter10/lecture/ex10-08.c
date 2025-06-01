/**
 * pause
 *
 * 시그널이 전달될 때까지 대기한다.
 */

#include <unistd.h>
#include <stdio.h>

int main(void) {
    alarm(2);
    printf("pause return %d\n", pause());   // 미출력

    return 0;
}