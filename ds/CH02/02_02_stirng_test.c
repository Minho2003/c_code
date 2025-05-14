#include "Ch01_CMH.h"

int main(){
    char* s1 = "Hello World";

    //s4 = s1;                  // 오류: 문자열은 대입 연산자로 복사 불가

    printf("s1: %c\n", *(s1+1));

    printf("문자열 s1의 길이: %zd\n", strlen(s1));
    
    
    for (int *ptr=s1; ptr<s1+strlen(s1);ptr++){
        printf("%c",*ptr);
    }
    printf("\n");
    return 0;
}


