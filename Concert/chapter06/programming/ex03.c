/* 화씨 0도부터 100도까지의 구간에 대하여 10도 간격으로 섭씨 온도로 환산 */
#include <stdio.h>

int main(void) {
    for (int i = 0; i < 101; i += 10) {
        printf("%d ℉ = %.2f ℃\n", i, (float) 5 / 9 * (i - 32));
    }

    return 0;
}
