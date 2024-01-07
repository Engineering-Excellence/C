#include <stdio.h>
#include "../include/array.h"

/**
 * get_sum_of_array
 *
 * @param arr 정수 배열
 * @param size arr의 원소들의 개수
 * @return arr 원소들의 합
 */
int get_sum_of_array(const int *arr, int size) {
    int sum = 0;

    for (int i = 0; i < size; ++i) {
        sum += arr[i];
    }

    return sum;
}

/**
 * get_average_of_array
 *
 * @param arr 정수 배열
 * @param size arr의 원소들의 개수
 * @return arr 원소들의 산술 평균
 */
float get_average_of_array(const int *arr, int size) {

    return (float) get_sum_of_array(arr, size) / (float) size;
}

/**
 * print_array
 *
 * @param arr 정수 배열
 * @param size arr의 원소들의 개수
 */
void print_array(const int *arr, int size) {

    for (int i = 0; i < size; ++i) {
        printf("%d ", arr[i]);
    }
    puts("");
}
