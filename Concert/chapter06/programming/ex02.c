/* 1부터 100까지의 자연수 중 3의 배수이면서 동시에 5의 배수인 숫자를 출력 */
#include <stdio.h>

int main(void) {
    for (int i = 1; i <= 100; i++) {
        if (i % 3 == 0 && i % 5 == 0) printf("%d\n", i);
    }

    return 0;
}
