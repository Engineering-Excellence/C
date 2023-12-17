/* 메뉴 시스템 */
#include <stdio.h>
#include <stdlib.h>

void print_menu();

int get_menu_number();

void hamburger();

void cheeseburger();

void sandwitch();

int main(void) {
    while (1) {
        print_menu();

        switch (get_menu_number()) {
            case 1:
                hamburger();
                break;
            case 2:
                cheeseburger();
                break;
            case 3:
                sandwitch();
                break;
            case 4:
                return 0;
            default:
                break;
        }
    }
}

void print_menu() {
    printf("1. 햄버거\n");
    printf("2. 치즈버거\n");
    printf("3. 샌드위치\n");
    printf("4. 종료\n");
}

int get_menu_number() {
    int menu;

    printf("원하는 메뉴를 선택하세요.: ");
    scanf("%d", &menu);

    if (menu >= 1 && menu <= 4) return menu;
    else return -1;
}

void hamburger() {
    printf("햄버거 메뉴 호출\n");
    exit(0);
}

void cheeseburger() {
    printf("치즈버거 메뉴 호출\n");
    exit(0);
}

void sandwitch() {
    printf("샌드위치 메뉴 호출\n");
    exit(0);
}
