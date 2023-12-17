/* 주차장 요금 계산 함수 */
#include <stdio.h>

int cal_parking_charge(float time) {
    int charge = 0, day;

    day = (int) time / 24;
    time -= day * 24;
    charge += day * 6000;

    if (time > 0 && time <= 2) charge += 3000;
    else if (time > 2 && time <= 3.5) charge += 5000;
    else charge += 6000;

    return charge;
}

int main(void) {
    float time;

    printf("주차시간(단위: 시간)을 입력하세요.: ");
    scanf("%f", &time);

    printf("주차요금은 %d원입니다.\n", cal_parking_charge(time));

    return 0;
}
