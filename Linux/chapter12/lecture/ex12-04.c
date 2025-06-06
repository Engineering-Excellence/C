/**
 * bind
 *
 * @brief 호스트의 로컬 주소를 소켓과 연결시킨다.
 *
 * @param sockfd {int} socket으로 미리 생성된 소켓 기술자
 * @param my_addr {struct sockaddr *} 호스트의 로컬 주소
 * @param addrlen {socklen_t} 호스트의 로컬 주소의 바이트 길이
 * @return {int} 호출이 성공하면 0을, 실패하면 -1을 반환
 */

#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#define SIZE sizeof(struct sockaddr_in)

int main(void) {
    int sockfd;
    struct sockaddr_in addr;    // 동일 시스템 내 프로세스 간 통신(sockaddr_in)
//    struct sockaddr_in addr = {AF_INET, 1004, INADDR_ANY};

    addr.sin_family = AF_INET;  // IPv4
    addr.sin_port = 1004;
    addr.sin_addr.s_addr = INADDR_ANY;  // 호스트 주소 자동 할당(커널)

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("fail to call socket()\n");
        exit(EXIT_FAILURE);
    }

    printf("socket descriptor is %d\n", sockfd);

    if (bind(sockfd, (struct sockaddr *) &addr, SIZE) == -1) {  // 호스트 로컬 주소를 소켓과 연결(sockaddr_in을 sockaddr로 형변환 필요)
        perror("fail to call bind()");
        exit(EXIT_FAILURE);
    }

    /* 통신을 위한 나머지 코드들 */

    close(sockfd);  // 소켓 닫기

    return EXIT_SUCCESS;
}