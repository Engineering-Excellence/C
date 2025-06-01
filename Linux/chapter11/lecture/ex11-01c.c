#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>

int main(void)
{
    int filedes;    // 네임드 파이프 파일 기술자

    puts("[exec] standard output"); // 표준 출력(부모 프로세스와 연결된 파이프의 사본)이 파이프를 통한 출력
    sleep(1);

    filedes = open("./fifo", O_WRONLY); // 네임드 파이프 열기
    write(filedes, "from exec via FIFO", strlen("from exec via FIFO")); // 첫 번째 자식 프로세스가 읽을 메시지
    close(filedes); // 네임드 파이프 닫기

    return 0;
}
