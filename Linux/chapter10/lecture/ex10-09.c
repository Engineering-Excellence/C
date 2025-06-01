/**
 * pause
 *
 * 시그널이 전달될 때까지 대기한다.
 */

#include <unistd.h>
#include <signal.h>
#include <stdio.h>

void handler(int signum);

int main(void) {
    struct sigaction act;

    sigfillset(&(act.sa_mask));
    act.sa_handler = handler;

    sigaction(SIGALRM, &act, NULL);

    alarm(2);
    printf("pause return %d\n", pause());   // 시그널 핸들러 수행 후 -1 반환

    return 0;
}

void handler(int signum) {
    printf("signal(%d) catched\n", signum);
}