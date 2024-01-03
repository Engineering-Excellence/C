/* 형식화된 입출력 */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    FILE *fp;
    char fname[100], name[20];
    int number, count = 0;
    float score, total = 0.0f;

    printf("성적 파일명을 입력하세요.: ");
    scanf("%s", fname);

    // 성적 파일을 쓰기 모드로 연다.
    if ((fp = fopen(fname, "w")) == NULL) {
        fprintf(stderr, "성적 파일 %s을 열 수 없습니다.\n", fname);
        exit(1);
    }

    // 사용자로부터 학번, 이름, 성적을 입력받아서 파일에 저장한다.
    while (1) {
        printf("학번, 이름, 성적을 입력하세요(음수 입력시 종료).: ");
        scanf("%d", &number);
        if (number < 0 ) break;
        scanf("%s %f", name, &score);
        fprintf(fp, "%d %s %f\n", number, name, score);     // 파일에 정수, 문자열, 실수 형태로 데이터를 쓴다.
    }

    fclose(fp);     // 파일 쓰기 모드 종료

    // 성적 파일을 읽기 모드로 연다.
    if ((fp = fopen(fname, "r")) == NULL) {
        fprintf(stderr, "성적 파일 %s을 열 수 없습니다.\n", fname);
        exit(1);
    }

    // 파일에서 성적을 읽어서 평균을 구한다.
    while (!feof(fp)) {
        fscanf(fp, "%d %s %f", &number, name, &score);      // 파일에 정수, 문자열, 실수 형태로 데이터를 읽는다.
        total += score;
        count++;
    }

    printf("평균: %.2f\n", total / count);
    fclose(fp);     // 파일 읽기 모드 종료

    return 0;
}
