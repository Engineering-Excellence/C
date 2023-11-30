// 실수를 소수점 표기 방법과 지수 표기 방법으로 동시에 출력
#include <stdio.h>

int main(void) {

    double num;

    printf("실수를 입력하세요.: ");
    scanf("%lf", &num);

    printf("%lf = %e\n", num, num);

    return 0;
}