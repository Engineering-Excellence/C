/* 두 수 중에서 큰 수를 찾는 함수 호출 */
#include <stdio.h>

int get_max(int x, int y);

int main(void) {
    int a, b;

    printf("두 정수를 공백으로 구분하여 입력하세요.: ");
    scanf("%d %d", &a, &b);

    printf("두 수 중에서 큰 수는 %d입니다.\n", get_max(a, b));

    return 0;
}

int get_max(int x, int y) {
    return x >= y ? x : y;
}
