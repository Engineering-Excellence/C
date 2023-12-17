/* 예금 프로그램 */
#include <stdio.h>

int deposit;    // 전역 변수

void print_menu(void);

int save(int amount);

int draw(int amount);

int main(void) {
    int amount = 0;
    char menu = '\0';

    while (1) {
        print_menu();
        scanf(" %c", &menu);

        switch (menu) {
            case '1':
                printf("얼마를 저축하시겠습니까? (종료는 -1): ");
                scanf("%d", &amount);
                if (amount == -1) {
                    printf("종료\n");
                    return 0;
                } else {
                    save(amount);
                }
                break;

            case '2':
                printf("얼마를 인출하시겠습니까? (종료는 -1): ");
                scanf("%d", &amount);
                if (amount == -1) {
                    printf("종료\n");
                    return 0;
                } else {
                    draw(amount);
                }
                break;

            case '0':
                return 0;

            default:
                break;
        }
    }
}

void print_menu(void) {
    printf("1. 압금\n");
    printf("2. 출금\n");
    printf("0. 종료\n");
    printf("메뉴를 입력하세요.: ");
}

int save(int amount) {
//    static int deposit; // 정적 지역 변수
    deposit += amount;
    printf("지금까지 총저축액은 %d원입니다.\n", deposit);
    return 0;
}

int draw(int amount) {
    deposit -= amount;
    printf("잔고는 %d원입니다.\n", deposit);
    return 0;
}
