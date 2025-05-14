#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define MAX_SIZE 10

typedef double Element;
#include "radioactive_decay.h"

int main(void)
{
    srand(time(NULL));
    CircularQueue N, T, K; // N 무게 T K 0.1
    
    init_queue(&N);
    init_queue(&T);
    init_queue(&K);

    for (int i = 1; i < 11; i++) {
        enqueue(&N,(rand()%10+1)*100);
        enqueue(&T,(rand()%9+1));
        enqueue(&K,(rand()%9+1)/10.0);
    }
    
    

    print_queue(&N, "물질의 무게는");
    print_queue(&T, "붕괴의 시간은");
    print_queue(&K, "붕괴의 상수는");
    
    print_cal_decay(&N, &T, &K);
    

    return 0;
}
