/* 구조체로 새로운 자료형 만들기 */
#include <stdio.h>

typedef struct point {  // 구조체를 정의하면서 동시에 POINT 타입으로 재정의
    int x;
    int y;
} POINT;

POINT translate(POINT p, POINT delta);

int main(void) {
    POINT p = {2, 3};
    POINT delta = {10, 10};
    POINT result = translate(p, delta);

    printf("새로운 점의 좌표는 (%d, %d)입니다.\n", result.x, result.y);

    return 0;
}

POINT translate(POINT p, POINT delta) {
    POINT new_p;

    new_p.x = p.x + delta.x;
    new_p.y = p.y + delta.y;

    return new_p;
}
