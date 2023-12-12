/* 구의 표면적과 체적을 구하는 프로그램 */
#include <stdio.h>
#include <math.h>

int main(void) {
    double r, A, V;

    printf("반지름을 입력하세요.: ");
    scanf("%lf", &r);

    A = 4 * M_PI * pow(r, 2);
    V = (double) 4 / 3 * M_PI * pow(r, 3);

    printf("구의 표면적: %lf\n구의 체적: %lf", A, V);

    return 0;
}
