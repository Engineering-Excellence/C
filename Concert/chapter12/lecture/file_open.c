/* 파일의 기초 */
#include <stdio.h>

int main(void) {
    FILE *fp = NULL;

    fp = fopen("./sample.txt", "w");     // 쓰기 모드로 파일을 연다. 파일이 없으면 생성된다.

    if (fp == NULL) {
        puts("파일 열기 실패");
        return 1;
    } else {
        puts("파일 열기 성공");
    }

    fclose(fp);     // 파일 닫기

    return 0;
}
