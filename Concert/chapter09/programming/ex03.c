/* ISBN 유효성 검사 */
#include <stdio.h>

#define SIZE 13

void input_isbn(int values[]);

int is_valid_isbn(int values[]);

int main(void) {
    int isbn[SIZE];

    input_isbn(isbn);

    /*
        printf("입력한 ISBN 번호: ");
        for (int i = 0; i < SIZE; ++i) {
            printf("%d", isbn[i]);
        }
        printf("\n");
     */

    printf("%s ISBN 번호입니다.\n", is_valid_isbn(isbn) ? "유효한" : "유효하지 않은");

    return 0;
}

void input_isbn(int values[]) {
    long long int num;
    printf("ISBN 번호를 입력하세요.: ");
    scanf("%lld", &num);
    for (int i = SIZE - 1; i >= 0; --i) {
        values[i] = num % 10;
        num /= 10;
    }
}

int is_valid_isbn(int values[]) {
    int check_sum = 0;

    for (int i = 0; i < SIZE - 1; ++i) {
        check_sum += i % 2 ? 3 * values[i] : values[i];
    }
    check_sum += values[SIZE - 1];
//    printf("check_sum = %d\n", check_sum);

    return check_sum % 10 == 0;
}
