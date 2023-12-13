/* 소문자를 대문자로 변환하는 프로그램 */
#include <stdio.h>
#include <ctype.h>

int main(void) {
    char letter;

    while (1) {
        printf("소문자를 입력하세요.: ");
        scanf("%c", &letter);   // 공백 문자 제외

        if (letter == 'Q') break;
        else if (letter < 'a' || letter > 'z') continue;

//        letter -= 32;   // 소문자 → 대문자
        letter = (char) toupper(letter);
        printf("변환된 대문자는 %c입니다.\n", letter);
    }

    return 0;
}
