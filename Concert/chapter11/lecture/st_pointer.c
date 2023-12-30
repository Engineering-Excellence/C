/* 포인터를 멤버로 가지는 구조체 */
#include <stdio.h>

struct date {
    int month;
    int day;
    int year;
};

struct student {
    int number;
    char name[10];
    float grade;
    struct date *dob;   // date of birth: 포인터가 구조체의 멤버
};

int main(void) {
    struct date d = {3, 20, 2000};
    struct student s = {20190001, "Kim", 4.3f};

    s.dob = &d;

    printf("학번: %d\n", s.number);
    printf("이름: %s\n", s.name);
    printf("학점: %.2f\n", s.grade);
    printf("생년월일: %d년 %d월 %d일\n", s.dob->year, s.dob->month, s.dob->day);

    return 0;
}
