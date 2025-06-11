/**
 * gethostbyaddr
 *
 * @headerfile netdb.h
 * @brief 호스트명으로 주소와 관련된 정보를 알아온다.
 *
 * @param addr {const char *} 바이너리 형태의 IP 주소(inet_addr 함수가 반환하는 in_addr_t형 포인터)
 * @param len {socklen_t} addr의 바이트 크기
 * @param type {int} 프로토콜 군을 지정
 * @return {struct hostent *} 호출이 성공하면 struct hostent형의 포인터를, 실패하면 NULL을 반환
 */

#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    struct hostent *hent;
    in_addr_t ipaddr;
    char **ptr;

    if (argc < 2) {
        fprintf(stderr, "%s is ip_address\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if ((ipaddr = inet_addr(argv[1])) == -1) {
        perror("fail to call inet_addr()");
        exit(EXIT_FAILURE);
    }

    if ((hent = gethostbyaddr((char *) &ipaddr, 4, AF_INET)) == NULL) { // 바이너리 형태의 이진 주소를 사용하여 호스트 정보 획득
        perror("fail to call gethostbyaddr()");
        exit(EXIT_FAILURE);
    }

    printf("official name: %s\n", hent->h_name);

    for (ptr = hent->h_aliases; *ptr != NULL; *ptr++)
        printf("\talias: %s\n", *ptr);

    if (hent->h_addrtype == AF_INET) {
        ptr = hent->h_addr_list;
        for (; *ptr != NULL; ptr++)
            printf("\taddress: %s\n", inet_ntoa(*((struct in_addr *) *ptr)));
    }

    return 0;
}