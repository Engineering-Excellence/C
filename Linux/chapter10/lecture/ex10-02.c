/**
 * sigemptyset, sigfillset, sigaddset, sigdelset, sigismember
 *
 * sigemptyset: set 인자로 주어진 시그널 집합을 아무런 시그널도 포함되어 있지 않은 비어있는 상태로 초기화한다.
 * sigfillset: set 인자로 주어진 시그널 집합을 모든 시그널이 포함되어 있는 상태로 초기화한다.
 */

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    sigset_t set;
    int result;

    sigemptyset(&set);
    result = sigismember(&set, SIGALRM);
    printf("SIGALRM is %sa member.\n", result ? "" : "not ");
    sigaddset(&set, SIGALRM);
    result = sigismember(&set, SIGALRM);
    printf("SIGALRM is %sa member.\n", result ? "" : "not ");

    sigfillset(&set);
    result = sigismember(&set, SIGCHLD);
    printf("SIGCHLD is %sa member.\n", result ? "" : "not ");
    sigdelset(&set, SIGCHLD);
    result = sigismember(&set, SIGCHLD);
    printf("SIGCHLD is %sa member.\n", result ? "" : "not ");

    return EXIT_SUCCESS;
}