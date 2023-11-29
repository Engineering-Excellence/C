#include <stdio.h>

int main(void) {

    float weight_earth;
    double weight_moon;

    printf("몸무게를 입력하세요.: ");
    scanf("%f", &weight_earth);

    weight_moon = weight_earth / 6;
    printf("달에서의 몸무게는 %.1fkg입니다.", weight_moon);

    return 0;
}