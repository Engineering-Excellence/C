/* 문자 동적 메모리 할당 */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    char *pc = NULL;

    pc = (char *) malloc(sizeof(char));     // 동적 메모리 할당
    if (pc == NULL) {
        puts("메모리 할당 오류");
        exit(1);
    }
    *pc = 'm';
    printf("*pc = %c\n", *pc);

    free(pc);   // 동적 메모리 반납

    return 0;
}
