/**
 * 메시지 버퍼 크기와 파이프 크기
 *
 * 파이프를 통해서 메시지를 받을 때는 그 크기를 정확히 알고 있어야 한다.
 */

#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define SIZE 64

/**
 * @brief 두번째 메시지가 읽기가 봉쇄되는 문제가 있는 프로그램
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

    write(filedes[1], msg1, strlen(msg1) + 1);  // 실제 문자열 길이로 파이프에 쓰기
    write(filedes[1], msg2, strlen(msg2) + 1);

    for (int i = 0; i < 2; ++i) {
        nread = read(filedes[0], buffer, SIZE); // 파이프로부터 버퍼 최대 크기로 읽기: 두 번째 실행 봉쇄(메시지 읽기 실패)
        printf("%zd, %s\n", nread, buffer);
    }

    return EXIT_SUCCESS;
}