/**
 * 예제 프로그램 완성하기: 연결형 모델
 *
 * @brief echo 클라이언트 구현
 *
 * 클라이언트는 서버에게 연결 요청 후, 두 프로세스 간의 연결이 설정되면 클라이언트가 전송한 메시지를 서버가 그대로 되돌려 주는 기능을 수행한다.
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
    char send_c, recv_c;
    struct sockaddr_in server = {AF_INET, 5000};

    server.sin_addr.s_addr = inet_addr("127.0.0.1");

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) { // 소켓 생성
        perror("fail to call socket()\n");
        exit(EXIT_FAILURE);
    }

    if (connect(sockfd, (struct sockaddr *) &server, SIZE) == -1) { // 서버로 연결 요청 및 3-ways handshake 수행
        perror("fail to call connect()\n");
        exit(EXIT_FAILURE);
    }

    recv_c = '\n';
    while (1) {
        if (recv_c == '\n')
            printf("input message:");
        send_c = getchar();

        send(sockfd, &send_c, 1, 0);    // 서버로 메시지를 전송

        if (recv(sockfd, &recv_c, 1, 0) > 0)    // 서버로부터 메시지를 수신
            putchar(recv_c);
        else {
            puts("server has no reply");
            close(sockfd);
            exit(EXIT_FAILURE);
        }
    }
}
