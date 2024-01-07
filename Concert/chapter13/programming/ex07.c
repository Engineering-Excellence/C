#include <stdio.h>
#include "../include/graphic.h"

int main(void) {
    GRAPHIC graphic;
    unsigned int tmp;

    printf("도형의 종류를 선택하세요.(1: 사각형, 2: 원, 3: 직선): ");
    scanf("%d", &tmp);
    graphic.figure = tmp - 1;

    printf("채우기색을 선택하세요.(1: 없음, 2: red, 3: green, 4: blue): ");
    scanf("%d", &tmp);
    graphic.color = tmp - 1;

    printf("선색을 선택하세요.(1: 없음, 2: red, 3: green, 4: blue): ");
    scanf("%d", &tmp);
    graphic.line_color = tmp - 1;

    printf("선스타일을 선택하세요.(1: 실선, 2: 점선, 3: 파선): ");
    scanf("%d", &tmp);
    graphic.line_style = tmp - 1;

    show_attr(graphic);

    return 0;
}
