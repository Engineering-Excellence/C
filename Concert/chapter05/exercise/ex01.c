/* 입력받은 두 수의 합과 차를 출력 */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int x, y;

    printf("두 정수를 공백으로 구분하여 입력하세요.: ");
    scanf("%d %d", &x, &y);

    printf("두 수의 합은 %d입니다.\n", x + y);
    printf("두 수의 차는 %d입니다.\n", abs(x - y));

    return 0;
}
