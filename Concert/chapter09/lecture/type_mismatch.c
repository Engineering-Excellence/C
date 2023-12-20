/* 포인터 타입과 변수의 타입은 일치하여야 한다 */

int main(void) {
    int i;
    double *pd;

    pd = &i;    // 오류! double형 포인터에 int형 변수의 주소를 대입
    *pd = 36.5;

    return 0;
}
