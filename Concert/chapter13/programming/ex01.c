/* 매크로 정의 */
#include <stdio.h>

// 첫 번째 매개변수 x가 두 번째 y보다 작거나 세 번째 매개변수 z보다 크면 0을 반환하고 그렇지 않으면 1을 반환하는 매크로
#define RANGE(x, y, z) (!((x) < (y) || (x) > (z)))

// x가 홀수이고 y보다 크면 1을 반환하는 매크로
#define ODD_GT(x, y) ((x) % 2 && (x) > (y))

// c가 대문자이면 참을 반환하는 매크로
#define IS_UPPER(c) ((c) >= 'A' && (c) <= 'Z')

int main(void) {
    // RANGE 매크로 테스트
    printf("RANGE(5, 3, 10) = %d\n", RANGE(5, 3, 10));  // 1을 반환해야 함
    printf("RANGE(2, 3, 10) = %d\n", RANGE(2, 3, 10));  // 0을 반환해야 함
    printf("RANGE(12, 3, 10) = %d\n", RANGE(12, 3, 10)); // 0을 반환해야 함

    // ODD_GT 매크로 테스트
    printf("ODD_GT(5, 3) = %d\n", ODD_GT(5, 3)); // 1을 반환해야 함
    printf("ODD_GT(4, 3) = %d\n", ODD_GT(4, 3)); // 0을 반환해야 함
    printf("ODD_GT(5, 6) = %d\n", ODD_GT(5, 6)); // 0을 반환해야 함

    // IS_UPPER 매크로 테스트
    printf("IS_UPPER('A') = %d\n", IS_UPPER('A')); // 1을 반환해야 함
    printf("IS_UPPER('z') = %d\n", IS_UPPER('z')); // 0을 반환해야 함
    printf("IS_UPPER('Z') = %d\n", IS_UPPER('Z')); // 1을 반환해야 함

    return 0;
}
