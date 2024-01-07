#include <stdio.h>
#include "../include/graphic.h"

const char *figures[3] = {"사각형", "원", "직선"};
const char *colors[4] = {"없음", "red", "green", "blue"};
const char *styles[3] = {"실선", "점선", "파선"};

void show_attr(GRAPHIC graphic) {
    puts("\n당신이 선택한 도형의 속성은 다음과 같습니다.");
    printf("도형의 종류: %s\n", figures[graphic.figure]);
    printf("채우기색: %s\n", colors[graphic.color]);
    printf("선색: %s\n", colors[graphic.line_color]);
    printf("선스타일: %s\n", styles[graphic.line_style]);
}
