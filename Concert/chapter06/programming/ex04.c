#include <stdio.h>

int main(void) {
    double money = 10000000;
    int cnt = 0;

    while (1) {
        cnt++;
        money *= 1.07;
        if (money >= 20000000) break;
    }

    printf("%d년\n", cnt);

    return 0;
}
