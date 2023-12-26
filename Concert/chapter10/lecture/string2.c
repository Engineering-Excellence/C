#include <stdio.h>

int main(void) {
    char str[] = "komputer";

    printf("%s\n", str);

    str[0] = 'c';   // 문자열의 첫 번째 문자를 'c'로 변경
    printf("%s\n", str);

    return 0;
}
