/**
 * sigprocmask
 *
 * 시그널 집합 단위로 봉쇄될 시그널들의 목록을 설정한다.
 */

#include <signal.h>
#include <unistd.h>
#include <stdio.h>

int main(void) {
    sigset_t set;
    int count = 3;

    sigemptyset(&set);
    sigaddset(&set, SIGINT);

    sigprocmask(SIG_BLOCK, &set, NULL); // SIGINT가 포함된 set을 봉쇄 시그널 목록에 추가

    while (count) {
        printf("don't disturb me (%d)\n", count--);
        sleep(1);
        if (count == 2) raise(SIGINT);  // 봉쇄 해제 전까지 실행되지 않음
    }

    sigprocmask(SIG_UNBLOCK, &set, NULL);   // 봉쇄 해제
    puts("you did not disturb me!!");   // 봉쇄 해제 직후 SIGINT에 의해 프로세스가 종료되므로 출력되지 않음

    return 0;
}