#include <stdio.h>

int main(void) {
    int n;

    printf("정수를 입력하세요.: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            printf("%d", j);
        }
        printf("\n");
    }

    return 0;
}
