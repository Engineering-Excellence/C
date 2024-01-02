/* 필드폭을 지정하여서 읽기 */
#include <stdio.h>

int main(void) {
    int a, b;

    printf("6개의 숫자로 이루어진 정수를 입력하세요.: ");
    scanf("%3d%3d", &a, &b);    // 3글자씩 나누어서 읽는다.
    printf("입력된 정수는 %d, %d\n", a, b);

    return 0;
}
