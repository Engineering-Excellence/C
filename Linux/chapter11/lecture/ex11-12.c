/**
 * dup2
 *
 * 파일 기술자를 연결하는 함수다.
 */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(void) {
    int p[2];
    pid_t pid;

    if (pipe(p) == -1) {
        perror("fail to call pipe() #1\n");
        exit(EXIT_FAILURE);
    }
    if ((pid = fork()) == -1) {
        perror("fail to call fork() #1\n");
        exit(EXIT_FAILURE);
    } else if (pid > 0) {
        puts("[parent]");
        close(p[0]);
        dup2(p[1], 1/* 표준 출력 */);   // 파일 기술자 연결: 표준 출력력을 쓰기용 파이프의 사본으로 만듦
        execlp("ls", "ls", "-al", (char *) 0);
        perror("[parent] fail to call execlp()\n");
    } else {
        puts("[child]");
        close(p[1]);
        dup2(p[0], 0/* 표준 입력 */);  // 파일 기술자 연결: 표준 입력을 읽기용 파이프의 사본으로 만듦
        execlp("wc", "wc", (char *) 0);
        perror("[child] fail to call execlp()\n");
    }

    return EXIT_SUCCESS;
}