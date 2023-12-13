/* 파티고라스 정리 */
#include <stdio.h>
#include <math.h>

int main(void) {
    for (int a = 1; a < 100; ++a) {
        for (int b = 1; b < 100; ++b) {
            for (int c = 1; c < 100; ++c) {
                if (powf(a, 2) + powf(b, 2) == powf(c, 2))
                    printf("%d² + %d² = %d²\n", a, b, c);
            }
        }
    }

    return 0;
}
