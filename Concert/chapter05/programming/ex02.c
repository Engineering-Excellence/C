/* 근로소득세를 계산하는 프로그램 */
#include <stdio.h>

int main(void) {
    float tax_base;
    float tax_rate;

    printf("과세 표준을 입력하세요(만원).: ");
    scanf("%f", &tax_base);

    if (tax_base <= 1000) tax_rate = 0.08f;
    else if (tax_base <= 4000) tax_rate = 0.17f;
    else if (tax_base <= 8000) tax_rate = 0.26f;
    else tax_rate = 0.35f;

    printf("소득세는 %d만원입니다.", (int) (tax_base * tax_rate));

    return 0;
}
