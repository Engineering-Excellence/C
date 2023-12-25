/* 배열의 합 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void add(const int *A, const int *B, int *C, int n);

void print_array(const int *A, int n);

int main(void) {
    int size;

    printf("배열의 크기를 입력하세요.: ");
    scanf("%d", &size);
    int a[size], b[size], c[size];

    srand((unsigned) time(NULL));
    for (int i = 0; i < size; ++i) {
        a[i] = 1 + rand() % 10;
        b[i] = 1 + rand() % 10;
    }

    print_array(a, size);
    print_array(b, size);

    add(a, b, c, size);
    print_array(c, size);

    return 0;
}

void add(const int *A, const int *B, int *C, int n) {
    for (int i = 0; i < n; ++i) {
        C[i] = A[i] + B[i];
    }
}

void print_array(const int *A, int n) {
    printf("{");
    for (int i = 0; i < n; ++i) {
        printf("%d", A[i]);
        if (i < n - 1) printf(", ");
    }
    printf("}\n");
}
