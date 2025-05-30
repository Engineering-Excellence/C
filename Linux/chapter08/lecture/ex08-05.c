#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>

/**
 * getpid, getppid
 *
 * getpid는 자신의 프로세스 식별 번호를 구하고, getppid는 부모 프로세스의 식별 번호를 구한다.
 */
int main(void) {
    pid_t pid;

    if ((pid = fork()) > 0) {   // 부모 프로세스 실행
        printf("[ex08-05.c] PPID: %d, PID: %d\n", getppid(), getpid());
        sleep(1);
    } else if (pid == 0) {  // 자식 프로세스 실행
        printf("[ex08-05.c] PPID: %d, PID: %d\n", getppid(), getpid());
        execl("ex08-06", "ex08-06", (char *) 0);    // 자식 프로세스를 새로운 프로세스로 대체: PID, PPID 동일
    } else
        fprintf(stderr, "fail to fork\n");

    return 0;
}
