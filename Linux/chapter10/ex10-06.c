/**
 * kill, raise
 *
 * kill은 특정 프로세스나 특정 프로세스의 그룹에게 지정한 시그널을 전달한다.
 * raise는 자기 자신에게 지정한 시그널을 전달한다.
 */

#include <signal.h>
#include <unistd.h>
#include <stdio.h>

int main(void) {
    pid_t pid;
    int count = 5;

    if ((pid = fork()) > 0) {   // 부모 프로세스
        sleep(2);
        kill(pid, SIGINT);  // 자식 프로세스에게 SIGINT 전달
        raise(SIGINT);  // 자신에게 SIGINT 전달
        puts("[parent] bye!");  // 미출력
    } else if (pid == 0) {  // 자식 프로세스
        while (count) {
            printf("[child] count is %d\n", count--);
            sleep(1);
        }
    } else
        fprintf(stderr, "fail to fork\n");

    return 0;
}