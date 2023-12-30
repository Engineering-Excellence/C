/* 구조체 배열의 초기화 */
#include <printf.h>

#define SIZE 3

struct student {
    int number;
    char name[20];
    float grade;
};

int main(void) {
    struct student list[SIZE];  // 구조체 배열의 선언

    for (int i = 0; i < SIZE; ++i) {
        printf("학번을 입력하세요.: ");
        scanf("%d", &list[i].number);
        printf("이름을 입력하세요.: ");
        scanf("%s", list[i].name);
        printf("학점을 입력하세요.: ");
        scanf("%f", &list[i].grade);
    }

    for (int i = 0; i < SIZE; ++i) {
        printf("학번: %d, 이름:%s, 학점: %.2f\n", list[i].number, list[i].name, list[i].grade);
    }

    return 0;
}
