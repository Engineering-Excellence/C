/* break를 이용하여 무한 루프를 탈출한다. */
#include <stdio.h>
#include <math.h>

int main(void) {
    double v;

    while (1) {
        printf("제곱근을 구할 실수를 입력하세요.: ");
        scanf("%lf", &v);

        if (v >= 0) printf("√(%lf) = %lf\n", v, sqrt(v));
        else break;
    }

    return 0;
}
