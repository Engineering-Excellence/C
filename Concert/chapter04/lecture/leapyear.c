// 윤년 프로그램
#include <stdio.h>

int main(void) {
    int year, result;

    printf("연도를 입력하세요.: ");
    scanf("%d", &year);

    result = (year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0);
    printf("%d년은 윤년%s.", year, result ? "입니다" : "이 아닙니다");

    return 0;
}
