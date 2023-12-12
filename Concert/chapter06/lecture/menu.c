/* do...while 문을 이용한 메뉴 */
#include <stdio.h>

int main(void) {
    int i;

    do {
        printf("1---파일열기\n");
        printf("2---파일닫기\n");
        printf("메뉴 중 하나를 선택하세요.: ");
        scanf("%d", &i);
    } while (i < 1 || i > 2);

    printf("선택된 메뉴: %d", i);

    return 0;
}
