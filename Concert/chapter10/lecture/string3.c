#include <stdio.h>

int main(void) {
    char str[] = "A barking dog never bites";
    int i = 0;

    while (str[i] != 0) {
        i++;    // NULL 문자가 나올 때까지 반복한다.
    }
    printf("문자열 \"%s\"의 길이는 %d입니다.\n", str, i);

    return 0;
}
