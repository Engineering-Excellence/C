#include <stdio.h>

int main(void) {

    float cm;
    double inch;

    printf("센티미터를 입력하세요.: ");
    scanf("%f", &cm);

    inch = cm / 2.54;
    printf("%.2f cm는 %.2f inch입니다.", cm, inch);

    return 0;
}