// if 문을 사용하여 절댓값을 구하는 프로그램
#include <stdio.h>

int main(void) {
    int number;

    printf("정수를 입력하세요.: ");
    scanf("%d", &number);

    if (number < 0) {   // number가 0보다 작으면 number의 부호를 반전한다.
        number = -number;
    }

    printf("절댓값은 %d입니다.\n", number);

    return 0;
}
