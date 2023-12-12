/* 가위바위보 프로그램 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char *to_string(int i) {
    switch (i) {
        case 0:
            return "가위";
        case 1:
            return "바위";
        case 2:
            return "보";
        default:
            printf("잘못 입력하셨습니다.\n");
            exit(1);    // 프로그램 종료
    }
}

int main(void) {
    int player, computer;

    printf("가위(0), 바위(1), 보(2) 중 하나를 입력하세요.: ");
    scanf("%d", &player);

    srand(time(0)); // 시드값 설정
    computer = rand() % 3;  // 0~2 범위의 랜덤한 정수 생성

    printf("player=%s(%d), computer=%s(%d)\n", to_string(player), player, to_string(computer), computer);

    if (player == computer) {
        printf("비겼습니다.\n");
    } else if (player == 0 && computer == 2 || player == 1 && computer == 0 || player == 2 && computer == 1) {
        printf("당신이 이겼습니다!\n");
    } else if (player == 0 && computer == 1 || player == 1 && computer == 2 || player == 2 && computer == 0) {
        printf("당신이 졌습니다.\n");
    }
    return 0;
}
