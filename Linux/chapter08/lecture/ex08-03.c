#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * waitpid
 *
 * 프로세스 식별 번호로 지정한 자식 프로세스가 종료할 때까지 대기한다.
 */
int main(void) {
    pid_t pid1, pid2;
    int status;

    pid1 = pid2 = -1;

    pid1 = fork();  // 첫 번째 자식 프로세스 생성
    if (pid1 > 0)
        pid2 = fork();  // 두 번째 자식 프로세스 생성

    if (pid1 > 0 && pid2 > 0) { // 부모 프로세스 실행
        waitpid(pid2, &status, 0);  // 두 번째 자식 프로세스의 종료를 먼저 처리
        printf("parent: child2 - exit(%d)\n", WEXITSTATUS(status));

        waitpid(pid1, &status, 0);
        printf("parent: child1 - exit(%d)\n", WEXITSTATUS(status));
    } else if (pid1 == 0 && pid2 == -1) {   // 첫 번째 자식 프로세스 실행
        sleep(1);   // 먼저 종료 후 두 번째 자식 프로세스가 종료 처리될 때까지 좀비 프로세스가 됨
        exit(1);
    } else if (pid1 > 0 && pid2 == 0) { // 두 번째 자식 프로세스 실행
        sleep(2);   // 나중에 종료
        exit(2);
    } else
        fprintf(stderr, "fail to fork\n");

    return EXIT_SUCCESS;
}
