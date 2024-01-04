/* 도서 데이터베이스 구현 */
#include <stdio.h>
#include <stdlib.h>

struct book {
    char title[128];
    char author[64];
    char publisher[64];
};

void print_menu(void);

int register_book(void);

void search_book(void);

int delete_book(void);

int main(void) {
    FILE *fp;
    char menu;

    while (1) {
        print_menu();
        scanf(" %c", &menu);
        switch (menu) {
            case '1':
                register_book();
                break;
            case '2':
                search_book();
                break;
            case '3':
                delete_book();
                break;
            case '4':
                return 0;
            default:
                break;
        }
    }
}

void print_menu(void) {
    puts("메뉴");
    puts("1. 입력");
    puts("2. 탐색");
    puts("3. 삭제");
    puts("4. 종료");
    printf("번호를 입력하세요.: ");
}

int register_book(void) {
    puts("입력");
    return 1;
}

void search_book(void) {
    puts("탐색");
}

int delete_book(void) {
    puts("삭제");
    return 1;
}
