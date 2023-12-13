#include <stdio.h>

int all_files;

extern void sub();

static int this_file;

int main(void) {
    sub();
    printf("%d\n", all_files);

    return 0;
}
