/* 칼로리 계산 */
#include <stdio.h>

#define SIZE 4

enum course {
    Appetizer, Entree, Main, Dessert
};

struct meal {
    char name[256];
    unsigned int calorie;
};

unsigned int get_total_calorie(const struct meal *meals);

int main(void) {
    struct meal meals[SIZE];

    puts("4코스 요리의 이름과 칼로리 정보를 순서대로 입력하세요.");
    for (enum course c = Appetizer; c <= Dessert; c++) {
        printf("%d번째 음식 이름: ", c + 1);
        scanf("%s", meals[c].name);
        printf("%d번째 음식 칼로리(kcal): ", c + 1);
        scanf("%d", &meals[c].calorie);
    }

    printf("4코스 요리 칼로리 총합: %u kcal", get_total_calorie(meals));

    return 0;
}

unsigned int get_total_calorie(const struct meal *meals) {
    unsigned int sum = 0;

    for (int i = 0; i < SIZE; ++i) {
        sum += meals[i].calorie;
    }

    return sum;
}
