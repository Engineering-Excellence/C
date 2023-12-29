/* 입력받은 텍스트를 모두 대문자로 출력 */
#include <stdio.h>
#include <ctype.h>

int main(void) {
    char buffer[256];

    printf("텍스트를 입력하세요.: ");
    fgets(buffer, sizeof(buffer), stdin);

    printf("대문자 출력: ");
    int i = 0;
    while (buffer[i] != '\n') {
        printf("%c", toupper(buffer[i]));
        i++;
    }
    puts("");

    return 0;
}
