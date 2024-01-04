/* 텍스트 파일 비교 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(void) {
    FILE *fp1, *fp2;
    char file1[128], file2[128];
    char buffer1[1024], buffer2[1024];

    fp1 = NULL;
    fp2 = NULL;

    printf("첫 번째 파일명: ");
    fgets(file1, sizeof(file1), stdin);
    file1[strcspn(file1, "\n")] = '\0';
    printf("두 번째 파일명: ");
    fgets(file2, sizeof(file2), stdin);
    file2[strcspn(file2, "\n")] = '\0';

    if (((fp1 = fopen(file1, "r")) == NULL) || ((fp2 = fopen(file2, "r")) == NULL)) {
        fprintf(stderr, "파일을 읽을 수 없습니다.\n");
        exit(1);
    }

    while (fgets(buffer1, sizeof(buffer1), fp1) != NULL && fgets(buffer2, sizeof(buffer2), fp2) != NULL) {
        if (strcmp(buffer1, buffer2) != 0) {    // 문자열 버퍼 불일치시 종료
            puts("두 파일은 서로 다릅니다.");
            fclose(fp1);
            fclose(fp2);
            return 0;
        }
    }
    puts("두 파일은 서로 같습니다.");

    fclose(fp1);
    fclose(fp2);

    return 0;
}
