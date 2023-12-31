/* 열거형 */
#include <stdio.h>

enum days {     // 열거형 정의
    MON, TUE, WED, THU, FRI, SAT, SUN
};

char *days_name[] = {
        "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"
};

int main(void) {
    for (enum days d = MON; d <= SUN; d++) {
        printf("%d번째 요일의 이름은 %s입니다.\n", d, days_name[d]);
    }

    return 0;
}
