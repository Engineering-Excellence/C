/* 실수를 정수 부분과 소수점 이하 부분으로 분리하여 출력 */
#include <stdio.h>
#include <math.h>

//float modff(float x, float *i_ptr);

int main(void) {
    float num, int_part, frac_part;

    printf("실수를 입력하세요.: ");
    scanf("%f", &num);

    frac_part = modff(num, &int_part);

    printf("정수 부분은 %.f입니다.\n소수점 이하 부분은 %.2f입니다.\n", int_part, frac_part);

    return 0;
}

/*
    float modff(float x, float *i_ptr) {
        int i = (int) x;
        *i_ptr = (float) i;
        return x - *i_ptr;
    }
*/
