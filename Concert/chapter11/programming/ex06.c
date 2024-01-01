#include <stdio.h>

typedef enum genre {
    comics, sf, novel, classic
} Genre;

typedef struct location {
    char place[128];
    int num;
} Location;

typedef struct book {
    char title[128];
    char author[128];
    Location location;
    Genre genre;
} Book;

void print_menu(void);

int add_book(void);

void print_books(void);

void search_book(void);

int main(void) {
    char menu;

    do {
        print_menu();
        scanf(" %c", &menu);

        switch (menu) {
            case '1':
                add_book();
                break;
            case '2':
                print_books();
                break;
            case '3':
                search_book();
                break;
            default:
                break;
        }
    } while (menu != '4');

    return 0;
}

void print_menu(void) {
    puts("=======================");
    puts("1. 추가");
    puts("2. 출력");
    puts("3. 검색");
    puts("4. 종료");
    puts("=======================");
    printf("정숫값을 입력하세요.: ");
}

int add_book(void) {
    puts("추가");

    return 0;
}

void print_books(void) {
    puts("출력");
}

void search_book(void) {
    puts("검색");
}
