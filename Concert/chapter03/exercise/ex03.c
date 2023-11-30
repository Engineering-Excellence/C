// 제곱미터를 평으로 환산
#include <stdio.h>
#define COEFF 3.3058;

int main(void) {

    double area;
    double convertedArea;

    printf("면적을 제곱미터 단위로 입력하세요.: ");
    scanf("%lf", &area);

    convertedArea = area / COEFF
    printf("%.2lf 제곱미터는 %.2lf평입니다.\n", area, convertedArea);

    return 0;
}