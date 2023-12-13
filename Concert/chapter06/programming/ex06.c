#include <stdio.h>
#include <limits.h>

int main(void) {
    int min = INT_MAX, curr;

    while (1) {
        printf("데이터를 입력하세요(숫자가 아닌 값을 입력시 종료).: ");
        if (!scanf("%d", &curr)) break;
        else if (min > curr) min = curr;
    }

    printf("최솟값은 %d입니다.\n", min);

    return 0;
}
