/* 수학적인 조합값을 구하는 예제 */
#include <stdio.h>

int get_integer(void);

int combination(int n, int r);

long factorial(int n);

int main(void) {
    int a, b;

    a = get_integer();
    b = get_integer();

    printf("C(%d, %d) = %d\n", a, b, combination(a, b));

    return 0;
}

int combination(int n, int r) {
    return factorial(n) / (factorial(n - r) * factorial(r));
}

int get_integer(void) {
    int n;

    printf("정수를 입력하세요.: ");
    scanf("%d", &n);

    return n;
}

long factorial(int n) {
    long result = 1;

    for (int i = 1; i <= n; ++i) {
        result *= i;
    }

    return result;
}
