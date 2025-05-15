#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "02.c"

typedef double Element;
#include "LinkedList.h"

void print_list(char* msg)
{
    printf("단순연결리스트 %s[%2d]: ", msg, size());
    for (Node* p = head; p != NULL; p = p->link)
        printf("%lf ", p->data);
    printf("\n");
}

int main(void){
    init_list();
    Point degree[MAX_SIZE]={ DEGREE_A, DEGREE_B, DEGREE_C};
    
    insert(0, DEGREE_A);
    insert(1, DEGREE_B);
    insert(2, DEGREE_C);
    insert(3, ((distance(degree[0], degree[1])+distance(degree[1], degree[2])+distance(degree[2], degree[0]))/2.0));
    insert(4, (distance(degree[0], degree[1])*distance(degree[1], degree[2])/2.0));
    insert(5, calculateTriangle(DEGREE_A, DEGREE_B, DEGREE_C));
    print_list(" ");
}
