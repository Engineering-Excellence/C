/* 숫자 탐색 */
#include <stdio.h>

#define SIZE 10

int *search(const int *A, int x);

int main(void) {
    int key;
    int a[SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    printf("탐색할 숫자를 입력하세요.: ");
    scanf("%d", &key);

    printf("%p", search(a, key));

    return 0;
}

int *search(const int *A, int x) {
    for (int i = 0; i < SIZE; ++i) {
        if (A[i] == x) return A + i;
    }
    return NULL;
}
