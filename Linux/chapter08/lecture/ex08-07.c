#include <unistd.h>
#include <stdio.h>

/**
 * getpgrp, getpgid, setpgrp, setpgid
 *
 * getpgrp과 getpgid는 프로세스의 프로세스 그룹 식별 번호를 구하고, setpgrp과 setpgid는 프로세스의 프로세스 그룹 식별 번호를 변경한다.
 */
int main(void) {
    printf("getpgrp(): %d\n", getpgrp());
    printf("getpgid(0): %d\n", getpgid(0));
    printf("getpgid(getpid()): %d\n", getpgid(getpid()));

    return 0;
}
