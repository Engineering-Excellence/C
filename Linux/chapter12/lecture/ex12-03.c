/**
 * socket
 *
 * @brief 프로세스 간 통신을 위한 끝단(endpoint)을 생성한다.
 *
 * @param domain {int} 통신 도메인(프로토콜)을 지정한다.
 * @param type {int} 통신 방법을 선택한다.
 * @param protocol {int} 선택된 프로토콜 군에서 특정 프로토콜을 선택한다. 대부분의 프로토콜 군은 하나의 프로토콜을 갖고 있다.
 * @return {int} 호출이 성공하면 소켓 기술자를 반환하고, 실패하면 -1을 반환한다.
 */

#include <sys/socket.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(void) {
    int sockfd;

    if ((sockfd = socket(AF_INET/* IPv4 */, SOCK_STREAM/* 연결형 */, 0/* 기본값(TCP) */)) == -1) {    // IPv4 기반의 연결형 모델(TCP)로 소켓 생성
        perror("fail to call socket()\n");
        exit(EXIT_FAILURE);
    }

    printf("socket descriptor is %d\n", sockfd);

    /* 소켓을 통한 통신 기능을 수행한다. */

    close(sockfd);  // 소켓 닫기

    return EXIT_SUCCESS;
}