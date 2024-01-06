#include <stdio.h>

/**
 * 프로그램 인수
 *
 * @param argc 인수의 개수
 * @param argv 문자 포인터의 배열
 * @return 0
 */
int main(int argc, char *argv[]) {
    for (int i = 0; i < argc; ++i) {
        printf("명령어 라인에서 %d번째 문자열: %s\n", i, argv[i]);
    }

    return 0;
}
