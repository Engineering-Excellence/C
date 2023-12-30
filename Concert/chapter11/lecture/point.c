/* 두 점 사이의 거리를 계산 */
#include <stdio.h>
#include <math.h>

struct point {  // 구조체 정의
    int x;
    int y;
};

int main(void) {
    struct point p1, p2;    // 구조체 변수 선언
    int xdiff, ydiff;
    double dist;

    printf("점의 좌표를 입력하세요.(x1 y1): ");
    scanf("%d %d", &p1.x, &p1.y);

    printf("점의 좌표를 입력하세요.(x2 y2): ");
    scanf("%d %d", &p2.x, &p2.y);

    xdiff = p1.x - p2.x;
    ydiff = p1.y - p2.y;

    dist = sqrt(xdiff * xdiff + ydiff * ydiff);

    printf("두 점 사이의 거리는 %.2f입니다.\n", dist);

    return 0;
}
