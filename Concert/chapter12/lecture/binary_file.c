/* 파일을 이용한 데이터베이스 구현 */
#include <stdio.h>
#include <stdlib.h>

#define SIZE 3

struct student {
    int number;     // 학번
    char name[20];  // 이름
    float gpa;      // 평점
};

int main(void) {
    struct student table[SIZE] = {
            {1, "Kim", 3.99f},
            {2, "Min", 2.68f},
            {3, "Lee", 4.01f}
    };
    struct student s;
    FILE *fp = NULL;

    // 이진 파일을 쓰기 모드로 연다.
    if ((fp = fopen("student.dat", "wb")) == NULL) {
        fprintf(stderr, "입력을 위한 파일을 열 수 없습니다.\n");
        exit(1);
    }

    // 배열을 파일에 저장한다.
    fwrite(table, sizeof(table), 1, fp);

    fclose(fp); // 이진 파일 쓰기모드 닫기

    // 이진 파일을 읽기 모드로 연다.
    if ((fp = fopen("student.dat", "rb")) == NULL) {
        fprintf(stderr, "출력을 위한 파일을 열 수 없습니다.\n");
        exit(1);
    }

    for (size_t i = 0; i < SIZE; i++) {
        fread(&s, sizeof(struct student), 1, fp);
        printf("학번: %d, 이름: %s, 평점: %.2f\n", s.number, s.name, s.gpa);
    }

    fclose(fp); // 이진 파일 열기모드 닫기

    return 0;
}
