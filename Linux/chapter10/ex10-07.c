/**
 * alarm
 *
 * 지정한 시간이 경과한 뒤에 자기 자신에게 SIGALRM 시그널을 전달한다.
 */

#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void timeover();

int main(void) {
    char buf[BUFSIZ];
    char *alpha = "abcdefghijklmnopqrstuvwxyz";

    int timelimit;
    struct sigaction act;

    act.sa_handler = timeover;
    sigaction(SIGALRM, &act, NULL);

    printf("input timelimit[sec]: ");
    scanf("%d", &timelimit);

    alarm(timelimit);

    printf("START!!\n > ");
    scanf("%s", buf);

    puts(!strcmp(buf, alpha) ? "\n\nSUCCESS!!" : "\n\nFAIL!!");

    return 0;
}

void timeover() {
    puts("\nTIME OVER!!\n");
    exit(0);
}
