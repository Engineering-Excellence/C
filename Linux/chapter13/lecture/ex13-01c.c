/**
 * Chapter13 소켓을 이용한 통신 (2): 비연결 지향형 모델과 관련 함수
 *
 * 학습목표
 * 비연결형 통신 모델에 대해서 이해한다.
 * 비연결형 통신 모델에서 사용하는 함수에 대해서 이해한다.
 */

#include <netdb.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#define SIZE sizeof(struct sockaddr_in)

int main(void) {
    int sockfd;
    char msg, hostname[1024], *ipaddr;

    struct hostent *hent;   // 시스템 네트워크 정보 변수
    struct sockaddr_in server = {AF_INET, 2007};    // 메시지를 전송할 대상인 서버의 통신 정보
    socklen_t server_len = SIZE;

    gethostname(hostname, 1024);    // 자신의 호스트명 확인
    printf("host name: %s\n", hostname);

    hent = gethostbyname(hostname); // 지정한 호스트(자신)의 네트워크 정보
    ipaddr = inet_ntoa(*((struct in_addr *) hent->h_addr_list[0])); // 바이너리 형태의 IP 주소를 문자열로 변환
    printf("official name: %s\n", hent->h_name);    // FQDN 형태의 공식 이름 출력
    printf("IP address: %s\n", ipaddr);

    server.sin_addr.s_addr = inet_addr(ipaddr); // 메시지를 전송할 대상인 서버(자신)의 주소를 지정
    // server.sin_addr.s_addr = inet_addr("172.30.1.55"); // 메시지를 전송할 대상인 서버의 주소를 지정

    sockfd = socket(AF_INET, SOCK_DGRAM/* 비연결형 */, 0/* 기본값(UDP) */);    // 비연결형 모델 소켓을 생성

    msg = 'A';
    sendto(sockfd, &msg, 1, 0, (struct sockaddr *) &server, server_len);    // 소켓을 통해 서버로 지정한 호스트로 메시지를 전송
    recvfrom(sockfd, &msg, 1, 0, (struct sockaddr *) &server, &server_len); // 송신자 서버 정보 저장 후 메시지 읽기
    printf("recv from server: %c\n", msg);

    close(sockfd);  // 소켓 닫기

    return EXIT_SUCCESS;
}