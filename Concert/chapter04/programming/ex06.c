#include <stdio.h>
#include <math.h>

int main(void) {
    double x = 0;

    printf("정수를 입력하세요.: ");
    scanf("%lf", &x);

    printf("수식의 값은 %f입니다.", (pow(x, 3) - 20) / (x - 7));

    return 0;
}
