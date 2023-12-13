/* 1부터 100까지의 자연수 중 3의 배수를 출력 */
#include <stdio.h>

int main(void) {
    for (int i = 3; i <= 100; i += 3) {
        printf("%d\n", i);
    }

    return 0;
}
