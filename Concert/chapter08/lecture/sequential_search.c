/*
 * 순차 탐색(Sequential Search)
 *
 * 시간 복잡도: O(n)
 * 정렬되지 않은 배열의 원소들을 처음부터 마지막까지 하나씩 탐색
 * 탐색키(Search Key: 우리가 찾는 데이터)와 일치하는 항목을 찾을 때까지 탐색키와 배열의 모든 원소를 비교
 */
#include <stdio.h>

#define SIZE 10

int main(void) {
    int key;
    int list[SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    printf("탐색할 값을 입력하세요.: ");
    scanf("%d", &key);

    for (int i = 0; i < SIZE; ++i) {
        if (list[i] == key) {
            printf("탐색 성공 인덱스: %d\n", i);
        }
    }
    printf("탐색 종료\n");

    return 0;
}
