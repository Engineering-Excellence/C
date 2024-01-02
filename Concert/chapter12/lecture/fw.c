/* 필드폭을 지정하는 방법 */
#include <stdio.h>

int main(void) {
    printf("%6d    %6d\n", 1, -1);      // 필드폭은 6이고 오른쪽 정렬
    printf("%6d    %6d\n", 12, -12);
    printf("%6d    %6d\n", 123, -123);
    printf("%-6d   %-6d\n", 1, -1);     // 필드폭은 6이고 왼쪽 정렬
    printf("%-6d   %-6d\n", 12, -12);
    printf("%-6d   %-6d\n", 123, -123);

    return 0;
}
