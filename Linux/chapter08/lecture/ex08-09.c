#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(void) {
    pid_t pid;

    if ((pid = fork()) > 0) {
        sleep(1);
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        printf("old session id: %d\n", getsid(0));
        printf("new session id: %d\n", setsid());
        sleep(600);
    }

    return EXIT_SUCCESS;
}
