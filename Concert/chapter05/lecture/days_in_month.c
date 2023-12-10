/* 달의 일수를 계산하는 프로그램 */
#include <stdio.h>

int main(void) {
    int year, month, days;

    printf("연도와 월을 입력하세요.: ");
    scanf("%d %d", &year, &month);

    switch (month) {
        case 2:
            if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
                days = 29;
            else
                days = 28;
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            days = 30;
            break;
        default:
            days = 31;
            break;
    }

    printf("%d년 %d월의 일수는 %d일입니다.\n", year, month, days);

    return 0;
}
