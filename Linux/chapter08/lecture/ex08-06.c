#include <unistd.h>
#include <stdio.h>

int main(void) {
    printf("[ex08-06.c] PPID: %d, PID: %d\n", getppid(), getpid());

    return 0;
}
