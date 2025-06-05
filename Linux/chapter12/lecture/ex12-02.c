/**
 * inet_addr
 *
 * @brief 문자열로 표현된 인터넷 호스트 주소를 바이너리로 변환한다.
 *
 * @param ip_addr {char *} 문자열로 표현된 인터넷 호스트 주소
 * @return {in_addr_t} 바이너리로 변환된 인터넷 호스트 주소, 실패시 -1
 */

/**
 * inet_ntoa
 *
 * @brief 바이너리로 표현된 인터넷 호스트 주소를 문자열로 변환한다.
 *
 * @param n_addr {in_addr_t} 바이너리로 표현된 인터넷 호스트 주소
 * @return {char *} 문자열로 변환된 인터넷 호스트 주소
 */

#include <arpa/inet.h>
#include <stdio.h>

int main(void) {
    char *valid = "197.0.0.1";
    char *invalid = "300.0.0.1";    // 첫번째 옥텟이 범위(0~255)를 초과하여 유효하지 않은 주소

    in_addr_t ipaddr1;  // 32비트 정수형으로 표현된 IP 주소 (네트워크 바이트 순서, Big Endian)
    struct in_addr ipaddr2; // 멤버 s_addr는 in_addr_t 타입

    if ((ipaddr1 = inet_addr(valid)) == -1)
        fprintf(stderr, "invalid: %s\n", valid);
    else
        /* 이진수로 변환된 IP 주소에서 각 옥텟을 추출하여 사람이 읽을 수 있는 도트 표기법으로 출력
           각 옥텟을 추출하기 위해 8비트씩 오른쪽으로 시프트(>>)하고, 마스킹(& 0xFF)함
           x86_64와 ARM64 아키텍처 환경(Little Endian)에서 출력 시 바이트를 역순으로 출력해야 올바른 IP 주소가 표시됨 */
        printf("valid: %d.%d.%d.%d\n",
               (ipaddr1 >> 0) & 0xFF,
               (ipaddr1 >> 8) & 0xFF,
               (ipaddr1 >> 16) & 0xFF,
               (ipaddr1 >> 24) & 0xFF);

    ipaddr2.s_addr = ipaddr1;   // 변환된 바이너리 IP를 in_addr 구조체의 s_addr에 저장

    if ((ipaddr1 = inet_addr(invalid)) == -1)   // 잘못된 IP 문자열을 바이너리 형식으로 변환 시도
        fprintf(stderr, "invalid: %s\n", invalid);
    else
        printf("valid: %x\n", ipaddr1);

    puts(inet_ntoa(ipaddr2));   // 바이너리 형식의 IP 주소를 도트 표기법의 문자열로 변환

    return 0;
}