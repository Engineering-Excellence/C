/* 문자열 토큰 분리 */
#include <string.h>
#include <stdio.h>

int main(void) {
    char *token;
    char s[] = "Man is immortal, because he has a soul";
    //char seps[] = " ,\t\n.;:!?-";     // 분리자. 문자 배열로 선언시 스택 메모리에 저장.
    const char *seps = " ,\t\n.;:!?-";     // 문자 포인터로 선언하면 변경 불가, 동적으로 크기 조절. 힙 메모리에 저장.
    char *saveptr;      // 재진입 가능(reentrant) 함수 strtok_r()가 내부 상태를 저장할 포인터. 스레드 안정성.
//    token = strtok(s, seps);    // 문자열에서 첫 번째 토큰을 얻는다.
    token = strtok_r(s, seps, &saveptr);

    while (token != NULL) {     // 문자열 s에 토큰이 있는 동안 반복한다.
        printf("토큰: %s\n", token);
//        token = strtok(NULL, seps);     // 첫 번째 인자를 NULL로 지정하여 다음 토큰을 얻는다.
        token = strtok_r(NULL, seps, &saveptr);     // 다음 토큰을 얻는다.
    }

    return 0;
}
