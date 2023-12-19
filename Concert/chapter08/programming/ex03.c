/* 평균과 표준편차 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main(void) {
    unsigned int n;
    float subtotal;
    float m;

    srand((unsigned) time(NULL));
    printf("표본의 크기를 입력하세요.: ");
    scanf("%d", &n);
    int sample[n];

    subtotal = 0;
    for (int i = 0; i < n; ++i) {
        sample[i] = rand() % 101;
        subtotal += (float) sample[i];
        printf("%d ", sample[i]);
    }
    printf("\n");

    m = subtotal / (float) n;
    printf("평균: %.2f\n", m);

    subtotal = 0;
    for (int i = 0; i < n; ++i) {
        subtotal += powf((float) sample[i] - m, 2);
    }
    printf("분산: %.2f\n", subtotal / (float) n);

    return 0;
}
