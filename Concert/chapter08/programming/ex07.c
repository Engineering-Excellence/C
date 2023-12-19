#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    int dice[6] = {0};

    srand((unsigned) time(NULL));
    for (int i = 0; i < 60000; ++i) {
        dice[rand() % 6]++;
    }

    printf("주사위면\t빈도\n");
    for (int i = 0; i < 6; ++i) {
        printf("%4d\t%5d\n", i + 1, dice[i]);
    }

    return 0;
}
