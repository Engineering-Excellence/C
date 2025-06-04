/**
 * fpathconf, pathconf
 *
 * 파일 기술자나 파일 경로를 지정하여 해당 파일과 관련된 여러 가지 정보를 확인할 수 있다.
 */

#include <unistd.h>
#include <signal.h>
//#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

int nc;

void alarm_action(int);

int main(void) {
    int filedes[2];
    char msg = 'A';

    struct sigaction act;
    act.sa_handler = alarm_action;
    sigfillset(&(act.sa_mask));

    if (pipe(filedes) == -1) {
        perror("fail to call pipe()\n");
        exit(EXIT_FAILURE);
    }

    printf("PIPE max atomic size: %ld Bytes\n", fpathconf(filedes[1], _PC_PIPE_BUF));  // 파이프의 원자적 쓰기의 최대 크기: 4096 바이트
//    printf("PIPE max size: %d Bytes\n", fcntl(filedes[1], F_GETPIPE_SZ));  // 파이프의 버퍼의 최대 크기: 65536 바이트

    nc = 0;
    sigaction(SIGALRM, &act, NULL);
    alarm(1);
    while (1) {
        write(filedes[1], &msg, 1); // 파이프 버퍼 최대 크기인 65536 바이트 쓰기 후 봉쇄 당함
        nc++;
    }
}

/**
 * @brief SIGALRM 발생시 파이프에 쓴 메시지 크기를 출력 후 프로세스를 종료하는 핸들러
 */
void alarm_action(int signo) {
    printf("\nSIGALRM(%d): blocked after %d characters\n", signo, nc);
    exit(EXIT_FAILURE);
}
