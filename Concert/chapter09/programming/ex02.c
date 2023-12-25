/* 최소공배수와 최대공약수 */
#include <stdio.h>

int get_gcd(int x, int y);

int get_lcm(int x, int y, int *gcd_ptr);

int main(void) {
    int a, b, gcd, lcm;

    printf("두 정수를 공백으로 구분해서 입력하세요.: ");
    scanf("%d %d", &a, &b);

    lcm = get_lcm(a, b, &gcd);

    printf("최소공배수는 %d입니다.\n", lcm);
    printf("최대공약수는 %d입니다.\n", gcd);

    return 0;
}

int get_gcd(int x, int y) {
    return y == 0 ? x : get_gcd(y, x % y);
}

int get_lcm(int x, int y, int *gcd_ptr) {
    *gcd_ptr = get_gcd(x, y);
    return x * y / *gcd_ptr;
}
