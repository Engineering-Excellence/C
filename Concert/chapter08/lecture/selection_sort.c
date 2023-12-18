/*
 * 선택 정렬(Selection Sort)
 *
 * 시간 복잡도: O(n²)
 * 전체 배열에서 최솟값을 탐색한 다음, 배열의 첫 번째 원소와 교환
 */
#include <stdio.h>

#define SIZE 10

int main(void) {
    int list[SIZE] = {3, 2, 9, 7, 1, 4, 8, 0, 6, 5};
    int temp, least;

    for (int i = 0; i < SIZE - 1; ++i) {
        least = i;  // i번째 값을 최솟값으로 가정

        // 최솟값 탐색
        for (int j = i + 1; j < SIZE; ++j) {
            if (list[j] < list[least]) {
                least = j;
            }
        }

        // i번째 원소와 least 위치의 원소를 교환
        temp = list[i];
        list[i] = list[least];
        list[least] = temp;
    }

    for (int i = 0; i < SIZE; ++i) {
        printf("%d ", list[i]);
    }
    printf("\n");

    return 0;
}
