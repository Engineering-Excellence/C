/**
 * 예제 프로그램 완성하기: 연결형 모델
 *
 * @brief echo 서버 구현
 *
 * 서버는 대기 상태로 클라이언트의 연결 요청을 기다리다가, 두 프로세스 간의 연결이 설정되면 클라이언트가 전송한 메시지를 서버가 그대로 되돌려 주는 기능을 수행한다.
 */

#include <sys/socket.h>
#include <netinet/in.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#define SIZE sizeof(struct sockaddr_in)

void closesock(int sig);

int sockfd_connect;

int main(void) {
    int sockfd_listen;
    char c;
    struct sockaddr_in server = {AF_INET, 5000, INADDR_ANY};
    struct sigaction act;

    act.sa_handler = closesock;
    sigfillset(&(act.sa_mask));
    sigaction(SIGPIPE, &act, NULL);

    if ((sockfd_listen = socket(AF_INET, SOCK_STREAM, 0)) == -1) {  // 소켓 생성
        perror("fail to call socket()\n");
        exit(EXIT_FAILURE);
    }

    if (bind(sockfd_listen, (struct sockaddr *) &server, SIZE) == -1) { // 서버를 소켓과 연결
        perror("fail to call bind()\n");
        exit(EXIT_FAILURE);
    }

    if (listen(sockfd_listen, 5) == -1) {   // 서버를 클라이언트 대기 상태로 변경
        perror("fail to call listen()\n");
        exit(EXIT_FAILURE);
    }

    while (1) {
        if ((sockfd_connect = accept(sockfd_listen, NULL, NULL)) == -1) {   // 클라이언트가 연결 요청시 수락 및 3-ways handshake 수행 후 새로운 소켓 생성
            perror("fail to call accept()\n");
            continue;
        }
        puts("accepted");
        while (recv(sockfd_connect, &c, 1, 0) > 0)
            send(sockfd_connect, &c, 1, 0); // 서버가 수신한 메시지를 클라이언트에게 그대로 되돌려 줌

        puts("close(sockfd_connect)");
        close(sockfd_connect);  // 소켓 닫기
    }
}

/**
 * @brief 비정상 소켓 종료 함수
 *
 * 비정상적으로 끊어진 소켓에 대해 메시지 송수신시 SIGPIPE 시그널이 전달된 경우 소켓을 닫는다.
 *
 * @param sig {int} 시그널
 */
void closesock(int sig) {
    close(sockfd_connect);
    printf("SIGPIPE(%d): connection is lost", sig);
    exit(EXIT_SUCCESS);
}
