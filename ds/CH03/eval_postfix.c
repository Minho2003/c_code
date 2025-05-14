#include <stdio.h>
#include <stdlib.h>
#include "CMH.h"
#define MAX_SIZE 100
typedef double Element; // 스택에는 피연산자(double)가 저장됨
#include "ArrayStack.h"

double eval_postfix(char* expr);

int main(void)
{
    printf("%d\n", clock());
    int start=clock();
    char expr[2][80] = { "8 2 / 3- 3 2 * +", "1 2 / 4 * 1 4 / *" };

    printf("수식: %s = %lf\n", expr[0], eval_postfix(expr[0]));
    printf("수식: %s = %lf\n", expr[1], eval_postfix(expr[1]));
    int end =clock();
    
    printf("시간 %d",end-start);
    
    return 0;
}

double eval_postfix(char* expr)
{
    int i = 0;

    init_stack();
    while (expr[i] != '\0') {
        char c = expr[i++];
        if (c >= '0' && c <= '9') {
            double num = (double)c - '0';
            push(num);  //피연산자 스택에 입력
        }
        else if (c == '+' || c == '-' || c == '*' || c == '/') {
            double val2 = pop(); // 두 번째 피연산자
            double val1 = pop(); // 첫 번째 피연산자
            switch (c) {
            case '+': push(val1 + val2); break;
            case '-': push(val1 - val2); break;
            case '*': push(val1 * val2); break;
            case '/': push(val1 / val2); break;
            }
        }
    }
    return pop();
}
