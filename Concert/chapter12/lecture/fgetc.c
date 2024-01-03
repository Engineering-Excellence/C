/* 문자 단위 출력 */
#include <stdio.h>

int main(void) {
    FILE *fp = NULL;
    int c;

//    fp = fopen("./sample.txt", "r");
    fp = fopen("./proverb.txt", "r");

    if (fp == NULL) {
        puts("파일 열기 실패");
        return 1;
    } else {
        puts("파일 열기 성공");
    }

    while ((c = fgetc(fp)) != EOF) {    // 하나의 문자를 fp에서 읽어서 c에 대입한다.
        putchar(c);
    }

    fclose(fp);

    return 0;
}
