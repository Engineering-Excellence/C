/* 원의 면적을 계산하는 프로그램 */
#include <stdio.h>
#include <math.h>

int main(void) {

    float radius;   // 원의 반지름
    float area; // 면적

    printf("반지름을 입력하세요.: ");
    scanf("%f", &radius);

    area = (float) M_PI * powf(radius, 2);

    printf("원의 면적: %.2f\n", area);

    return 0;
}
