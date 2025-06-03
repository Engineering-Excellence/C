/**
 * 메시지 버퍼 크기와 파이프 크기
 *
 * 파이프를 통해서 메시지를 받을 때는 그 크기를 정확히 알고 있어야 한다.
 */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#define SIZE 64

/**
 * @brief 문자열 길이에 상관 없이 항상 메시지가 담긴 버퍼의 최대 크기로 쓰고 읽는 프로그램
 */
int main(void) {
    char *msg1 = "Apple is red.";
    char *msg2 = "Banana is yellow.";
    char buffer[SIZE];

    int filedes[2];
    ssize_t nread;

    if (pipe(filedes) == -1) {
        perror("fail to call pipe()\n");
        exit(EXIT_FAILURE);
    }

    write(filedes[1], msg1, SIZE);
    write(filedes[1], msg2, SIZE);

    for (int i = 0; i < 2; ++i) {
        nread = read(filedes[0], buffer, SIZE);
        printf("%zd, %s\n", nread, buffer);
    }

    return EXIT_SUCCESS;
}