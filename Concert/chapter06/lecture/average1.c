/* break를 이용하여 무한 루프를 탈출한다. */
#include <stdio.h>

int main(void) {
    float sum = 0, grade, average;
    int cnt = 0;

    while (1) {
        printf("학생 성적을 입력하세요.: ");
        scanf("%f", &grade);    // 실수 형태로 입력받는다.

        if (grade < 0) break;   // 음수가 입력되면 반복 루프를 탈출한다.

        cnt++;
        sum += grade;
    }

    average = sum / cnt;
    printf("학생들의 성적의 평균은 %f입니다.", average);

    return 0;
}
