/* Monte Carlo Simulation: 동전 던지기 게임 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void game(int player) {
    srand((unsigned) time(NULL));
    int computer = rand() % 2;
    printf("player: %d(%s), computer: %d(%s)\n", player, player ? "뒤" : "앞", computer, computer ? "뒤" : "앞");
    printf("%s\n", player == computer ? "승" : "패");
}

void main(void) {
    char player;

    while (1) {
        printf("동전의 면을 입력하세요(0: 앞, 1: 뒤).: ");
        scanf(" %c", &player);

        switch (player) {
            case '0':
            case '1':
                game(player - '0');
                break;
            case 'q':
            case 'Q':
                exit(0);
            default:
                printf("잘못 입력하셨습니다.\n");
                break;
        }
    }
}
