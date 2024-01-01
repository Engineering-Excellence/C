/* 이메일 구조체 */
#include <stdio.h>
#include <time.h>

typedef struct email EMAIL;

enum priority {
    critical, high, normal, low
};

struct email {
    char *title;        // 제목
    char *recipient;     // 수신자
    char *sender;        // 발신자
    char *content;     // 내용
    struct tm *date;      // 날짜
    enum priority priority; // 우선순위
};

int main(void) {
    struct tm date = {0};
    date.tm_mon = 12;
    date.tm_mday = 31;
    date.tm_year = 2023;

    EMAIL email;
    email.title = "송구영신";
    email.recipient = "리트아니아";
    email.sender = "소나티넨";
    email.content = "Love ya, vice versa.";
    email.date = &date;
    email.priority = 0;

    printf("제목: %s\n", email.title);
    printf("수신자: %s\n", email.recipient);
    printf("발신자: %s\n", email.sender);
    printf("내용: %s\n", email.content);
    printf("날짜: %d년 %d월 %d일\n", email.date->tm_year, email.date->tm_mon, email.date->tm_mday);
    printf("우선순위: %d\n", email.priority);

    return 0;
}
