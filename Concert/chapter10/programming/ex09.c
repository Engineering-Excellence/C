#include <string.h>
#include <stdlib.h>
#include <printf.h>

#define MAX_SIZE 1024  // 최대 텍스트 크기

char *str_replace(const char *original, const char *pattern, const char *replacement);

int main(void) {
    char original[MAX_SIZE];
    char pattern[MAX_SIZE];
    char replacement[MAX_SIZE];
    char *result;

    printf("원본 문자열을 입력하세요: ");
    fgets(original, MAX_SIZE, stdin);
    original[strcspn(original, "\n")] = '\0';  // 개행 문자를 null 문자로 바꿔서 문자열을 종료

    printf("찾을 패턴을 입력하세요: ");
    fgets(pattern, MAX_SIZE, stdin);
    pattern[strcspn(pattern, "\n")] = '\0';

    printf("대체할 문자열을 입력하세요: ");
    fgets(replacement, MAX_SIZE, stdin);
    replacement[strcspn(replacement, "\n")] = '\0';

    result = str_replace(original, pattern, replacement);

    printf("결과: %s\n", result);

    free(result);  // 메모리 해제

    return 0;
}

char *str_replace(const char *original, const char *pattern, const char *replacement) {
    size_t i, count = 0;
    size_t patlen = strlen(pattern);
    size_t replen = strlen(replacement);

    for (i = 0; original[i] != '\0'; i++) {
        if (strstr(&original[i], pattern) == &original[i]) {
            count++;
            i += patlen - 1;
        }
    }

    char *newstr = malloc(i + count * (replen - patlen) + 1);
    if (newstr == NULL) {
        printf("메모리 할당에 실패했습니다.\n");
        exit(EXIT_FAILURE);
    }

    i = 0;
    while (*original) {
        if (strstr(original, pattern) == original) {
            strcpy(&newstr[i], replacement);
            i += replen;
            original += patlen;
        } else
            newstr[i++] = *original++;
    }

    newstr[i] = '\0';

    return newstr;
}
