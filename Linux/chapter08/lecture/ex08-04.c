#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(void) {
    pid_t pid;
    int status = 0;

    if ((pid = fork()) > 0) {
        while (!waitpid(pid, &status, WNOHANG)) {   // WNOHANG: 부모 프로세스를 대기 상태로 만들지 않음
            printf("parent: %d\n", status++);   // 자식 프로세스가 실행되는 동안 계속 실행
            sleep(1);
        }
        printf("parent: child - exit(%d)\n", status);
    } else if (pid == 0) {
        sleep(5);
        printf("bye!\n");
        exit(EXIT_SUCCESS);
    } else
        fprintf(stderr, "fail to fork\n");

    return EXIT_SUCCESS;
}
