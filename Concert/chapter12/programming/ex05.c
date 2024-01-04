/* 텍스트 파일 비교 후 불일치 문장 출력 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    FILE *fp1 = NULL, *fp2 = NULL;
    char fname1[128], fname2[128];
    char buffer1[1024], buffer2[1024];
    size_t line = 0;

    printf("첫 번째 파일명: ");
    fgets(fname1, sizeof(fname1), stdin);
    fname1[strcspn(fname1, "\n")] = '\0';
    printf("두 번째 파일명: ");
    fgets(fname2, sizeof(fname2), stdin);
    fname2[strcspn(fname2, "\n")] = '\0';

    if ((fp1 = fopen(fname1, "r")) == NULL || (fp2 = fopen(fname2, "r")) == NULL) {
        fprintf(stderr, "파일을 열 수 없습니다.\n");
        exit(1);
    }

    while ((fgets(buffer1, sizeof(buffer1), fp1) != NULL) && (fgets(buffer2, sizeof(buffer2), fp2) != NULL)) {
        line++;
        if (strcmp(buffer1, buffer2) != 0) {
            printf("%s %zu << %s", fname1, line, buffer1);
            printf("%s %zu >> %s", fname2, line, buffer2);
            puts("");
            fclose(fp1);
            fclose(fp2);
            return 0;
        }
    }

    fclose(fp1);
    fclose(fp2);
    puts("파일은 서로 일치함");

    return 0;
}
