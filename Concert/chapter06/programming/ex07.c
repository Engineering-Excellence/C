/* 막대그래프 출력 */
#include <stdio.h>

int main(void) {
    int cnt = 0, l;

    while (1) {
        printf("막대 #%d의 높이: ", ++cnt);
        if (!scanf("%d", &l)) break;
        for (int i = 0; i < l; ++i) {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}
