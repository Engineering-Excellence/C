#include <stdio.h>
#include <stdlib.h>

typedef struct NODE {
    int value;
    struct NODE *link;
} NODE;

int main(void) {
    NODE *list = NULL;
    NODE *prev, *p, *next;
    int tmp;

    while (1) {
        printf("양의 정수를 입력하세요.(종료: -1): ");
        scanf(" %d", &tmp);
        if (tmp < 0) break;

        p = (NODE *) malloc(sizeof(NODE));  // 동적 메모리 할당
        p->value = tmp;

        if (list == NULL) {
            list = p;
        } else {
            prev->link = p;
        }
        p->link = NULL;     // 현재 처리중인 노드가 연결 리스트의 마지막 노드
        prev = p;
    }
    putchar('\n');

    p = list;   // 연결 리스트의 첫 번째 노드를 가리키게 함
    while (p != NULL) {
        printf("%d->", p->value);
        p = p->link;
    }
    puts("NULL");

    p = list;
    while (p != NULL) {
        next = p->link;
        free(p);    // 동적 메모리 반납
        p = next;
    }

    return 0;
}
