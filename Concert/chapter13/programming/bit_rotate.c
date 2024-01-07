#include <string.h>
#include "../include/bit_rotate.h"

void rotate_bits(char* value, unsigned int count, int direction) {
    int length = strlen(value);
    char temp[65];

    // 왼쪽 회전
    if (direction < 0) {
        for (int i = 0; i < length; i++) {
            temp[i] = value[(i + count) % length];
        }
    }
        // 오른쪽 회전
    else {
        for (int i = 0; i < length; i++) {
            temp[(i + count) % length] = value[i];
        }
    }

    temp[length] = '\0';
    strcpy(value, temp);
}
