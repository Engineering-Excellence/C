/* 단어의 개수 세기 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SEPS " ,\t\n.;:!?-"  // 단어 구분자

int main(void) {
    unsigned short cnt = 0;
    const char *token;
    char text[1024];
    char *saveptr;

    printf("텍스트를 입력하세요.: ");
    if (fgets(text, sizeof(text), stdin) == NULL) {  // 파일 읽기 오류 처리
        puts("텍스트 읽기에 실패했습니다.");
        return EXIT_FAILURE;
    }
    text[strcspn(text, "\n")] = '\0';  // 개행 문자를 null 문자로 바꿔서 문자열을 종료

    token = strtok_r(text, SEPS, &saveptr);
    while (token != NULL) {
        cnt++;
        token = strtok_r(NULL, SEPS, &saveptr); // 첫 번째 인자를 NULL로 지정하여 이전에 분석한 문자열에서 계속해서 단어를 찾음
    }
    printf("단어의 개수는 %d개입니다.\n", cnt);

    return 0;
}
