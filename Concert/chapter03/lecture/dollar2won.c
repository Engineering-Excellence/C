// 달러화를 원화로 계산하는 프로그램
#include <stdio.h>

int main(void) {

    int usd;    // 달러화
    int krw;    // 원화
    const int EXCHANGE_RATE = 1260;

    printf("달러화 금액을 입력하세요.: "); // 입력 안내 메시지
    scanf("%d", &usd);  // 달러화 금액 입력

    krw = EXCHANGE_RATE * usd;   // 원화로 환산

    printf("달러화 %d달러는 %d원입니다.\n", usd, krw);    // 계산 결과 출력

    return 0;   // 함수 결괏값 반환
}