/* 3개 학급의 학생들의 평균 성적 구하기 */
#include <stdio.h>

#define CLASSES 3
#define STUDENTS 5

int main(void) {
    int s[CLASSES][STUDENTS] = {
            {0,  1,  2,  3,  4},    // 첫 번째 행의 원소들의 초깃값
            {10, 11, 12, 13, 14},   // 두 번째 행의 원소들의 초깃값
            {20, 21, 22, 23, 24},   // 세 번째 행의 원소들의 초깃값
    };
    int total, subtotal;

    total = 0;
    for (int class = 0; class < CLASSES; ++class) {
        subtotal = 0;
        for (int student = 0; student < STUDENTS; ++student) {
            subtotal += s[class][student];
        }
        printf("학급 %d의 평균 성적: %d\n", class, subtotal / STUDENTS);
        total += subtotal;
    }
    printf("전체 학생들의 평균 성적: %d\n", total / (CLASSES * STUDENTS));

    return 0;
}
