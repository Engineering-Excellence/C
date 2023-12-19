/* 시험 점수 통계 처리 */
#include <stdio.h>

#define STUDENTS 5
#define EXAMS 3

int max(int a, int b);

int min(int a, int b);

int main(void) {
    int score[STUDENTS][EXAMS] = {{30, 10, 11},
                                  {40, 90, 32},
                                  {70, 65, 56},
                                  {70, 43, 32},
                                  {80, 10, 89}};
    int rank[STUDENTS] = {1, 2, 3, 4, 5};
    int total[STUDENTS] = {0};
    int most, least, subtotal, mode, temp;

    // (a) 각 시험마다 최고점수, 최저점수, 평균점수 출력
    for (int exam = 0; exam < EXAMS; ++exam) {
        most = least = score[0][exam];
        subtotal = 0;
        for (int student = 0; student < STUDENTS; ++student) {
            most = max(most, score[student][exam]);
            least = min(least, score[student][exam]);
            subtotal += score[student][exam];
        }
        printf("시험 #%d - 최고점수: %d, 최저점수: %d, 평균점수: %d\n", exam + 1, most, least, subtotal / STUDENTS);
    }

    printf("\n");

    // (b) 각 학생마다 최고점수, 최저점수, 평균점수 출력
    for (int student = 0; student < STUDENTS; ++student) {
        most = least = score[student][0];
        subtotal = 0;
        for (int exam = 0; exam < EXAMS; ++exam) {
            most = max(most, score[student][exam]);
            least = min(least, score[student][exam]);
            subtotal += score[student][exam];
        }
        printf("학번 %d - 최고점수: %d, 최저점수: %d, 평균점수: %d\n", student + 1, most, least, subtotal / EXAMS);
    }

    printf("\n");

    // (c) 각 시험마다 산술 평균값, 최빈값을 출력
    for (int exam = 0; exam < EXAMS; ++exam) {
        subtotal = 0;
        mode = score[0][exam];
        int freq[101] = {0};
        for (int student = 0; student < STUDENTS; ++student) {
            subtotal += score[student][exam];
            if (freq[mode] < ++freq[score[student][exam]]) {
                mode = score[student][exam];
            }
        }
        printf("시험 #%d - 산술 평균: %d, 최빈값: %d\n", exam + 1, subtotal / STUDENTS, mode);
    }

    printf("\n");

    // (d) 각 학생별 총점 기준 정렬
    for (int student = 0; student < STUDENTS; ++student) {
        for (int exam = 0; exam < EXAMS; ++exam) {
            total[student] += score[student][exam];
        }
    }
    for (int i = 0; i < STUDENTS - 1; ++i) {
        most = i;
        for (int j = i + 1; j < STUDENTS; ++j) {
            if (total[most] < total[j]) {
                most = j;
            }
        }
        if (most != i) {
            temp = total[i];
            total[i] = total[most];
            total[most] = temp;
            temp = rank[i];
            rank[i] = rank[most];
            rank[most] = temp;
        } else {
            continue;
        }
    }
    for (int student = 0; student < STUDENTS; ++student) {
        printf("학번 %d: %3d점\n", rank[student], total[student]);
    }

    return 0;
}

int max(int a, int b) {
    return a > b ? a : b;
}

int min(int a, int b) {
    return a < b ? a : b;
}
