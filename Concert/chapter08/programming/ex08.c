#include <stdio.h>

#define SEATS 10

int main(void) {
    int seats[SEATS] = {0};

    do {
        char reply;
        printf("좌석을 예약하시겠습니까?(y 또는 n) ");
        scanf(" %c", &reply);

        if (reply == 'y') {
            int seat;
            printf("현재의 예약 상태는 다음과 같습니다.\n");
            printf("------------------------------------------\n");
            for (int i = 0; i < SEATS; ++i) {
                printf("%2d\t", i + 1);
            }
            printf("\n------------------------------------------\n");
            for (int i = 0; i < SEATS; ++i) {
                printf("%2d\t", seats[i]);
            }
            printf("\n몇 번째 좌석을 예약하시겠습니까? ");
            scanf("%d", &seat);
            if (seat <= SEATS && seat >= 1) {
                if (seats[seat - 1] != 0) {
                    printf("이미 예약된 좌석입니다.\n");
                } else {
                    seats[seat - 1] = 1;
                    printf("예약되었습니다.\n");
                }
            } else {
                printf("예약에 실패했습니다.\n");
            }
            for (int i = 0; i < SEATS; ++i) {
                printf("%2d\t", i + 1);
            }
            printf("\n------------------------------------------\n");
            for (int i = 0; i < SEATS; ++i) {
                printf("%2d\t", seats[i]);
            }
            printf("\n");
        } else if (reply == 'n') {
            printf("예약을 종료합니다.\n");
            return 0;
        }
    } while (1);
}
