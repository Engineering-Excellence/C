/* 문자열의 배열 */
#include <stdio.h>

int main(void) {
//    char menu[5][6] = {    // 2차원 문자 배열에 여러 개의 문자열을 저장
    char *menu[5] = {
            "init",
            "open",
            "close",
            "read",
            "write"
    };

    for (int i = 0; i < 5; ++i) {
        printf("%d번째 메뉴: %s\n", i, menu[i]);
    }
    
    return 0;
}
