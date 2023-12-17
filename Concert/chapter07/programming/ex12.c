/* 세제곱의 합을 출력하는 순환적인 프로그램 */
#include <stdio.h>

int recursive_sum(int n);

int main(void) {
    int num;

    printf("정수를 입력하세요.: ");
    scanf("%d", &num);

    printf("%d\n", recursive_sum(num));

    return 0;
}

int recursive_sum(int n) {
    static int sum;

    if (n == 0) {
        return sum;
    } else {
        sum += n * n * n;
        return recursive_sum(n - 1);
    }
}
