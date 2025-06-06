/**
 * send
 *
 * @brief 지정한 소켓을 사용하여 메시지를 전송한다.
 *
 * @param sockfd {int} 메시지를 전송할 소켓 기술자
 * @param msg {const void *} 전송할 메시지
 * @param msg_len {size_t} msg의 길이
 * @param flags {int} 메시지를 전송하는 방법
 * @return {int} 호출이 성공하면 전송한 문자 수를, 실패하면 -1을 반환
 */

/**
 * recv
 *
 * @brief 지정한 소켓을 사용하여 메시지를 수신한다.
 *
 * @param sockfd {int} 메시지를 수신할 소켓 기술자
 * @param msg {void *} 수신할 메시지
 * @param msg_len {size_t} msg의 길이
 * @param flags {int} 메시지를 수신하는 방법
 * @return {int} 호출이 성공하면 수신한 바이트 수를, 실패하면 -1을 반환
 */

#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#define SIZE sizeof(struct sockaddr_in)

int sockfd_connect;

int main(void) {
    int sockfd_listen;
    char c;
    struct sockaddr_in server = {AF_INET, 5000, INADDR_ANY};

    if ((sockfd_listen = socket(AF_INET, SOCK_STREAM, 0)) == -1) {  // 소켓 생성
        perror("fail to call socket()\n");
        exit(EXIT_FAILURE);
    }

    printf("socket descriptor is %d\n", sockfd_listen);

    if (bind(sockfd_listen, (struct sockaddr *) &server, SIZE) == -1) { // 서버를 소켓과 연결
        perror("fail to call bind()");
        exit(EXIT_FAILURE);
    }

    if (listen(sockfd_listen, 5/* 동시에 받아들일 수 있는 연결 요청 수 */) == -1) {    // 소켓을 클라이언트의 연결 요청을 대기 상태로 변경
        perror("fail to call listen()");
        exit(EXIT_FAILURE);
    }

    while (1) {
        // 연결 요청 대기 큐의 첫 번째 연결 요청을 가져와서 새로운 소켓을 생성 및 소켓 기술자를 할당 후 반환
        if ((sockfd_connect = accept(sockfd_listen, NULL, NULL)) == -1) {
            perror("fail to call accept()");
            continue;
        }
        puts("accepted");
        while (recv(sockfd_connect, &c, 1, 0) > 0)
            send(sockfd_connect, &c, 1, 0);

        close(sockfd_connect);  // 비정상적으로 끊어진 소켓에 대해 메시지 송수신시 SIGPIPE 시그널이 전달된 경우에도 닫기 필요
    }
}