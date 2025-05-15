#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SIZE 3

#define DEGREE_A (1 ,0)
#define DEGREE_B (5, 0)
#define DEGREE_C (5, 4)

typedef struct Point {
    int x;
    int y;
} Point;

double distance(Point p1, Point p2){  // 세변의 길이
    return pow((double)pow((p2.x-p1.x),2)+(double)pow((p2.y-p1.y),2),0.5);
}

int isTriangle(Point A, Point B, Point C){
    double dis_a=distance(A, B);
    double dis_b=distance(B, C);
    double dis_c=distance(C, A);
    
    if (dis_a+dis_b>=dis_c && dis_a+dis_c>=dis_b && dis_c+dis_b>=dis_a){
        return 1;
    }
    else{
        return 0;
    }
}

int main(void){
    Point degree[MAX_SIZE]={ (1,0), (5,0), (5,4)};
    if (isTriangle(degree[0], degree[1], degree[2])==1){
        printf("삼각형이 유효합니다.");
    }
    else{
        printf("삼각형이 유효하지 않습니다.");
    }

    return 0;
}
