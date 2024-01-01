#include <stdio.h>

#define SIZE 3

unsigned int empno;

struct employee {
    unsigned int empno;      // 사번
    char name[32];     // 이름
    char contact[16];  // 전화번호
    int age;        // 나이
};

int main(void) {
    struct employee employees[SIZE];

    puts("직원 정보를 입력하세요.");
    for (int i = 0; i < SIZE; ++i) {
        employees[i].empno = ++empno;   // 사번 자동증가
        printf("이름: ");
        scanf("%s", &employees[i].name);
        printf("전화번호: ");
        scanf("%s", &employees[i].contact);
        printf("나이: ");
        scanf("%d", &employees[i].age);
    }

    for (int i = 0; i < SIZE; ++i) {
        if (employees[i].age >= 20 && employees[i].age <= 30) {     // 나이 20 이상 30 이하인 직원만 출력
            printf("사번: %d\t이름: %s\t전화번호: %s\t나이: %d\n", employees[i].empno, employees[i].name, employees[i].contact,
                   employees[i].age);
        }
    }

    return 0;
}
