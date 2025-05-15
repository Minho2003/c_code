#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "01.c"

double Triangle_D(double a, double b, double c){
    return ((a+b+c)/2.0);
}

double Triangle_E(double a, double b, double c){
    return pow(pow(a,2)+pow(b,2)+pow(c,2),0.5)/2.0;
}

double calculateTriangle(double a, double b, double c){
    double D = Triangle_D(a, b, c);
    double E = Triangle_E(a, b, c);
    return E/D;
    
}

double safeArea(double cal){
    return (3.14)*pow(cal,2);
}

int main(void){
    Point degree[MAX_SIZE]={ DEGREE_A, DEGREE_B, DEGREE_C};

    if (isTriangle(degree[0],degree[1],degree[2]) == 0){
        printf("삼각형이 아닙니다.");
        return 0;
    }
    
    printf(" 드론의 안전구역은 : %lf\n", safeArea(calculateTriangle(distance(degree[0], degree[1]), distance(degree[1], degree[2]), distance(degree[2], degree[0]))));
    
    return 0;
}
