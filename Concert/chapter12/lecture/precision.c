/* 정밀도 */
#include <stdio.h>

int main(void) {
    printf("%10.3f\n", 1.23456789);     // 필드폭은 10이고 소수점 이하는 3자리
    printf("%10.4f\n", 1.23456789);
    printf("%10.5f\n", 1.23456789);
    printf("%.3f\n", 1.23456789);       // 소수점 이하는 3자리
    printf("%.4f\n", 1.23456789);
    printf("%.5f\n", 1.23456789);

    return 0;
}
