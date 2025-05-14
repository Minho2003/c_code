#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

int fact(int num){
    while(num>1){
        return num*fact(num-1);
    }
    return 1;
}


int main(void) {
    int a=7;
    
    printf("%d",fact(a));
    
    
    
    
    return 0;
}
