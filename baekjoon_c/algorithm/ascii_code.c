#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    char** arr=(char **)malloc(1 * sizeof(char *));
    arr[0]=(char *)malloc(101 * sizeof(char));
    int cnt_arr[26];
    int i, cnt;
    scanf("%s", arr[0]);
    
    for (i = 0; i < 26; i++) {
        cnt_arr[i] = -1;
    }
    
    for (i = 0; i < strlen(arr[0]); i++){
        cnt=arr[0][i]-97;
        if(cnt_arr[cnt]==-1){
            cnt_arr[cnt]=i;
        }
    }
    for ( i=0;i<26;i++){
        printf("%d ",cnt_arr[i]);
    }

    
    
    
    
    
    
    
    
    
    
    
    
    return 0;
}
