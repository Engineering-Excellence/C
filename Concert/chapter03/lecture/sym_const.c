#include <stdio.h>

int main(void) {

    const int MONTHS = 12;  // 기호 상수 선언
    int m_salary;
    int y_salary; // 변수 선언

    printf("월급을 입력하세요: ");  // 입력 안내문
    scanf("%d", &m_salary);

    y_salary = MONTHS * m_salary;   // 순수입 계산
    printf("연봉은 %d입니다.\n", y_salary);

    return 0;
}
