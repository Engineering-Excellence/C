/* 단어 빈도 계산 */
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SEPS " ,\t\n.;:!?-"  // 단어 구분자
#define MAX_WORDS 1000
#define MAX_CHAR 100

typedef struct {
    char word[MAX_CHAR];
    int count;
} WordFreq;

int main() {
    WordFreq words[MAX_WORDS];
    int numWords = 0;

    char line[MAX_CHAR * MAX_WORDS];
    printf("텍스트를 입력하세요: ");
    fgets(line, sizeof(line), stdin);

    char *token = strtok(line, SEPS);
    while (token != NULL) {
        // 이미 리스트에 있는 단어인지 확인
        int found = 0;
        for (int i = 0; i < numWords; i++) {
            if (strcmp(words[i].word, token) == 0) {
                // 단어를 찾았다면 빈도를 증가시키고 플래그를 설정
                words[i].count++;
                found = 1;
                break;
            }
        }

        // 단어가 리스트에 없다면 새로운 단어를 추가
        if (!found && numWords < MAX_WORDS) {
            strcpy(words[numWords].word, token);
            words[numWords].count = 1;
            numWords++;
        }

        token = strtok(NULL, SEPS);
    }

    puts("------------------------------------");
    puts("단어\t\t\t\t\t빈도");
    puts("------------------------------------");
    for (int i = 0; i < numWords; i++) {
        printf("%-20s%d\n", words[i].word, words[i].count);
    }

    return 0;
}
