/**
 * Chapter12 소켓을 이용한 통신 (1): 연결 지향형 모델
 *
 * 학습목표
 * 연결형 통신 모델에 대해서 이해한다.
 * 연결형 통신 모델에서 사용하는 함수에 대해서 이해한다.
 * 연결형 통신 모델을 사용하는 프로그램 작성법에 대해서 이해한다.
 */

#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#define SIZE sizeof(struct sockaddr_in)

int main(void) {
    int sockfd_listen;  // 클라이언트의 연결 요청을 기다리는 용도로 사용되는 소켓 기술자
    int sockfd_connect; // 클라이언트와 연결하여 메시지를 주고받는 용도로 사용되는 소켓 기술자
    char c;
    struct sockaddr_in server = {AF_INET/* 인터넷 기반 */, 5000, INADDR_ANY/* 호스트 주소 자동 할당(커널) */};    // 통신 유형에 관한 자기 자신의 정보

    puts("socket()");
    sockfd_listen = socket(AF_INET/* IPv4*/, SOCK_STREAM/* 연결형 */, 0/* 기본값(TCP) */);    // IPv4 기반의 연결형 모델(TCP)로 소켓 생성

    puts("bind()");
    if (bind(sockfd_listen, (struct sockaddr *) &server, SIZE) == -1) { // 서버와 소켓을 연결
        perror("fail to call bind()");
        exit(EXIT_FAILURE);
    }

    puts("listen()");
    listen(sockfd_listen, 5);   // 소켓을 클라이언트의 연결 요청을 기다리는 상태로 변경

    puts("waiting for client");
    sockfd_connect = accept(sockfd_listen, NULL, NULL); // 대기하다가 클라이언트가 연결 요청시 수락 후 새로운 소켓 생성
    puts("accepted");

    recv(sockfd_connect, &c, 1, 0); // 소켓을 통해 클라이언트가 보낸 메시지를 수신
    printf("recv %c from client\n", c++);

    printf("send %c to client\n", c);
    send(sockfd_connect, &c, 1, 0); // 소켓을 통해 클라이언트로 메시지를 전송

    puts("close()");
    close(sockfd_connect);  // 소켓 닫기
    close(sockfd_listen);

    return EXIT_SUCCESS;
}