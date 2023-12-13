/* 정수의 제곱을 계산하는 함수 호출 */
#include <stdio.h>

int square(int n);  // 함수 원형

int main(void) {
    int result;

    for (int i = 0; i < 5; ++i) {
        result = square(i); // 함수 호출
        printf("%d\n", result);
    }

    return 0;
}

int square(int n) { // 함수 정의
    return n * n;
}
