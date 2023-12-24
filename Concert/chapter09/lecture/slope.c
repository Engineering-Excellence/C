#include <stdio.h>

/* 기울기와 y절편을 계산 */
int get_line_param(int x1, int y1, int x2, int y2, float *slope, float *yintercept);    // 포인터들을 통해 값들을 반환

int main(void) {
    float s, y;

    if (get_line_param(3, 3, 6, 6, &s, &y) == -1) {
        printf("ERROR\n");
    } else {
        printf("slope = %f, yintercept = %f\n", s, y);
    }

    return 0;
}

int get_line_param(int x1, int y1, int x2, int y2, float *slope, float *yintercept) {
    if (x1 == x2) {
        return -1;
    } else {
        *slope = (float) (y2 - y1) / (float) (x2 - x1);
        *yintercept = (float) y1 - (*slope) * (float) x1;
        return 0;
    }
}
