/* 사용자로부터 두 개의 정수를 입력받아 +, -, *, /, % 연산을 해서 화면에 출력 */
#include <stdio.h>

int main(void) {
    int i, j;

    printf("두 개의 정수를 공백으로 구분해서 입력하세요.: ");
    scanf("%d %d", &i, &j);

    printf("%d + %d = %d\n", i, j, i + j);
    printf("%d - %d = %d\n", i, j, i - j);
    printf("%d * %d = %d\n", i, j, i * j);
    printf("%d / %d = %d\n", i, j, i / j);
    printf("%d %% %d = %d\n", i, j, i % j);

    return 0;
}
