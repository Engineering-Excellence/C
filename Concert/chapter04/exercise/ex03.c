#include <stdio.h>
#include <math.h>

int main(void) {
    printf("정수    제곱값    세제곱값\n");
    for (int i = 1; i < 6; ++i) {
        printf("%d\t\t%d\t\t%d\n", i, (int) powf(i, 2), (int) powf(i, 3));
    }
    return 0;
}
