#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(void) {
    int a,b,c; // 자연수 입력받을 변수 선언
    scanf("%d\n%d\n%d",&a,&b,&c); // 자연수 입력
    int num=a*b*c;
    int num_cnt[10]={0}; // 0~9까지 횟수 계산
    
    int num_size=log10(a*b*c)+1;// ????에 들어갈 길이를 정해주는 변수 만들기
    char **arr=(char **)malloc(1 * sizeof(char*));
    arr[0]=(char *)malloc(num_size * sizeof(char));
    sprintf(arr[0], "%d",num);
    int num_arr[num_size];
    for (int i=0;i<num_size;i++){
        num_arr[i]=arr[0][i]-'0';
    }
    
    for (int *ptr=num_arr; ptr<num_arr+num_size;ptr++){
        
        num_cnt[*ptr]++;
    }
    for (int i=0;i<10;i++){
        printf("%d\n",num_cnt[i]);
    }
    return 0;
}
