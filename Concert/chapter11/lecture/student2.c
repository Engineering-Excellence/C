#include <stdio.h>

struct student {    // 구조체 정의
    int number;
    char name[10];
    double grade;
};

int main(void) {
    struct student s;   // 구조체 변수 선언

    printf("학번을 입력하세요.: ");
    scanf("%d", &s.number); // 구조체 멤버의 주소를 전달한다.

    printf("학번을 입력하세요.: ");
    scanf("%s", s.name);

    printf("학점을 입력하세요.: ");
    scanf("%lf", &s.grade); // double 형의 값을 입력받을 때는 %lf를 사용한다.

    printf("학번: %d\n", s.number);
    printf("이름: %s\n", s.name);
    printf("학점: %.2f\n", s.grade);

    return 0;
}
