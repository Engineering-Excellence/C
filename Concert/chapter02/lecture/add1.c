/* 두 개의 숫자의 합을 계산하는 프로그램 */
#include <stdio.h>

int main(void) {
    // 변수 선언
    int x;      // 첫 번째 정수를 저장할 변수
    int y;      // 두 번째 정수를 저장할 변수
    int sum;    // 두 정수의 합을 저장하는 변수

    // 변수에 값을 할당
    x = 100;
    y = 200;

    sum = x + y;    // 덧셈 연산
    printf("두 수의 합: %d", sum);  // 변수의 값을 출력

    return 0;
}