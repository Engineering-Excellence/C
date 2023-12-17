#include <stdio.h>

#define STUDENTS 5   // 기호 상수: 배열의 크기를 나타낸다.

int main(void) {
    int grade[STUDENTS]; // 배열 정의
    int sum = 0;
    int average;

    for (int i = 0; i < STUDENTS; ++i) {
        printf("학생들의 성적을 입력하세요.: ");    // 학생들의 성적을 키보드로부터 받는다.
        scanf("%d", &grade[i]);
        sum += grade[i];    // 성적의 합계를 구한다.
    }

    // 평균을 구하고 출력한다.
    average = sum / STUDENTS;
    printf("성적 평균: %d\n", average);

    return 0;
}
