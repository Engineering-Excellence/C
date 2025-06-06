/**
 * connect
 *
 * @brief listen 상태로 대기중인 상태 프로세스에게 연결을 요청한다.
 *
 * @param sockfd {int} socket으로 미리 생성된 소켓 기술자
 * @param serv_addr {const struct sockaddr *} 통신을 연결할 서버의 주소 등에 관한 정보
 * @param addrlen {socklen_t *} serv_addr의 크기
 * @return {int} 호출이 성공하면 0을, 실패하면 -1을 반환
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

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {  // 소켓 생성
        perror("fail to call socket()\n");
        exit(EXIT_FAILURE);
    }

    printf("socket descriptor is %d\n", sockfd);

    if (connect(sockfd, (struct sockaddr *) &server, SIZE) == -1) { // 서버로 연결 요청
        perror("fail to call connect()\n");
        exit(EXIT_FAILURE);
    }

    /* 메시지를 주고받는 부분 */
    send_c = 'A';
    printf("send %c to server\n", send_c);
    send(sockfd, &send_c, 1, 0);    // 서버로 메시지를 전송

    recv(sockfd, &recv_c, 1, 0);    // 서버로부터 메시지를 수신
    printf("recv %c from server\n", recv_c);

    close(sockfd);  // 소켓 닫기

    return EXIT_SUCCESS;
}