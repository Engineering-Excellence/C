#include <stdio.h>

int main(void) {
//    int grade[5] = {31, 63, 62, 87, 14}; // 배열의 초기화
//    int grade[5] = {31, 63}; // 배열 원소의 개수가 초깃값보다 많은 경우
    int grade[5];   // 초깃값이 주어지지 않을 경우

    for (int i = 0; i < 5; ++i) {
        printf("grade[%d] = %d\n", i, grade[i]);
    }

    return 0;
}
