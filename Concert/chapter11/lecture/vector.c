/* 구조체를 함수의 반환값으로 넘기는 방법 */
#include <stdio.h>

struct vector {
    float x;
    float y;
};

struct vector get_vector_sum(struct vector a, struct vector b);

int main(void) {
    struct vector a = {2.0f, 3.0f};
    struct vector b = {5.0f, 6.0f};
    struct vector sum = get_vector_sum(a, b);

    printf("벡터의 합은 (%.1f, %.1f)입니다.\n", sum.x, sum.y);

    return 0;
}

struct vector get_vector_sum(struct vector a, struct vector b) {
    struct vector result;

    result.x = a.x + b.x;
    result.y = a.y + b.y;

    return result;
}
