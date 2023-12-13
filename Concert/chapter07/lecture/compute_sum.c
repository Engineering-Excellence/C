#include <stdio.h>

int compute_sum(int n); // 함수 원형(Function Prototype)

int main(void) {
    int n, sum;

    printf("정수를 입력하세요.: ");
    scanf("%d", &n);

    sum = compute_sum(n);   // 함수 사용

    printf("1부터 %d까지의 합은 %d입니다.\n", n, sum);

    return 0;
}

int compute_sum(int n) {
/*
    int result = 0;
    for (int i = 1; i <= n; ++i) {
        result += i;
    }
    return result;
*/
    return n * (n + 1) / 2;
}
