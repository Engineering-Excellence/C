/* 문자열 비교 */
#include <string.h>
#include <stdio.h>

int main(void) {
    char s1[80];    // 첫 번째 단어를 저장할 문자 배열
    char s2[80];    // 두 번째 단어를 저장할 문자 배열
    char output[200];
    int result;

    printf("첫 번째 단어를 입력하세요.: ");
    fgets(s1, sizeof(s1), stdin);
    s1[strcspn(s1, "\n")] = '\0';
    printf("두 번째 단어를 입력하세요.: ");
    fgets(s2, sizeof(s2), stdin);
    s2[strcspn(s2, "\n")] = '\0';

    result = strcmp(s1, s2);    // 문자열 s1과 문자열 s2를 비교한다.
    if (result < 0) {
        strcat(output, s1);
        strcat(output, "(이)가 ");
        strcat(output, s2);
        strcat(output, "보다 앞에 있습니다.");
        puts(output);
    } else if (result == 0) {
        strcat(output, s1);
        strcat(output, "(이)가 ");
        strcat(output, s2);
        strcat(output, "와 같습니다.");
        puts(output);
    } else {
        strcat(output, s1);
        strcat(output, "(이)가 ");
        strcat(output, s2);
        strcat(output, "보다 뒤에 있습니다.");
        puts(output);
    }

    return 0;
}
