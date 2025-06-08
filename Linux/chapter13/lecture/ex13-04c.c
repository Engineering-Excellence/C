/**
 * 예제 프로그램 완성하기: 비연결형 모델
 *
 * @brief echo 클라이언트 구현
 *
 * 클라이언트가 서버로 메시지를 보내면 서버로부터 동일한 메시지를 되돌려받는다.
 */

#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#define SIZE sizeof(struct sockaddr_in)

int main(void) {
    int sockfd;
    char msg, prev;

    struct sockaddr_in server = {/* SIZE, */AF_INET, 2007, inet_addr("127.0.0.1")}; // 서버 정보
    socklen_t server_len = SIZE;

    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) == -1) {  // 비연결형 모델 소켓을 생성
        perror("fail to call socket()");
        exit(EXIT_FAILURE);
    }

    prev = '\n';
    while (read(0, &msg, 1) != 0) {
        if (sendto(sockfd, &msg, sizeof(msg), 0, (struct sockaddr *) &server, server_len) == -1) {  // 서버로 메시지를 송신
            perror("fail to send message");
            continue;
        }

        if (recvfrom(sockfd, &msg, sizeof(msg), 0, (struct sockaddr *) &server, &server_len) == -1) {   // 서버로부터 메시지를 수신
            perror("fail to receive message");
            continue;
        }

        printf("%s%c", prev == '\n' ? "[recv] " : "", msg);
        prev = msg;
    }

    close(sockfd);  // 소켓 닫기

    return EXIT_SUCCESS;
}