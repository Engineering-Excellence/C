/**
 * accept
 *
 * @brief 연결형 소켓으로 통신을 할 때 상대의 연결 요청을 수락한다.
 *
 * @param sockfd {int} socket으로 미리 생성된 소켓 기술자
 * @param addr {struct sockaddr *} 연결 요청한 클라이언트의 주소 등에 관한 정보
 * @param addrlen {socklen_t *} addr의 바이트 길이
 * @return {int} 호출이 성공하면 0을, 실패하면 -1을 반환
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
        } else {
            /* sockfd_connect를 사용하여 통신을 수행 */

            close(sockfd_connect);
        }
    }
}