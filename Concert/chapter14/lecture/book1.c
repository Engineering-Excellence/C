/* 배열로 구현 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define S_SIZE 50
#define MAX_BOOKS 10

struct book {
    char title[S_SIZE];
    int year;
};

int main(void) {
    struct book books[MAX_BOOKS];   // 배열
    char buffer[S_SIZE];
    int n = 0;

    while (n < MAX_BOOKS) {
        printf("책의 제목을 입력하세요(종료시 엔터): ");
        fgets(buffer, sizeof(buffer), stdin);
        buffer[strcspn(buffer, "\n")] = '\0';
        if (buffer[0] == '\0') {
            break;
        }
        strcpy(books[n].title, buffer);
        printf("책의 출판년도를 입력하세요.: ");
        fgets(buffer, sizeof(buffer), stdin);
        buffer[strcspn(buffer, "\n")] = '\0';
        books[n++].year = atoi(buffer);
    }
    putchar('\n');

    for (int i = 0; i < n; ++i) {
        printf("책의 제목: %s, 출판년도: %d\n", books[i].title, books[i].year);
    }

    return 0;
}
