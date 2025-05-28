#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * wait
 *
 * 자신의 자식 프로세스가 종료할 때까지 대기한다.
 */
int main(void) {
    pid_t pid;
    int status; // 2Byte로 구성(상위 8bit: 종료코드, 하위 8bit: 종료원인)

    pid = fork();   // 자식 프로세스 생성

    if (pid > 0) {  // 부모 프로세스 실행
        printf("parent: waiting..\n");
        wait(&status);  // 자식 프로세스 종료 대기
        printf("parent: status is %d\n", status);   // 53760 = 0x0000D200: 0xD2를 전달받아 두 번째 바이트에 저장
    } else if (pid == 0) {  // 자식 프로세스 실행
        sleep(1);
        printf("child: bye!\n");
        exit(1234); // 1234 = 0x000004D2: 하위 1바이트인 0xD2만 전달
    } else
        fprintf(stderr, "fail to fork\n");

    printf("Goodbye!\n");

    return EXIT_SUCCESS;
}
