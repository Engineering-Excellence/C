/* 2차 방정식의 근을 계산하는 함수 */
#include <stdio.h>
#include <math.h>

void quad_eqn(double a, double b, double c) {
    double D = pow(b, 2) - 4 * a * c;

    if (D > 0) {
        printf("근은 %lf와 %lf입니다.\n", (-b + sqrt(D)) / (2 * a), (-b - sqrt(D)) / (2 * a));
    } else if (D < 0) {
        printf("실근이 존재하지 않습니다.\n");
    } else {
        printf("근은 %lf(중근)입니다.\n", -b / (2 * a));
    }
}

int main(void) {
    double a, b, c;

    printf("2차 방정식의 계수를 입력하세요.\n");
    printf("a: ");
    scanf("%lf", &a);
    printf("b: ");
    scanf("%lf", &b);
    printf("c: ");
    scanf("%lf", &c);

    quad_eqn(a, b, c);

    return 0;
}
