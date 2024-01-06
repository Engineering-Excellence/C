#include <stdio.h>
#include <stdlib.h>

/**
 * main 함수의 인수 활용
 *
 * @param argc 인수의 개수
 * @param argv 문자 포인터의 배열
 * @return 정상 종료시 0, 인수 개수가 2개가 아니면 1을 반환
 */
int main(int argc, char *argv[]) {
    double mile, km;

    if (argc != 2) {
        printf("사용 방법: mile2km 거리\n");
        exit(1);
    }

    mile = atof(argv[1]);   // argv가 가리키는 값들은 수치가 아니고 문자열이므로 변환 필요
    km = 1.609 * mile;
    printf("입력된 거리는 %f km입니다.\n", km);

    return 0;
}
