/**
 * pipe
 *
 * 프로세스 간 통신을 위해 파이프를 생성한다.
 */

#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define SIZE 64

/**
 * @brief 자식 프로세스가 파이프에서 모든 메시지를 읽기 전에 부모 프로세스가 먼저 읽는 문제가 있는 프로그램
 */
int main(void) {
    char *msg[] = {"Apple is red.", "Banana is yellow.", "Grape is purple."};
    char buffer[SIZE];
    int filedes[2], i;
    ssize_t nread;
    pid_t pid;

    if (pipe(filedes) == -1) {
        perror("fail to call pipe()\n");
        return EXIT_FAILURE;
    }

    if ((pid = fork()) == -1) {
        perror("fail to call fork()\n");
        return EXIT_FAILURE;
    } else if (pid > 0) {   // 부모 프로세스
        for (i = 0; i < 3; ++i) {
            strcpy(buffer, msg[i]);
            write(filedes[1], buffer, SIZE);
        }

        nread = read(filedes[0], buffer, SIZE);
        printf("[parent] %s(%zd)\n", buffer, nread);

        write(filedes[1], buffer, SIZE);
        puts("[parent] bye!");
        waitpid(pid, NULL, 0);
    } else {    // 자식 프로세스
        for (i = 0; i < 3; ++i) {
            nread = read(filedes[0], buffer, SIZE);
            printf("[child] %s(%zd)\n", buffer, nread);
        }
        puts("[child] bye!");
    }

    return EXIT_SUCCESS;
}