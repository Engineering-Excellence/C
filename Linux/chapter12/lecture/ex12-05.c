/**
 * listen
 *
 * @brief 소켓을 통해 들어오는 연결 요청을 기다린다.
 *
 * @param sockfd {int} socket으로 미리 생성된 소켓 기술자
 * @param backlog {int} 동시에 들어오는 여러 연결 요청을 넣어두는 큐의 사이즈
 * @return {int} 호출이 성공하면 0을, 실패하면 -1을 반환
 */

#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#define SIZE sizeof(struct sockaddr_in)

int main(void) {
    int sockfd_listen;
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

    close(sockfd_listen);  // 소켓 닫기

    return EXIT_SUCCESS;
}