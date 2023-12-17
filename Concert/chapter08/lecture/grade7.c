/* 막대 그래프 그리기 */
#include <stdio.h>

#define STUDENTS 5

int main(void) {
    int grade[STUDENTS] = {30, 20, 10, 40, 50}; // 배열의 정의와 초기화

    for (int i = 0; i < STUDENTS; ++i) {
        printf("번호 %d: ", i);
        for (int j = 0; j < grade[i]; ++j) {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}
