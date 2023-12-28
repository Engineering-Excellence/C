/* 한영 사전의 구현 */
#include <string.h>
#include <stdio.h>

#define WORDS 5

int main(void) {
    int idx;
    char word[30];
    char dic[WORDS][2][30] = {  // [단어의 개수][영한][문자열의 최대 길이]
            {"book",     "책"},
            {"boy",      "소년"},
            {"computer", "컴퓨터"},
            {"language", "언어"},
            {"rain",     "비"},
    };

    printf("단어를 입력하세요.: ");
    scanf("%s", word);

    idx = 0;
    for (int i = 0; i < WORDS; ++i) {
        if (strcmp(dic[idx][0], word) == 0) {   // 일치하는 문자열이 발견되면
            printf("%s: %s\n", word, dic[idx][1]);
            return 0;
        }
        idx++;
    }
    printf("사전에서 발견되지 않았습니다.\n");

    return 0;
}
