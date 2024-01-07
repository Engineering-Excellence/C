/* 암호화 및 복호화 */
#include <stdio.h>
#include <string.h>

int main(void) {
    char plaintext[1024], ciphertext[1024];
    unsigned long len;
    unsigned char key;

    printf("암호화 키 값을 입력하세요(0-255).: ");
    scanf("%hhu", &key);
    while (getchar() != '\n');  // 버퍼 공백 제거

    printf("문자열을 입력하세요.: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    len = strcspn(plaintext, "\n");
    plaintext[len] = '\0';

    printf("암호화된 문자열: ");
    for (int i = 0; i < len; ++i) {
        ciphertext[i] = plaintext[i] ^ key;
        printf("%c", ciphertext[i]);
    }
    puts("");

    printf("복호화 키 값을 입력하세요(0-255).: ");
    scanf("%hhu", &key);
    while (getchar() != '\n');

    printf("복호화된 문자열: ");
    for (int j = 0; j < len; ++j) {
        plaintext[j] = ciphertext[j] ^ key;
        printf("%c", plaintext[j]);
    }
    puts("");

    return 0;
}
