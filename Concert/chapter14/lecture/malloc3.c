/* 배열 동적 메모리 할당 */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int *pi;

    pi = (int *) malloc(5 * sizeof(int));   // 동적 메모리 할당
    if (pi == NULL) {
        fprintf(stderr, "메모리 할당 오류\n");
        exit(1);
    }

    for (int i = 0; i < 5; ++i) {
        pi[i] = 100 * (i + 1);  // *(pi + i) = 100 * (i + 1);
    }

    for (int i = 0; i < 5; ++i) {
        printf("%d ", pi[i]);
    }
    putchar('\n');

    free(pi);   // 동적 메모리 반납

    return 0;
}
