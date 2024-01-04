/* 텍스트 파일의 내용을 읽어서 행번호와 함께 출력 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    FILE *fp = NULL;
    char filename[128];
    char buffer[1024];
    int line = 0;

    printf("파일명을 입력하세요.: ");
    fgets(filename, sizeof(filename), stdin);
    filename[strcspn(filename, "\n")] = '\0';

    if ((fp = fopen(filename, "r")) == NULL) {
        fprintf(stderr, "파일을 읽을 수 없습니다.\n");
        exit(1);
    }

    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        printf("%d %s", ++line, buffer);    // 행번호와 함께 출력
    }
    puts("");

    fclose(fp);

    return 0;
}
