/* 중첩 for 문을 이용하여 * 기호를 사각형 모양으로 출력하는 프로그램 */
#include <stdio.h>

int main(void) {
    for (int i = 0; i < 5; ++i) {   // 외부 반복문
        for (int j = 0; j < 10; ++j) {  // 내부 반복문
            printf("*");
        }
        printf("\n");   // 내부 반복문이 종료될 때마다 실행
    }

    return 0;
}
