#include <signal.h>
#include <unistd.h>
#include <stdio.h>

int num = 0;

void int_handle(int);

int main(void) {
    static struct sigaction act;

    act.sa_handler = int_handle;
    sigfillset(&(act.sa_mask));
    sigaction(SIGINT, &act, NULL);

    while (1) {
        puts("I'm sleepy...");
        sleep(1);
        raise(SIGINT);
        if (num >= 2) {
            act.sa_handler = SIG_DFL;   // 시그널 핸들러의 행동을 기본 행동(SIG_DFL)으로 설정, 대부분 프로세스의 경우 종료
            sigaction(SIGINT, &act, NULL);
        }
    }
}

void int_handle(int signum) {
    printf("SIGINT: %d\n", signum);
    printf("int_handle called %d times\n", ++num);
}