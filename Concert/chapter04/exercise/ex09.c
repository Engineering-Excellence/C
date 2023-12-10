/* 조건 연산자 '?'만을 이용하여 2차원 공간의 x 좌표와 y 좌표를 입력받아서 해당 좌표가 속하는 사분면을 출력하는 프로그램 */
#include <stdio.h>

int main(void) {
    float x, y;

    printf("좌표 (x, y)를 공백으로 구분하여 입력하세요.: ");
    scanf("%f %f", &x, &y);

    printf("(x, y)가 속한 사분면: 제%d사분면",
           x > 0 && y > 0 ? 1 : x < 0 && y > 0 ? 2 : x < 0 && y < 0 ? 3 : x > 0 && y < 0 ? 4 : 0);

    return 0;
}
