#include <stdio.h>

#define WINDOWS

int main(void) {
#ifdef WINDOWS
    puts("Windows 버전입니다.");
#elifdef MACOS
    puts("macOS 버전입니다.");
#else
    puts("Linux 버전입니다.");
#endif
    return 0;
}
