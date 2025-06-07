/**
* Chapter13 소켓을 이용한 통신 (2): 비연결 지향형 모델과 관련 함수
 *
 * 학습목표
 * 비연결형 통신 모델에 대해서 이해한다.
 * 비연결형 통신 모델에서 사용하는 함수에 대해서 이해한다.
 */

#include <sys/utsname.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#define SIZE sizeof(struct sockaddr_in)

int main(void) {
    int sockfd;
    char msg;

    struct utsname info;    // 시스템 정보 변수
    struct hostent *hent;   // 네트워크 정보 변수

    struct sockaddr_in server = {/*sizeof(server), */AF_INET, 2007, INADDR_ANY};    // 서버 통신 정보 변수
    struct sockaddr_in client;  // 클라이언트 통신 정보 변수
    socklen_t client_len = SIZE;

    uname(&info);   // 시스템 정보 확인
    printf("node name: %s\n", info.nodename);   // 서버 호스트명 출력

    hent = gethostbyname(info.nodename);    // 서버 호스트의 네트워크 정보
    printf("official name: %s\n", hent->h_name);    // FQDN 형태의 공식 이름 출력

    sockfd = socket(AF_INET, SOCK_DGRAM/* 비연결형 */, 0/* 기본값(UDP) */);    // 비연결형 모델 소켓을 생성

    if (bind(sockfd, (struct sockaddr *) &server, SIZE) == -1) {    // 소켓에 서버 네트워크 정보를 연결
        perror("fail to call bind()\n");
        exit(EXIT_FAILURE);
    }

    recvfrom(sockfd, &msg, 1, 0, (struct sockaddr *) &client, &client_len); // 송신자 클라이언트 정보 저장 후 메시지 읽기
    printf("recv from client: %c\n", msg);

    sendto(sockfd, &msg, 1, 0, (struct sockaddr *) &client, client_len);    // 수신한 메시지를 소켓을 통해 클라이언트 호스트로 전송

    close(sockfd);  // 소켓 닫기

    return EXIT_SUCCESS;
}