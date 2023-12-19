#include <stdio.h>

int main(void) {
    int days[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    for (int i = 0; i < sizeof(days) / sizeof(days[0]); ++i) {
        printf("%d월은 %d일까지 있습니다.\n", i + 1, days[i]);
    }

    return 0;
}
