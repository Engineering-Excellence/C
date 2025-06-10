/**
 * gethostbyname
 *
 * @headerfile netdb.h
 * @brief 호스트명으로 주소와 관련된 정보를 알아온다.
 *
 * @param name {const char *} 호스트명
 * @return {struct hostent *} 호출이 성공하면 struct hostent형의 포인터를, 실패하면 NULL을 반환
 */

#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    struct hostent *hent;
    char **ptr;

    if (argc < 2) {
        fprintf(stderr, "%s hostname\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if ((hent = gethostbyname(argv[1])) == NULL) {  // 호스트명을 이용하여 네트워크 정보 획득
        perror("fail to call gethostbyname()");
        exit(EXIT_FAILURE);
    }

    printf("official name: %s\n", hent->h_name);    // 호스트 정규 이름

    for (ptr = hent->h_aliases; *ptr != NULL; *ptr++)
        printf("\talias: %s\n", *ptr);  // 호스트 보조 이름

    if (hent->h_addrtype == AF_INET) {
        ptr = hent->h_addr_list;
        for (; *ptr != NULL; ptr++)
            printf("\taddress: %s\n", inet_ntoa(*(struct in_addr *) *ptr)); // IPv4 주소 출력
    }

    return 0;
}