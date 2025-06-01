/**
 * Chapter10 시그널과 시그널 처리
 *
 * 학습목표
 * 시그널에 대해서 이해한다.
 * 시그널을 처리하는 방법에 대해서 이해한다.
 * 시그널을 사용하는 프로그램 작성법에 대해서 이해한다.
*/

#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void handler(int signum);

int flag = 5;

int main(void) {
    struct sigaction act;   // 특정 시그널에 대해서 수행해야 할 프로세스의 행동 정보 저장
    sigset_t set;   // 시그널 집합

    sigemptyset(&(act.sa_mask));    // 시그널 집합 초기화
    sigaddset(&(act.sa_mask), SIGALRM); // 시그널 추가
    sigaddset(&(act.sa_mask), SIGINT);
    sigaddset(&(act.sa_mask), SIGUSR1);

    act.sa_handler = handler;   // SIGALRM, SIGINT, SIGUSR1 수신시 handler() 실행
    sigaction(SIGALRM, &act, NULL);
    sigaction(SIGINT, &act, NULL);
    sigaction(SIGUSR1, &act, NULL);

    puts("call raise(SIGUSR1) before blocking");
    raise(SIGUSR1); // 자신에게 SIGUSR1 시그널 전달 - handler() 실행

    sigemptyset(&set);
    sigaddset(&set, SIGUSR1);
    sigprocmask(SIG_SETMASK, &set, NULL);   // SIGUSR1 시그널 봉쇄. 이후 봉쇄를 해제하지 않으므로 SIGUSR1에 대해 무반응.

    while (flag) {
        printf("input SIGINT [%d]\n", flag);
        sleep(1);
        raise(SIGINT);
    }

    puts("call kill(getpid(), SIGUSR1) after blocking");
    kill(getpid(), SIGUSR1);    // getpid()로 구한 값을 식별자로 가지는 프로세스에게 SIGUSR1 전달. raise()와 마찬가지로 자기자신에게 시그널 보냄.

    puts("sleep by pause... zzZZ");
    alarm(1);   // 1초 후 SIGALRM 발생
    printf("pause return %d\n", pause());   // 대기 상태 진입. 시그널이 들어와야 깨어남.

    puts("2 seconds sleeping... zzZZ");
    alarm(2);   // 2초 후 SIGALRM 발생
    pause();

    return EXIT_SUCCESS;
}

/**
 * @brief 시그널이 수신되었을 때 수행할 사용자 정의 함수
 *
 * handler
 *
 * @param signum 수신한 시그널
 */
void handler(int signum) {
    flag--;

    switch (signum) {
        case SIGINT:
            printf("SIGINT(%d)\n", signum);
            break;
        case SIGALRM:
            printf("SIGALRM(%d)\n", signum);
            break;
        case SIGUSR1:
            printf("SIGUSR1(%d)\n", signum);
            break;
        default:
            printf("signal(%d)\n", signum);
            break;
    }
}
