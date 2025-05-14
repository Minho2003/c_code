    #include "Ch01_CMH.h"

int main(){
    double dA[10];
    double* p1=dA; //추가
    double* p2[10]; //추가
    
    printf("포인터 변수의 크기는 = %zd\n", sizeof(p2));
    printf("포인터 변수의 크기는 = %zd\n", sizeof(&p2));
    
    printf("포인터 변수의 크기는 = %zd\n", sizeof(p1));
    
    printf("포인터 변수의 크기는 = %zd\n", sizeof(*(p1+0)));
    printf("포인터 변수의 크기는 = %zd\n", sizeof(p1[0]));

    p2[0]=dA;
    *(p2[0]+0)=3.14;
    printf("%.2f",*(p2[0]+0));
    return 0;
}
    
