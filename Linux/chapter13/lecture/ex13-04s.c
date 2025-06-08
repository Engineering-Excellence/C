/**
 * 예제 프로그램 완성하기: 비연결형 모델
 *
 * @brief echo 서버 구현
 *
 * 서버는 대기 상태로 있다가 클라이언트가 보낸 메시지가 도착하면 이를 그대로 되돌려준다.
 */

#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <stdio.h>

#define SIZE sizeof(struct sockaddr_in)

int main(void) {
    int sockfd;
    char msg, prev;

    struct sockaddr_in server = {/* SIZE, */AF_INET, 2007, INADDR_ANY}; // 서버 설정
    struct sockaddr_in client;
    socklen_t client_len = SIZE;

    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) == -1) {  // 비연결형 모델(UDP) 소켓을 생성
        perror("fail to call socket()");
        exit(EXIT_FAILURE);
    }

    if (bind(sockfd, (struct sockaddr *) &server, SIZE) == -1) {    // 소켓에 서버 네트워크 정보를 연결
        perror("fail to call bind()");
        exit(EXIT_FAILURE);
    }

    prev = '\n';
    while (1) {
        if (recvfrom(sockfd, &msg, 1, 0, (struct sockaddr *) &client, &client_len) == -1) {
            perror("fail to receive message");
            continue;
        }

        printf("%s%c", prev == '\n' ? "[recv] " : "", msg);
        prev = msg;

        if (sendto(sockfd, &msg, 1, 0, (struct sockaddr *) &client, client_len) == -1) {
            perror("fail to send message");
            continue;
        }
    }
}