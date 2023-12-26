/* fgets()와 puts()를 이용한 문자열 입출력 */
#include <stdio.h>
#include <string.h>

int main(void) {
    char name[100];
    char address[100];

    printf("이름을 입력하세요.: ");
    fgets(name, sizeof(name), stdin); // 한 줄을 입력받는다.
    name[strcspn(name, "\n")] = '\0'; // fgets()가 개행 문자를 포함시키므로 이를 제거한다.

    printf("현재 거주중인 도시를 입력하세요.: ");
    if (fgets(address, sizeof(address), stdin) == NULL) { // 한 줄을 입력받는다.
        printf("입력 오류!\n");
        return 1;
    }
    address[strcspn(address, "\n")] = '\0';

    puts(name); // 줄 단위로 출력한다.
    puts(address);

    return 0;
}
