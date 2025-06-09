/**
 * uname
 *
 * @headerfile sys/utsname.h
 * @brief 현재의 호스트 시스템 정보를 구한다.
 *
 * @param name {struct utsname *} 호스트의 시스템 정보
 * @return {int} 호출이 성공하면 0을, 실패하면 -1을 반환
 */

/**
 * gethostname
 *
 * @headerfile unistd.h
 * @brief 현재의 호스트명을 구한다.
 *
 * @param name {char *} 호스트명
 * @param len {size_t} 호스트명의 길이
 * @return {int} 호출이 성공하면 0을, 실패하면 -1을 반환
 */

#include <sys/utsname.h>
#include <unistd.h>
#include <stdio.h>

int main(void) {
    struct utsname info;
    char myname[256];

    uname(&info);
    printf("sysname: %s\n", info.sysname);  // 운영체제명
    printf("nodename: %s\n", info.nodename);    // 호스트명
    printf("release: %s\n", info.release);  // 릴리즈 정보
    printf("version: %s\n", info.version);  // 운영체제 버전
    printf("machine: %s\n", info.machine);  // 머신(CPU)의 종류

    gethostname(myname, 256);
    printf("hostname: %s\n", myname);   // 호스트명

    return 0;
}