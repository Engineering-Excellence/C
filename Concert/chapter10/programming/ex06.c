#include <stdio.h>
#include <string.h>

int main(void) {
    char result[512];
    char buffer[256];

    printf("문장을 입력하세요.: ");
    fgets(buffer, sizeof(buffer), stdin);

    strcpy(result, "전체 프로그램:\n#include <stdio.h>\nint main(void) {\n    ");
    strcat(result, buffer);
    strcat(result, "    return 0;\n}");

    puts(result);

    return 0;
}
