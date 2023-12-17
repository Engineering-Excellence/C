/* 두 점 사이의 거리를 계산하는 함수 */
#include <stdio.h>
#include <math.h>

float dist_2d(float x1, float y1, float x2, float y2) {
    return sqrtf(powf(x1 - x2, 2) + powf(y1 - y2, 2));
}

int main(void) {
    float x1, y1, x2, y2;

    printf("두 점 사이의 거리를 구합니다.\n");
    printf("첫 번째 점의 좌표(x1, y1)를 공백으로 구분하여 입력하세요.: ");
    scanf("%f %f", &x1, &y1);
    printf("두 번째 점의 좌표(x2, y2)를 공백으로 구분하여 입력하세요.: ");
    scanf("%f %f", &x2, &y2);

    printf("d = %f\n", dist_2d(x1, y1, x2, y2));

    return 0;
}
