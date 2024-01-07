#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int *pi;    // 동적 메모리를 가리키는 포인터

    pi = (int *) malloc(sizeof(int));   // 동적 메모리 할당

    if (pi == NULL) {   // 반환값이 NULL인지 검사
        puts("동적 메모리 할당 오류");
        exit(1);
    }

    *pi = 100;  // 동적 메모리 사용
    printf("%d\n", *pi);

    free(pi);   // 동적 메모리 반납

    return 0;
}
