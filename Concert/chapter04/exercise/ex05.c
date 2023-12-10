/* 조건 연산자를 이용하여 사용자로부터 입력받은 세 개의 정수 중 가장 큰 수를 출력 */
#include <stdio.h>

#define max(a, b) a > b ? a : b

int main(void) {
    int i, j, k;

    printf("세 개의 정수를 공백으로 구분하여 입력하세요.: ");
    scanf("%d %d %d", &i, &j, &k);

    printf("%d", max(max(i, j), k));

    return 0;
}
