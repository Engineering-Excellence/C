/* 공용체 */
#include <stdio.h>

union ip_address {  // 공용체 정의
    unsigned long laddr;
    unsigned char saddr[4];
};

int main(void) {
    union ip_address addr;  // 공용체 변수 선언

    addr.saddr[0] = 1;
    addr.saddr[1] = 0;
    addr.saddr[2] = 0;
    addr.saddr[3] = 127;

    printf("%lx\n", addr.laddr);

    return 0;
}
