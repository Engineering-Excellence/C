/* gets()와 puts()를 이용한 문자열 입출력 */
#include <stdio.h>

int main(void) {
    char name[100];
    char address[100];

    printf("이름을 입력하세요.: ");
    gets(name); // 한 줄을 입력받는다.
    printf("현재 거주중인 도시를 입력하세요.: ");
    gets(address);  // 속도면에서 유리하지만, 입력 문자열 크기를 검사하지 않기 때문에 보안상의 문제점이 있어서 deprecated 됨. fgets()로 대체.

    puts(name); // 줄 단위로 출력한다.
    puts(address);

    return 0;
}
