/**
 * pipe
 *
 * 프로세스 간 통신을 위해 파이프를 생성한다.
 */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(void) {
    char msg[BUFSIZ];
    int filedes[2]; // filedes[0]: 읽기용, filedes[1]: 쓰기용
    int i;

    if (pipe(filedes) == -1) {
        perror("fail to call pipe()\n");
        return EXIT_FAILURE;
    }

    for (i = 0; i < 3; ++i) {
        printf("input a message: ");
        fgets(msg, BUFSIZ, stdin);
        write(filedes[1], msg, BUFSIZ); // 파이프로 쓰기
    }
    puts("");

    for (i = 0; i < 3; ++i) {
        read(filedes[0], msg, BUFSIZ);  // 파이프로 읽기
        printf("%s", msg);
    }

    return EXIT_SUCCESS;
}