/* 임의 접근 */
#include <stdio.h>
#include <stdlib.h>

#define SIZE 1000

void init_table(int *table, int size);

int main(void) {
    int table[SIZE];
    int n, data;
    long pos;
    FILE *fp = NULL;

    // 배열을 초기화한다.
    init_table(table, SIZE);

    // 이진 파일을 쓰기 모드로 연다.
    if ((fp = fopen("sample.dat", "wb")) == NULL) {
        fprintf(stderr, "입력을 위한 파일을 열 수 없습니다.\n");
        exit(1);
    }

    // 배열을 이진 모드로 파일에 저장한다.
    fwrite(table, sizeof(table), 1, fp);

    fclose(fp); // 이진 쓰기 모드 종료

    // 이진 파일을 읽기 모드로 연다.
    if ((fp = fopen("sample.dat", "rb")) == NULL) {
        fprintf(stderr, "출력을 위한 파일을 열 수 없습니다.\n");
        exit(1);
    }

    // 사용자가 선택한 위치의 정수를 파일로부터 읽는다.
    while (1) {
        printf("파일에서의 위치를 입력하세요(0에서 %d, 종료: -1): ", SIZE - 1);
        scanf("%d", &n);
        if (n < 0) break;
        pos = (long) n * sizeof(table[0]);
        fseek(fp, pos, SEEK_SET);   // pos 위치로 위치 표시자를 이동한다.
        fread(&data, sizeof(table[0]), 1, fp);
        printf("%d 위치의 값은 %d입니다.\n", n, data);
    }

    fclose(fp); // 이진 읽기 모드 종료

    return 0;
}

// 배열을 인덱스의 제곱으로 초기화한다.
void init_table(int *table, int size) {
    for (int i = 0; i < size; ++i) {
        table[i] = i * i;
    }
}
