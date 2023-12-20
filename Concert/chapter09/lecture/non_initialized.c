/* 초기화하지 않고 사용하기 */
#include <stdio.h>

int main(void) {
    int *p; // 포인터 p는 초기화가 되어있지 않음

    *p = 100;   // 초기화하지 않고 간접 참조

    int *p2 = NULL; // 포인터가 아무것도 가리키고 있지 않을 때는 NULL로 설정하는 것이 바람직하다.

    return 0;
}
