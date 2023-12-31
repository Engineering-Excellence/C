/* 열거형 */
#include <stdio.h>
#include <stdlib.h>

enum tvtype {   // 열거형 정의
    tube, lcd, plasma, projection
};

int main(void) {
    enum tvtype type;   // 열거형 변수 선언

    printf("TV 종류 코드를 입력하세요.: ");
    scanf("%d", &type);

    switch (type) {
        case tube:
            puts("브라운관 TV를 선택하셨습니다.");
            break;
        case lcd:
            puts("LCD TV를 선택하셨습니다.");
            break;
        case plasma:
            puts("PDP TV를 선택하셨습니다.");
            break;
        case projection:
            puts("프로젝션 TV를 선택하셨습니다.");
            break;
        default:
            puts("다시 선택하여 주십시오.");
            break;
    }

    return 0;
}
