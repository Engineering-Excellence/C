/**
 * mkfifo
 *
 * @brief mkfifo는 네임드 파이프인 FIFO를 생성한다. 이는 일반 파일이 아니라 특수 파일이다.
 *
 * @param *pathname 특수 파일인 FIFO의 경로명으로 일반 파일의 경로를 지정하는 것과 같다.
 * @param mode pathname으로 지정한 특수 파일의 초기 접근 권한이다.
 * @return int 호출이 성공하면 0을 반환하고, 실패하면 -1을 반환한다.
 */

#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(void) {
    char msg[BUFSIZ];
    int filedes;
    ssize_t nread;

    if (mkfifo("./fifo", 0666) == -1) { // 네임드 파이프인 FIFO 생성
        perror("fail to call mkfifo()\n");
        exit(EXIT_FAILURE);
    }
    if ((filedes = open("./fifo", O_RDWR)) < 0) {
        perror("fail to call open()\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < 3; ++i) {
        if ((nread = read(filedes, msg, BUFSIZ)) < 0) {
            perror("fail to call read()\n");
            exit(EXIT_FAILURE);
        }
        printf("Received(%zd Bytes): %s\n", nread, msg);
    }

    if (unlink("./fifo") < 0) { // fifo 삭제
        perror("fail to call unlink()\n");
        exit(EXIT_FAILURE);
    }

    return EXIT_SUCCESS;
}