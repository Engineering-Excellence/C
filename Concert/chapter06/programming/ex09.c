/* 정수 계산기 */
#include <stdio.h>

void printMenu() {
    printf("*************\n");
    printf("A---Add\n");
    printf("S---Subtract\n");
    printf("M---Multiply\n");
    printf("D---Divide\n");
    printf("Q---Quit\n");
    printf("*************\n");
}

int main(void) {
    char menu;
    int x, y;

    printMenu();

    do {
        printf("연산을 선택하세요.: ");
        menu = getchar();
        while (getchar() != '\n');  // 입력 버퍼 비우기

        switch (menu) {
            case 'A':
                printf("두 수를 공백으로 분리하여 입력하세요.: ");
                scanf("%d %d", &x, &y);
                printf("%d\n", x + y);
                break;
            case 'S':
                printf("두 수를 공백으로 분리하여 입력하세요.: ");
                scanf("%d %d", &x, &y);
                printf("%d\n", x - y);
                break;
            case 'M':
                printf("두 수를 공백으로 분리하여 입력하세요.: ");
                scanf("%d %d", &x, &y);
                printf("%d\n", x * y);
                break;
            case 'D':
                printf("두 수를 공백으로 분리하여 입력하세요.: ");
                scanf("%d %d", &x, &y);
                printf("%d\n", x / y);
                break;
            default:
                break;
        }
    } while (menu != 'Q');

    return 0;
}
