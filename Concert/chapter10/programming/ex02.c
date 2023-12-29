/* 입력받은 문자의 아스키 코드값을 출력 */
#include <stdio.h>

int main(void) {
    char buffer[2];

    printf("문자 1개를 입력하세요.: ");
    fgets(buffer, sizeof(buffer), stdin);
    printf("%c: %d\n", buffer[0], buffer[0]);

    return 0;
}
