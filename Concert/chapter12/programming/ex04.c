/* 입력한 텍스트를 파일로 저장 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    FILE *fp = NULL;
    char filename[128];
    char buffer[1024];

    printf("파일명을 입력하세요.: ");
    fgets(filename, sizeof(filename), stdin);
    filename[strcspn(filename, "\n")] = '\0';

    if ((fp = fopen(filename, "w")) == NULL) {
        fprintf(stderr, "파일을 열 수 없습니다.\n");
        exit(1);
    }

    while (strcmp(fgets(buffer, sizeof(buffer), stdin), " \n") != 0) {  // 공백 문자열 입력시 종료
        fputs(buffer, fp);
    }

    fclose(fp);
    puts("파일 저장 완료");

    return 0;
}
