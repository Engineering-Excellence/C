/* 파일 내 문자열 탐색 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void) {
    FILE *fp;
    char fname[128];
    char buffer[256];
    char word[256];
    int line_num = 0;
    int cnt = 0;

    printf("파일명을 입력하세요.: ");
    scanf("%s", fname);

    printf("탐색할 단어를 입력하세요.: ");
    scanf("%s", word);

    // 파일을 읽기 모드로 연다.
    if ((fp = fopen(fname, "r")) == NULL) {
        fprintf(stderr, "파일 %s을 열 수 없습니다.\n", fname);
        exit(1);
    }

    while (fgets(buffer, sizeof(buffer), fp)) {
        line_num++;
        if (strstr(buffer, word)) {     // buffer 안에 word가 있으면 참
            cnt++;
            printf("%s: %d행 → 단어 %s이(가) 발견되었습니다.\n", fname, line_num, word);
        }
    }

    if (cnt > 0) {
        printf("발견한 단어 개수: %d개\n", cnt);
    } else {
        puts("단어를 발견하지 못 했습니다.");
    }

    fclose(fp);

    return 0;
}
