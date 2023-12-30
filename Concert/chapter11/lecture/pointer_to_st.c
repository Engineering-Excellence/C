/* 포인터를 통한 구조체 참조 */
#include <stdio.h>

struct student {
    int number;
    char name[10];
    float grade;
};

int main(void) {
    struct student s = {20230001, "홍길동", 4.3f};
    struct student *p;  // 구조체를 가리키는 포인터

    p = &s;

    printf("학번: %d, 이름: %s, 학점: %.2f\n", s.number, s.name, s.grade);
    printf("학번: %d, 이름: %s, 학점: %.2f\n", (*p).number, (*p).name, (*p).grade);
    printf("학번: %d, 이름: %s, 학점: %.2f\n", p->number, p->name, p->grade); // 간접 멤버 연산자

    return 0;
}
