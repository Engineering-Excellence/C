#include <stdio.h>

int main(void) {
    int grade, n;
    float sum, average;

    // 필요한 변수들을 초기화한다.
    n = 0;
    sum = 0;
    grade = 0;

    printf("성적 입력을 종료하려면 음수를 입력하세요.\n");

    // 성적을 입력받아서 합계를 구하고 학생 수를 센다.
    while (grade >= 0) {    // grade가 0 이상이면 반복
        printf("성적을 입력하세요.: ");
        scanf("%d", &grade);

        sum += grade;
        n++;
    }

    // 센티널을 제거한다.
    sum -= grade;
    n--;

    // 평균을 계산하고 화면에 출력한다.
    average = sum / n;
    printf("성적의 평균은 %f입니다.\n", average);

    return 0;
}
