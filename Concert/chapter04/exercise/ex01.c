/* 사용자로부터 초 단위의 시간을 입력받아서 몇 분 몇 초인지를 계산하는 프로그램 */
#include <stdio.h>

int main(void) {
    int t;

    printf("시간(초)을 입력하세요.: ");
    scanf("%d", &t);
    printf("%d초는 %d분 %d초입니다.", t, t / 60, t % 60);

    return 0;
}
