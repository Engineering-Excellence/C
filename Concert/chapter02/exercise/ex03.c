#include <stdio.h>

int main(void) {

    float oz;
    double g;
    const double gram = 28.3495;

    printf("온스를 입력하세요.: ");
    scanf("%f", &oz);

    g = oz * gram;
    printf("%.1f온스는 %.1f그램입니다.", oz, g);

    return 0;
}