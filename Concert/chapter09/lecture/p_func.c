/* 배열이 함수로 전달되는 경우 */
#include <stdio.h>

#define SIZE 5

void check_values(int values[], int n);

double get_avg(const int values[], int n);

int main(void) {
    int data[SIZE];

    for (int i = 0; i < SIZE; ++i) {
        printf("값을 입력하세요.: ");
        scanf("%d", &data[i]);  // i번째 배열 원소에 저장
    }

    // 배열을 함수에 전달한다.
    check_values(data, SIZE);
    printf("평균값: %lf\n", get_avg(data, SIZE));

    return 0;
}

void check_values(int values[], int n) {    // 배열의 경우 원본이 전달된다.
    for (int i = 0; i < n; ++i) {
        if (values[i] < 0) values[i] = 0;  // 원본 배열이 변경된다.
    }
}

double get_avg(const int values[], int n) {
    double sum = 0.0;
    for (int i = 0; i < n; ++i) {
        sum += values[i];
    }
    return sum / n;
}
