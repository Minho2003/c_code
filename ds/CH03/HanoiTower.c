#include <stdio.h>
# include "CMH.h"
#include <stdio.h>

void hanoi_tower(int n, char from, char tmp, char to)
{
    if (n == 1);
//        printf("원판 1: %c --> %c\n", from, to);
    else {
        hanoi_tower(n - 1, from, to, tmp);
//        printf("원판 %d: %c --> %c\n", n, from, to);
        hanoi_tower(n - 1, tmp, from, to);
    }
}

int main(void) {
    int start, end;
    start=clock();
    hanoi_tower(50, 'A', 'B', 'C');
    end=clock();
    printf("%d",end-start);
    
    return 0;
}
