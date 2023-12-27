/* sscanf()와 sprintf() */
#include <stdio.h>

int main(void) {
    const char *s1 = "100";
    const char *s2 = "12.93";
    char buffer[128];

    int i;
    double d;
    double result;

    sscanf(s1, "%d", &i);   // s1에서 정수를 추출하여 i에 저장한다.
    sscanf(s2, "%lf", &d);

    result = i + d;

    sprintf(buffer, "%f", result);  // result의 값을 실수 형태로 buffer에 저장한다.
    printf("연산 결과는 %s입니다.\n", buffer);

    return 0;
}
