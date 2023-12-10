#include <stdio.h>

int main(void) {
    float ac, ae, bc;

    printf("선분 AC, AE, BC의 길이를 공백으로 구분하여 순서대로 입력하세요.: ");
    scanf("%f %f %f", &ac, &ae, &bc);

    printf("(선분 DE의 길이) = %f", ae * bc / ac);

    return 0;
}
