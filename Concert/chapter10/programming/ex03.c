/* 입력받은 문자열에 포함된 모든 공백 문자를 삭제 */
#include <stdio.h>
#include <ctype.h>

char *remove_space(char *result, const char *string);

int main(void) {
    char buffer[128];
    char res[128];

    printf("문자열을 입력하세요.: ");
    fgets(buffer, sizeof(buffer), stdin);
    puts(remove_space(res, buffer));

    return 0;
}

char *remove_space(char *result, const char *string) {
    int j = 0;

    for (int i = 0; string[i] != '\n'; ++i) {
        if (!isspace(string[i]))result[j++] = string[i];
    }
    result[j] = '\0';

    return result;
}
