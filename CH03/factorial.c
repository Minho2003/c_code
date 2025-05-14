#include <stdio.h>

int factorial_iter(int n)
{
    int i, result = 1;
    for (i = 1; i <= n; i++)
        result = result * i;
    return result;
}

int factorial(int n)
{
    if (n == 1)
        return 1;
    else
        return n * factorial(n - 1);
}

int factorial_p(int n)
{
    printf("함수 호출: factorial(%d)\n", n);    // 순환호출 순서 확인을 위한 출력문
    int ret;
    if (n == 1) ret = 1;
    else ret = n * factorial_p(n - 1);

    // 함수의 반환 위치를 한 곳으로 모아 출력
    printf("함수 반환: factorial(%d) --> %d\n", n, ret);
    return ret;
}

void main()
{
    printf("반복 factorial(3) = %d\n", factorial_iter(3));
    printf("순환 factorial(3) = %d\n", factorial(3));

    factorial_p(3);
}
