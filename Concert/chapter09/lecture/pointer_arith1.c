/* 포인터의 증감 연산 */
#include <stdio.h>

int main(void) {
    char *pc;
    int *pi;
    double *pd;

    pc = (char *) 10000;
    pi = (int *) 10000;
    pd = (double *) 10000;
    printf("증가 전 pc = %p, pi = %p, pd = %p\n", pc, pi, pd);

    // 포인터를 하나씩 증가
    pc++;
    pi++;
    pd++;
    printf("증가 후 pc = %p, pi = %p, pd = %p\n", pc, pi, pd);

    printf("pc+2 = %p, pi+2 = %p, pd+2 = %p\n", pc + 2, pi + 2, pd + 2);

    return 0;
}
