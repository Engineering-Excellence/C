#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    int freq[10] = {0};
    int most;

    srand((unsigned) time(NULL));
    for (int i = 0; i < 100; ++i) {
        freq[rand() % 10]++;
    }
    most = 0;
    for (int i = 0; i < 10; ++i) {
        if (freq[most] < freq[i]) {
            most = i;
        }
        printf("%d ", freq[i]);
    }
    printf("\n가장 많이 생성된 수: %d\n", most);

    return 0;
}
