/* 절대평가 학점 계산 프로그램 */
#include <stdio.h>

int main(void) {
    int mid_score, fin_score;
    char grade;

    printf("중간고사 점수를 입력하세요.: ");
    scanf("%f", &mid_score);
    printf("기말고사 점수를 입력하세요.: ");
    scanf("%f", &fin_score);

    switch ((mid_score + fin_score) / 20) {
        case 10:
        case 9:
            grade = 'A';
            break;
        case 8:
            grade = 'B';
            break;
        case 7:
            grade = 'C';
            break;
        case 6:
            grade = 'D';
            break;
        default:
            grade = 'F';
            break;
    }

    printf("당신의 학점은 %c학점입니다.", grade);

    return 0;
}
