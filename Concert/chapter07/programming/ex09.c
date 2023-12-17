/* 계산기 */
#include <stdio.h>

//unsigned int add_cnt, sub_cnt, mul_cnt, div_cnt; // 전역 변수

void add(float x, float y);

void subtract(float x, float y);

void multiply(float x, float y);

void divide(float x, float y);

int main(void) {
    float x, y;
    char op = '\0';

    while (1) {
        printf("연산을 입력하세요.: ");
        scanf("%f %c %f", &x, &op, &y);
        while (getchar() != '\n');  // 입력 버퍼 비우기

        switch (op) {
            case '+':
                add(x, y);
                op = '\0';
                break;
            case '-':
                subtract(x, y);
                op = '\0';
                break;
            case '*':
                multiply(x, y);
                op = '\0';
                break;
            case '/':
                divide(x, y);
                op = '\0';
                break;
            default:
                return 0;
        }
    }
}

void add(float x, float y) {
    static unsigned int add_cnt;    // 정적 지역 변수

    printf("연산 결과: %f\n", x + y);
    printf("덧셈은 총 %d번 실행되었습니다.\n", ++add_cnt);
}

void subtract(float x, float y) {
    static unsigned int sub_cnt;

    printf("연산 결과: %f\n", x - y);
    printf("뺄셈은 총 %d번 실행되었습니다.\n", ++sub_cnt);
}

void multiply(float x, float y) {
    static unsigned int mul_cnt;

    printf("연산 결과: %f\n", x * y);
    printf("곱셈은 총 %d번 실행되었습니다.\n", ++mul_cnt);
}

void divide(float x, float y) {
    static unsigned int div_cnt;

    printf("연산 결과: %f\n", x / y);
    printf("나눗셈은 총 %d번 실행되었습니다.\n", ++div_cnt);
}
