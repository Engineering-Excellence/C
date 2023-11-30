#include <stdio.h>

int main(void) {

    float x = 1e39; // overflow
    float y = 1.23456e-46;  // underflow

    printf("x = %e\n", x);
    printf("y = %e\n", y);

    return 0;
}