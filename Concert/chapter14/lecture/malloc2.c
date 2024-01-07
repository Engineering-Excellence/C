/* 문자열 동적 메모리 할당 */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    char *pc = NULL;

    pc = (char *) malloc(100 * sizeof(char));   // 동적 메모리 할당
    if (pc == NULL) {
        fprintf(stderr, "메모리 할당 오류\n");
        exit(1);
    }
    for (int i = 0; i < 26; ++i) {
        *(pc + i) = 'a' + i;    // 알파벳 소문자를 순서대로 대
    }
    *(pc + 26) = 0;     // NULL 문자 추가

    puts(pc);

    free(pc);   // 동적 메모리 반납

    return 0;
}
