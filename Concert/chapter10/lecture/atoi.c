/* 전용 함수 사용 */
#include <stdlib.h>
#include <stdio.h>

int main(void) {
    const char *s1 = "100";
    const char *s2 = "12.93";
    char buffer[128];

    int i;
    double d;
    double result;

    i = atoi(s1);   // s1에서 정수를 추출하여 반환한다.
    d = atof(s2);   // s2에서 실수를 추출하여 반환한다.

    result = i + d;

    sprintf(buffer, "%f", result);  // result의 값을 실수 형태로 buffer에 저장한다.
    printf("연산 결과는 %s입니다.\n", buffer);

    return 0;
}
