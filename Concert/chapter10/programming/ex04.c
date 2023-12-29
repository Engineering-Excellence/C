/* 입력받은 문자열의 각 문자가 나타나는 빈도를 출력 */
#include <stdio.h>


int main(void) {
    char buffer[256];
    unsigned int freq[128] = {0};

    printf("문자열을 입력하세요.: ");
    fgets(buffer, sizeof(buffer), stdin);

    for (int i = 0; buffer[i] != '\n' ; ++i) {
        freq[(int) buffer[i]]++;
    }

    for (int i = 'a'; i <= 'z'; ++i) {
        printf("%c: %d\n", i, freq[i]);
    }
    for (int i = 'A'; i <= 'Z'; ++i) {
        printf("%c: %d\n", i, freq[i]);
    }

    return 0;
}
