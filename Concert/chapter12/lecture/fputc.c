/* 문자 단위 입력 */
#include <stdio.h>

int main(void) {
    FILE *fp = NULL;

//    fp = fopen("./sample.txt", "w");
    fp = fopen("./proverb.txt", "w");

    if (fp == NULL) {
        puts("파일 열기 실패");
        return 1;
    } else {
        puts("파일 열기 성공");
    }

/*
    fputc('a', fp); // 하나의 문자를 fp에 쓴다.
    fputc('b', fp);
    fputc('c', fp);
*/

    fputs("A chain is only as strong as its weakest link.\n", fp);
    fputs("A change is as good as a rest.\n", fp);
    fputs("A fool and his money are soon parted.\n", fp);
    fputs("A friend in need is a friend indeed.\n", fp);
    fputs("A good beginning makes a good ending.\n", fp);
    fputs("A good man is hard to find.\n", fp);
    fputs("A house divided against itself cannot stand.\n", fp);
    fputs("A house is not a home.\n", fp);
    fputs("A journey of a thousand miles begins with a single step.\n", fp);
    fputs("A leopard cannot change its spots.\n", fp);
    fputs("A little knowledge is a dangerous thing.\n", fp);

    fclose(fp);

    return 0;
}
