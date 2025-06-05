/**
 * Chapter11 파이프를 이용한 통신
 *
 * 학습목표
 * 파이프에 대해서 이해한다.
 * 파이프(PIPE)와 네임드 파이프(FIFO)의 차이에 대해서 이해한다.
 * 다수의 프로세스와 동시에 통신하는 방법에 대해서 이해한다.
 */

#include <unistd.h>
#include <sys/select.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>

#define MSGSIZE 64

int main(void) {
    pid_t pid1, pid2;
    int filedes, p1[2], p2[2];  // 네임드 파이프 개방 및 생성시 사용할 파일 기술자
    fd_set initset, newset; // select()에서 사용할 파일 기술자의 집합
    ssize_t nread;
    char msg[MSGSIZE];

    pipe(p1);   // 부모-자식 프로세스 간 파이프 생성
    pipe(p2);

    pid1 = pid2 = 0;
    pid1 = fork();
    if (pid1 > 0)
        pid2 = fork();

    if (pid1 > 0 && pid2 > 0) {
        // 부모 프로세스: p1 && p2 읽기
        puts("[parent] hello!");
        close(p1[1]);   // 미사용(쓰기용) 파이프 닫기
        close(p2[1]);

        FD_ZERO(&initset);  // 파일 기술자 집합 초기화
        FD_SET(p1[0], &initset);    // 읽기용 파이프 파일 기술자 등록
        FD_SET(p2[0], &initset);

        newset = initset;
        while (select(p2[0] + 1, &newset, NULL, NULL, NULL) > 0) {
            // newset에 등록된 파일 기술자 중 읽기 가능한 파일 기술자 관찰
            if (FD_ISSET(p1[0], &newset))
                if (read(p1[0], msg, MSGSIZE) > 0)
                    printf("[parent] %s\n", msg);   // 첫 번째 파이프 읽기 후 표준 출력
            if (FD_ISSET(p2[0], &newset))
                if (read(p2[0], msg, MSGSIZE) > 0)
                    printf("[parent] %s\n", msg);   // 두 번째 파이프 읽기 후 표준 출력
            newset = initset;
        }
    } else if (pid1 == 0 && pid2 == 0) {
        // 첫 번째 자식 프로세스: p1 쓰기
        puts("[fork1] hello!");
        close(p1[0]);   // 미사용 파이프 닫기
        close(p2[0]);
        close(p2[1]);

        dup2(p1[1], 1/* 표준 출력 */); // 파일 기술자 연결: 표준 출력을 쓰기용 파이프의 사본으로 만듦
        execl("ex11-01c", "ex11-01c", (char *) 0);
    } else if (pid1 > 0 && pid2 == 0) {
        // 두 번째 자식 프로세스: p2 쓰기
        puts("[fork2] hello!");
        close(p1[0]);   // 미사용 파이프 닫기
        close(p1[1]);
        close(p2[0]);
        write(p2[1], "from fork2 via pipe", strlen("from fork2 via pipe")); // 파이프로 메시지 송신

        if (mkfifo("./fifo", 0666) == -1)   // 특수 파일인 네임드 파이프 생성
            perror("mkfifo error");
        filedes = open("./fifo", O_RDWR);   // 네임드 파이프 열기
        nread = read(filedes, msg, MSGSIZE);
        printf("%s (%zd)\n", msg, nread);   // 네임드 파이프 읽기 후 표준 출력
        close(filedes); // 네임드 파이프 닫기
        unlink("./fifo");   // 네임드 파이프 삭제
    } else
        perror("fork error");

    return 0;
}
