/* while 문을 이용한 최대공약수 구하기 프로그램 */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int a, b, r;

    printf("두 개의 자연수를 공백으로 구분하여 입력하세요.: ");
    scanf("%d %d", &a, &b);

    if (a <= 0 || b <= 0) {
        printf("자연수만 입력 가능합니다.\n");
        exit(1);
    } else if (a < b) {
        int tmp = a;
        a = b;
        b = tmp;
    }

    while (b > 0) {
        r = a % b;  // a = bq + r
        a = b;
        b = r;
    }

    printf("최대공약수는 %d입니다.\n", a);

    return 0;
}
