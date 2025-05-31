#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * getenv, putenv
 *
 * getenv는 등록된 환경변수 중 하나의 값을 구하고, putenv는 새로운 환경 변수를 등록 또는 변경한다.
 */
int main(void) {
    putenv("APPLE=BANANA");
    printf("%s\n", getenv("APPLE"));

    execl("ex08-11", "ex08-11", (char *) 0);

    return EXIT_SUCCESS;
}
