/* scanf()와 printf()를 이용한 문자열 입출력 */
#include <stdio.h>

int main(void) {
    char name[100];
    char address[100];

    printf("이름을 입력하세요.: ");
    scanf("%s", name);  // 배열의 이름이 배열의 주소이므로 &name과 같이 하면 안 된다!
    printf("현재 거주중인 도시를 입력하세요.: ");
    scanf("%s", address);   // %s는 하나의 단어만을 입력받기 때문에 공백 이후의 문자가 올바르게 저장되지 않는다!

    printf("당신은 %s에 사는 %s입니다.\n", address, name);

    return 0;
}
