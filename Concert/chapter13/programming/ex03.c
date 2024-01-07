#include <stdio.h>
#include "../include/array.h"

int main(void) {
    // 테스트 케이스
    int arr[5] = {1, 2, 3, 4, 5};
    print_array(arr, 5);
    printf("합계: %d\n", get_sum_of_array(arr, 5));
    printf("평균: %.2f\n", get_average_of_array(arr, 5));

    return 0;
}
