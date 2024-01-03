/* 이진 파일 읽기 */
#include <stdio.h>

#define SIZE 5

int main(void) {
    int buffer[SIZE];
    FILE *fp = NULL;

    if ((fp = fopen("./binary.bin", "rb")) == NULL) {
        fprintf(stderr, "binary.bin 파일을 열 수 없습니다.\n");
        return 1;
    }

    for (size_t i = 0; i < SIZE; ++i) {
        fread(&buffer[i], sizeof(buffer[0]), 1, fp);    // fp에서 정수 하나를 읽는다.
        printf("%d\n", buffer[i]);
    }

    fclose(fp);

    return 0;
}
