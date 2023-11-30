/* 원의 면적을 계산하는 프로그램 */
#include <stdio.h>
#include <math.h>

int main(void) {

    /*
        변수(variable): 프로그램에서 데이터들이 일시적으로 저장되는 공간
     */

    float radius;   // 원의 반지름
    float area;     // 원의 면적

    printf("원의 반지름을 입력하세요.: ");
    scanf("%f", &radius);

    area = (float) M_PI * powf(radius, 2);
    printf("원의 면적: %f", area);

    return 0;
}
