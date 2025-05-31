/**
 * sigaction
 *
 * 프로세스가 특정한 시그널을 받았을 때 취해야 할 행동을 지정한다.
 */

#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int num = 0;

void int_handle(int);

int main(void) {
    static struct sigaction act;

    act.sa_handler = int_handle;
    sigfillset(&(act.sa_mask)); // sa_mask 안에 등록된 시그널들은 핸들러 실행 중 봉쇄(무시가 아닌 연기)됨
    sigaction(SIGINT, &act, NULL);  // SIGINT가 들어오면 act에 등록된 방식(int_handle)으로 행동

    while (1) {
        puts("I'm sleepy...");
        sleep(1);
        raise(SIGINT);
        if (num >= 3)
            exit(EXIT_SUCCESS);
    }
}

void int_handle(int signum) {
    printf("SIGINT: %d\n", signum);
    printf("int_handle called %d times\n", ++num);
}