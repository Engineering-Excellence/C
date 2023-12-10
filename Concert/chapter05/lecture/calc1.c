/* 간단한 산술 계산기 프로그램 */
#include <stdio.h>

int main(void) {
    char op;
    int x, y;

    printf("수식을 입력하세요.: ");
    scanf("%d %c %d", &x, &op, &y);

    if (op == '+')
        printf("%d %c %d = %d\n", x, op, y, x + y);
    else if (op == '-')
        printf("%d %c %d = %d\n", x, op, y, x - y);
    else if (op == '*')
        printf("%d %c %d = %d\n", x, op, y, x * y);
    else if (op == '/')
        printf("%d %c %d = %f\n", x, op, y, (float) x / (float) y);
    else if (op == '%')
        printf("%d %c %d = %d\n", x, op, y, x % y);
    else
        printf("지원되지 않는 연산입니다.\n");

    return 0;
}
