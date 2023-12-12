// 실수를 지수표기법으로 출력
#include <stdio.h>

int main(void) {

    double d;

    printf("실수를 입력하세요.: ");
    scanf("%lf", &d);

    printf("%lf = %e\n", d, d);

    return 0;
}