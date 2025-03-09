#include <stdio.h>

int main() {
    int a, b;
    a = b = 1;
    if (a = 2)  // a = 2 대입 후 2를 조건으로 사용 -> 참
        b = a + 1;  // a = 2, b = 3
    else if (a == 1)
        b = b + 1;
    else
        b = 10;
    printf("%d, %d\n", a, b);
}
