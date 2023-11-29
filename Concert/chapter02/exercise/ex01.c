// 연습문제 1: 3개의 정수를 입력받은 후 평균값 출력
#include <stdio.h>

int main(void) {

    int num1;
    int num2;
    int num3;
    int average;

    printf("첫 번째 정수를 입력하세요.: ");
    scanf("%d", &num1);
    printf("두 번째 정수를 입력하세요.: ");
    scanf("%d", &num2);
    printf("세 번째 정수를 입력하세요.: ");
    scanf("%d", &num3);

    average = (num1 + num2 + num3) / 3;
    printf("평균은 %d입니다.\n", average);

    return 0;
}