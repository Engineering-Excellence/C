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
 * @brief 파이프가 저장하고 있는 메시지의 크기를 정확히 알고 읽는 프로그램(메시지 크기 알려주는 방법 필요)
 */
int main(void) {
    char *msg1 = "Apple is red.";
    char *msg2 = "Banana is yellow.";
    char buffer[SIZE];

    int filedes[2];
    ssize_t nread;
    size_t len1 = strlen(msg1) + 1;
    size_t len2 = strlen(msg2) + 1;

    if (pipe(filedes) == -1) {
        perror("fail to call pipe()\n");
        exit(EXIT_FAILURE);
    }

    write(filedes[1], msg1, len1);
    write(filedes[1], msg2, len2);

    nread = read(filedes[0], buffer, len1);
    printf("%zd, %s\n", nread, buffer);
    nread = read(filedes[0], buffer, len2);
    printf("%zd, %s\n", nread, buffer);

    return EXIT_SUCCESS;
}