#include <unistd.h>

void __libc_start_main(void) {
    write(1, "Hello, World!\n", 14);
}

int main(void) {
    return 0;
}