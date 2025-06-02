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
 * @brief 부모 프로세스와 자식 프로세스 모두 동일한 파이프에 대해 읽기와 쓰기 작업이 가능한 문제가 있는 프로그램(본래 파이프는 단방향 전달 목적)
 */
int main(void) {
    char msg[SIZE];
    int filedes[2];
    pid_t pid;

    if (pipe(filedes) == -1) {
        perror("fail to call pipe()\n");
        return EXIT_FAILURE;
    }

    if ((pid = fork()) == -1) {
        perror("fail to call fork()\n");
        return EXIT_FAILURE;
    } else if (pid > 0) {   // 부모 프로세스
        strcpy(msg, "Apple is red.\n");
        write(filedes[1], msg, SIZE); // 파이프를 통해 자식 프로세스에 쓰기
        printf("[parent] %s", msg);
        waitpid(pid, NULL, 0);
    } else {    // 자식 프로세스
        sleep(1);
        read(filedes[0], msg, SIZE);  // 파이프를 통해 부모 프로세스로부터 읽기
        printf("[child] %s", msg);
    }

    return EXIT_SUCCESS;
}