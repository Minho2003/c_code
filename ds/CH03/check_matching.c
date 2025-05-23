#include "CMH.h"

typedef char Element; // 스택 요소 Element의 자료형
#define MAX_SIZE 100
#include "ArrayStack.h" // 스택의 ADT(데이터와 연산) 포함

int check_matching(char* expr);


int main(void)
{
    char expr[4][80] = {
        "{A[(i+1)]=0;}",
        "if((i==0) && (j==0)",
        "while(n<8)){n++;}",
        "arr[(i+1]) = 0;" };

    for (int i = 0; i < 4; i++) {
        int errCode = check_matching(expr[i]);
        
        if (errCode == 0) printf("%-20s -> 정상\n", expr[i]);
        else printf("%-20s -> 오류(조건%d 위반)\n", expr[i], errCode);
    }
    
    return 0;
}

int check_matching(char* expr)
{
    int i = 0, prev;
    
    init_stack();
    while (expr[i] != '\0') {
        char ch = expr[i++];
        
        if (ch == '[' || ch == '(' || ch == '{'){
            push(ch);
        }
        else if (ch == ']' || ch == ')' || ch == '}') {
            if (is_empty())
                return 2;       // 조건 2 위반
            
            prev = pop();
            
            if ((ch == ']' && prev != '[')
                || (ch == ')' && prev != '(')
                || (ch == '}' && prev != '{'))
                return 3;       // 조건 3 위반
        }
    }
    
    if (!is_empty()) return 1;  // 조건 1 위반
    else return 0;              // 괄호 정상
}
