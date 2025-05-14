#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <sys/time.h>

int uclid_gcd(int* num);  // 최대공약수를 구하는 유클리드 호제법 a=b*q+r일때 r이 0일떄 q가 최대공약수
int uclid_lcm( int gcd, int* num);
int prime_fact(int num);
int predicr_degree(int gcd, int lcm);


int main(void) {
    int num[2]={23,28};
    int gcd,lcm;
    
    gcd=uclid_gcd(num);
    
    lcm=uclid_lcm(gcd, num);
    
    printf("%d\n%d\n",gcd,lcm);
    (void)(prime_fact(num[0])),prime_fact(num[1]);
    return 0;
}


int uclid_gcd(int* num){ // 최대공약수를 구하는 유클리드 호제법 a=b*q+r일때 r이 0일떄 q가 최대공약수
    int r = 1, a=num[0], b=num[1];
    while(r != 0){ // r이 0이 될떄까지, gcd(a,b)=gcd(b,r) 이다. r은 a를 b로 나눈 나머지이고, 그 값을 반복
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}

int uclid_lcm( int gcd , int* num){ //최소공배수
    return (num[0]*num[1]/gcd);
}


int prime_fact(int num){
    int cnt=0;
    int prime_ary[10];// 450까지일때의 약수의 최대 개수
    
    
    for (int i = 2; num>1 ; ){
        if ( num % i == 0 ){
            prime_ary[cnt]=i;
            cnt++;
            num/=i;
        }
        else{
            i++;
        }
    
    }
    printf("약수는 : ");
    for (int i = 0; i < cnt; i++){
        printf("%d ", prime_ary[i]);
    }
    printf("\n");
    return cnt; //약수의 개수
}
