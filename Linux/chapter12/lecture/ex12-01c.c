/**
 * Chapter12 소켓을 이용한 통신 (1): 연결 지향형 모델
 *
 * 학습목표
 * 연결형 통신 모델에 대해서 이해한다.
 * 연결형 통신 모델에서 사용하는 함수에 대해서 이해한다.
 * 연결형 통신 모델을 사용하는 프로그램 작성법에 대해서 이해한다.
 */

#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#define SIZE sizeof(struct sockaddr_in)

int main(void) {
    int sockfd; // 클라이언트는 1개의 소켓만 필요
    char send_c, recv_c;
    struct sockaddr_in server = {AF_INET/* 인터넷 기반 */, 5000};    // 통신 유형에 관한 서버의 정보

    server.sin_addr.s_addr = inet_addr("127.0.0.1");

    puts("socket()");
    sockfd = socket(AF_INET, SOCK_STREAM, 0);   // 소켓 생성

    puts("connect()");
    if (connect(sockfd, (struct sockaddr *) &server, SIZE) == -1) { // 서버로 연결 요청
        perror("fail to connect()\n");
        exit(EXIT_FAILURE);
    }

    send_c = 'A';
    printf("send %c to server\n", send_c);
    send(sockfd, &send_c, 1, 0);    // 서버로 메시지를 전송

    recv(sockfd, &recv_c, 1, 0);    // 서버로부터 메시지를 수신
    printf("recv %c from server\n", recv_c);

    puts("close()");
    close(sockfd);  // 소켓 닫기

    return EXIT_SUCCESS;
}