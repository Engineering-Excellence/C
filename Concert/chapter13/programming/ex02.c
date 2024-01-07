/* 배열의 평균을 계산 */
#include <stdio.h>

#define DEBUG

float average(const int *arr, int size);

int main(void) {
    // 테스트 케이스
    int arr[5] = {1, 2, 3, 4, 5};
    printf("평균: %.2f\n", average(arr, 5));

    return 0;
}

float average(const int *arr, int size) {
    float sum = 0.0f;

#ifdef DEBUG
    for (int i = 0; i < size; ++i) {
        printf("DEBUG: arr[%d]=%d\n", i, arr[i]);
    }
    printf("DEBUG: size=%d\n", size);
#endif

    for (int i = 0; i < size; ++i) {
        sum += (float) arr[i];
#ifdef DEBUG
        printf("DEBUG: sum=%.2f\n", sum);
#endif
    }

    return sum / (float) size;
}
