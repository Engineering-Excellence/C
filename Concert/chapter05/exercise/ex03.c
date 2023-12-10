/* 주차료 계산 프로그램 */
#include <stdio.h>

int main(void) {
    int in_hour, in_min, out_hour, out_min, time;
    int fee = 1500;

    printf("들어온 시간을 입력하세요(0-24).: ");
    scanf("%d", &in_hour);
    printf("들어온 분을 입력하세요(0-60).: ");
    scanf("%d", &in_min);
    printf("나가는 시간을 입력하세요(0-24).: ");
    scanf("%d", &out_hour);
    printf("나가는 시간을 입력하세요(0-60).: ");
    scanf("%d", &out_min);

    time = (out_hour - in_hour) * 60 + out_min - in_min;
    fee += (time - 30) / 10 * 500;

    printf("주차 요금은 다음과 같습니다.\n");
    printf("주차한 시간: %d분\n", time);
    printf("주차 요금: %d원\n", fee);

    return 0;
}
