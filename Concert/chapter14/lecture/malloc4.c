/* 구조체 동적 메모리 할당 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Book {
    int number;
    char title[16];
};

int main(void) {
    struct Book *p;

    p = (struct Book *) calloc(2, sizeof(struct Book));    // 동적 메모리 할당
    if (p == NULL) {
        fprintf(stderr, "메모리 할당 오류\n");
        exit(1);
    }

    p->number = 1;
    strcpy(p->title, "C Programming");
    (p + 1)->number = 2;
    strcpy((p + 1)->title, "Data Structure");

    p = realloc(p, 3 * sizeof(struct Book));    // 동적 메모리 블록의 크기 변경, 기존 데이터 값 유지

    (p + 2)->number = 3;
    strcpy((p + 2)->title, "Algorithms");

    for (int i = 0; i < 3; ++i) {
        printf("%d: %s\n", (p + i)->number, (p + i)->title);
    }

    free(p);    // 동적 메모리 반납

    return 0;
}
