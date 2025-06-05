/**
 * mkfifo
 *
 * @brief mkfifo는 네임드 파이프인 FIFO를 생성한다. 이는 일반 파일이 아니라 특수 파일이다.
 *
 * @param pathname {const char *} 특수 파일인 FIFO의 경로명으로 일반 파일의 경로를 지정하는 것과 같다.
 * @param mode {mode_t} pathname으로 지정한 특수 파일의 초기 접근 권한이다.
 * @return {int} 호출이 성공하면 0을 반환하고, 실패하면 -1을 반환한다.
 */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(void) {
    char msg[BUFSIZ];
    int filedes;

    if ((filedes = open("./fifo", O_WRONLY)) < 0) {
        perror("fail to call open()\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < 3; ++i) {
        printf("Input a message: ");
        fgets(msg, BUFSIZ, stdin);

        if (write(filedes, msg, BUFSIZ) < 0) {
            perror("fail to call write()\n");
            exit(EXIT_FAILURE);
        }
        sleep(1);
    }

    return EXIT_SUCCESS;
}