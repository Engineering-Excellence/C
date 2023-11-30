#include <stdio.h>

int main(void) {

    int id;
    int pw;

    printf("ID와 PW를 4개의 숫자로 입력하세요.\n");
    printf("ID: ____\b\b\b\b");
    scanf("%d", &id);
    printf("PW: ____\b\b\b\b");
    scanf("%d", &pw);
    printf("\a입력된 ID는 \"%d\"이고 PW는 \"%d\"입니다.\n", id, pw);

    return 0;
}