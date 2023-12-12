/* 반복을 이용한 정수합 프로그램 */
#include <stdio.h>

int main(void) {
    int sum = 0;

    for (int i = 1; i <= 10; ++i) {
        sum += i;
    }

    printf("1부터 10까지의 정수의 합: %d", sum);

    return 0;
}
