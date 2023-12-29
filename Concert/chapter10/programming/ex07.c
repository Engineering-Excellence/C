/* 단어 게임 */
#include <stdio.h>
#include <string.h>

int main(void) {
    const char answer[] = "hangman";
    char reveal[sizeof(answer)];    // 드러난 글자
    char reply;
    unsigned char cnt = 10; // 시도 횟수

    memset(reveal, '_', sizeof(reveal) - 1);    // 마지막 인덱스를 위해 1 바이트를 남김
    reveal[sizeof(reveal) - 1] = '\0';      // 배열의 끝에 null 문자를 추가

    do {
        printf("(남은 횟수 %d): %s\n", cnt, reveal);
        printf("글자를 추측하세요: ");
        scanf(" %c", &reply);
        for (int i = 0; i < sizeof(answer) - 1; ++i) {
            if (reply == answer[i]) reveal[i] = reply;
        }

        if (!strcmp(reveal, answer)) {
            printf("정답입니다! %s\n", answer);
            return 0;
        }
    } while (--cnt > 0);

    printf("실패... 정답: %s\n", answer);
    puts("GAME OVER");

    return 0;
}
