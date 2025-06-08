/**
 * recvfrom
 *
 * @brief 비연결형 통신 모델에서 소켓을 통해 메시지를 수신한다.
 *
 * @param fd {int} 소켓 기술자
 * @param buf {void *} 수신할 메시지를 저장할 버퍼
 * @param n {size_t} 버퍼의 크기
 * @param flags {int} recvfrom의 동작 방식을 결정(recv와 동일)
 * @param addr {struct sockaddr *} 메시지 송신자의 정보
 * @param addr_len {socklen_t} addr의 바이트 크기
 * @return {ssize_t} 호출 성공시 수신한 메시지의 바이트 크기를, 실패시 -1을 반환
 */

#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#define SIZE sizeof(struct sockaddr_in)

int main(void) {
    int sockfd;
    char msg[BUFSIZ];

    struct sockaddr_in server = {/*SIZE, */AF_INET, 2007, INADDR_ANY};
    struct sockaddr_in client;
    socklen_t client_len = SIZE;

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);    // 비연결형 모델(UDP) 소켓을 생성

    if (bind(sockfd, (struct sockaddr *) &server, SIZE) == -1) {    // 소켓을 서버와 연결
        perror("fail to call bind()");
        exit(EXIT_FAILURE);
    }

    recvfrom(sockfd, &msg, BUFSIZ, 0, (struct sockaddr *) &client, &client_len);     // 송신자 클라이언트 정보 저장 후 메시지 읽기
    printf("recvfrom client: %s\n", msg);

    sendto(sockfd, &msg, BUFSIZ, 0, (struct sockaddr *) &client, client_len);

    close(sockfd);

    return EXIT_SUCCESS;
}