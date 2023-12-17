/* 정수의 각 자릿수를 출력하는 함수 */
#include <stdio.h>

void show_digit(unsigned int x);

int main(void) {
    unsigned int num;

    printf("양의 정수를 입력하세요.: ");
    scanf("%d", &num);

    show_digit(num);

    return 0;
}

void show_digit(unsigned int x) {
    if (x / 10 == 0) {
        printf("%d ", x);
        return;
    } else {
        printf("%d ", x % 10);
        show_digit(x / 10);
    }
}
