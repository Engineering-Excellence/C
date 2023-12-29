/* 간단한 철자 교정 프로그램 */
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(void) {
    char buffer[256];
    unsigned long endidx;

    printf("문자열을 입력하세요.: ");
    fgets(buffer, sizeof(buffer), stdin);
    endidx = strcspn(buffer, "\n");
    buffer[endidx] = '\0';

    // 마침표 검사
    if (buffer[endidx - 1] != '.') {
        buffer[endidx] = '.';
        buffer[endidx + 1] = '\0';
    }

    // 첫 문자를 대문자로 변환
    /*
        for (int i = 0; buffer[i] != '\0'; ++i) {
            if (isalpha(buffer[i])) {
                if (islower(buffer[i])) {
                    buffer[i] = (char) toupper(buffer[i]);
                }
                break;
            }
        }
     */
    int i = 0;
    while (!isalpha(buffer[i]) && buffer[i] != '\0') {
        i++;
    }
    if (islower(buffer[i])) {
        buffer[i] = (char) toupper(buffer[i]);
    }

    printf("교정된 문자열: %s\n", buffer);

    return 0;
}
