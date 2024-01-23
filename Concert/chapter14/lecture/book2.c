#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define S_SIZE 50

typedef struct NODE {   // 노드의 타입을 정의
    char title[S_SIZE];
    int year;
    struct NODE *link;
} NODE;

int main(void) {
    NODE *list = NULL;
    NODE *prev, *p, *next;  // 노드를 가리키는 포인터 정의
    char buffer[S_SIZE];

    // 연결 리스트에 정보를 입력한다.
    while (1) {
        printf("책의 제목을 입력하세요(종료시 엔터): ");
        fgets(buffer, sizeof(buffer), stdin);
        buffer[strcspn(buffer, "\n")] = '\0';
        if (buffer[0] == '\0') {
            break;
        }

        p = (NODE *) malloc(sizeof(NODE));  // 동적 메모리 할당
        strcpy(p->title, buffer);
        printf("책의 출판년도를 입력하세요.: ");
        fgets(buffer, sizeof(buffer), stdin);
        buffer[strcspn(buffer, "\n")] = '\0';
        p->year = atoi(buffer);

        if (list == NULL) {
            list = p;
        } else {
            prev->link = p;
        }
        p->link = NULL; // 현재 처리중인 구조체가 연결 리스트의 마지막 노드
        prev = p;
    }
    putchar('\n');

    // 연결 리스트에 들어있는 정보를 모두 출력한다.
    p = list;   // 연결 리스트의 첫 번째 노드를 가리키게 함
    while (p != NULL) {
        printf("책의 제목: %s, 출판년도: %d\n", p->title, p->year);
        p = p->link;
    }

    // 동적 할당을 반납한다.
    p = list;
    while (p != NULL) {
        next = p->link;
        free(p);    // 동적 메모리 반납
        p = next;
    }

    return 0;
}
