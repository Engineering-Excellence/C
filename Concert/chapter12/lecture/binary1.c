/* 이진 파일 쓰기 */
#include <stdio.h>

int main(void) {
    int buffer[] = {10, 20, 30, 40, 50};
    FILE *fp = NULL;
    size_t size, count;

    fp = fopen("./binary.bin", "wb");     // 파일을 (쓰기 + 이진 파일) 모드로 연다.
    if (fp == NULL) {
        fprintf(stderr, "binary.bin 파일을 열 수 없습니다.\n");
        return 1;
    }

    size = sizeof(buffer[0]);
    count = sizeof(buffer) / size;

    // fwrite(메모리 블록 주소, 항목 크기, 항목 개수, 파일 스트림);
    fwrite(buffer, size, count, fp);   // count 만큼의 항목을 buffer에서 fp로 쓴다.

    fclose(fp);

    return 0;
}
