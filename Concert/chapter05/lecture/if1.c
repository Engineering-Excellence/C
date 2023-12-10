#include <stdio.h>

int main(void) {
    int number;

    printf("정수를 입력하세요.: ");
    scanf("%d", &number);

    if (number > 0) // number가 0보다 크면 printf 문장이 실행된다.
        printf("양수입니다.\n");

    printf("입력된 값은 %d입니다.\n", number);  // if 문 다음에 실행된다.

    return 0;
}
