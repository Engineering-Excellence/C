#include <stdlib.h>
#include <stdio.h>

int main(void) {
    printf("%s\n", getenv("APPLE"));
    unsetenv("APPLE");

    if (!getenv("APPLE"))
        printf("APPLE not found\n");

    return EXIT_SUCCESS;
}
