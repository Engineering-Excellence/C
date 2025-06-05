/**
 * select
 *
 * 이미 지정한 파일 기술자 집합에서 상태가 바뀐 파일 기술자가 있는지를 확인한다.
 */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#define MSGSIZE 16

void onerror(char *msg);

int main(void) {
    int p1[2], p2[2];
    char msg[MSGSIZE];
    pid_t pid1, pid2;
    fd_set initset, newset;

    pid1 = pid2 = 0;

    if (pipe(p1) == -1)
        onerror("fail to call pipe() #1\n");
    if (pipe(p2) == -1)
        onerror("fail to call pipe() #2\n");
    if ((pid1 = fork()) == -1)
        onerror("fail to call fork() #1\n");
    if (pid1 > 0 && (pid2 = fork()) == -1)
        onerror("fail to call fork() #2\n");

    if (pid1 > 0 && pid2 > 0) { // 부모 프로세스
        printf("parent: %d\n", getpid());
        close(p1[1]);
        close(p2[1]);

        FD_ZERO(&initset);
        FD_SET(p1[0], &initset);
        FD_SET(p2[0], &initset);

        newset = initset;
        while (select(p2[0] + 1, &newset, NULL, NULL, NULL) > 0) {  // 두 자식 프로세스로 연결된 파이프를 관찰
            if (FD_ISSET(p1[0], &newset) && read(p1[0], msg, MSGSIZE) > 0)  // 읽기 가능한 파일 기술자 발견시 메시지를 읽음
                printf("[parent] %s is from child1\n", msg);
            if (FD_ISSET(p2[0], &newset) && read(p2[0], msg, MSGSIZE) > 0)
                printf("[parent] %s is from child2\n", msg);
            newset = initset;   // select 리턴시 변화가 생긴 파일 기술자에 해당하는 비트가 설정된 후 초기화 필요
        }
    } else if (pid1 == 0 && pid2 == 0) {    // 첫 번째 자식 프로세스
        printf("child1: %d\n", getpid());
        close(p1[0]);
        close(p2[0]);
        close(p2[1]);

        for (int i = 0; i < 3; ++i) {
            sleep((i + 1) % 4);
            printf("child1: send message %d\n", i);
            write(p1[1], "\"I'm child1\"", MSGSIZE);
        }
        puts("child1: Bye!");
        exit(EXIT_SUCCESS);
    } else if (pid1 > 0 && pid2 == 0) {
        printf("child2: %d\n", getpid());
        close(p1[0]);
        close(p1[1]);
        close(p2[0]);

        for (int i = 0; i < 3; ++i) {
            sleep((i + 3) % 4);
            printf("child2: send message %d\n", i);
            write(p2[1], "\"I'm child2\"", MSGSIZE);
        }
        puts("child2: Bye!");
        exit(EXIT_SUCCESS);
    }

    return EXIT_SUCCESS;
}

void onerror(char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}
