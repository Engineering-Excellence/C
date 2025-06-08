/**
 * sendto
 *
 * @brief 비연결형 통신 모델에서 소켓을 통해 메시지를 송신한다.
 *
 * @param fd {int} 소켓 기술자
 * @param buf {const void *} 전송할 메시지를 저장하고 있는 버퍼
 * @param n {size_t} 전송할 메시지의 길이
 * @param flags {int} sendto의 동작 방식을 결정(send와 동일)
 * @param addr {const struct sockaddr *} 메시지 수신자의 정보
 * @param addr_len {socklen_t} addr의 바이트 크기
 * @return {ssize_t} 호출 성공시 전송한 메시지의 문자 개수를, 실패시 -1을 반환
 */

#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define SIZE sizeof(struct sockaddr_in)

int main(void) {
    int sockfd;
    char msg[BUFSIZ], recv[BUFSIZ];

    struct sockaddr_in server = {AF_INET, 2007, inet_addr("127.0.0.1")};
    socklen_t server_len = SIZE;

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);    // 비연결형 모델(UDP) 소켓을 생성

    strcpy(msg, "Hello, world!");
    sendto(sockfd, &msg, BUFSIZ, 0, (struct sockaddr *) &server, server_len);   // 서버로 메시지를 전송

    recvfrom(sockfd, &recv, BUFSIZ, 0, (struct sockaddr *) &server, &server_len);
    printf("reply from server: %s\n", recv);

    close(sockfd);  // 소켓 닫기

    return EXIT_SUCCESS;
}