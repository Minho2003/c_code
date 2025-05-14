#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SIZE 100
typedef double* Element;
#include "ArrayList.h" // 리스트 데이터와 연산
#include "file.h"

double dis(double* a, double* b){
    return sqrt(pow(a[0]-b[0],2)+pow(a[1]-b[1],2));
}

double circle_area(double* a, double* b, double* c){  //삼각형의 넓이
    return 0.5*fabs(a[0]*(b[1]-c[1])+b[0]*(c[1]-a[1])+c[0]*(a[1]-b[1]));
}

double inscribed_circle(double* a, double* b, double* c){  // 삼각형의 내접원의 반지름
    double ab=dis(a, b);
    double bc=dis(b, c);
    double ca=dis(c, a);

    return (circle_area(a, b, c)*2)/(ab+bc+ca);
}

void inscribed_circle_center(double* a, double* b, double* c, double* result){ // 내접원 중심 좌표 x,y
    result[0]=(a[0]*dis(b,c)+b[0]*dis(c,a)+c[0]*dis(a,b))/(dis(a,b)+dis(b,c)+dis(c,a));
    result[1]=(a[1]*dis(b,c)+b[1]*dis(c,a)+c[1]*dis(a,b))/(dis(a,b)+dis(b,c)+dis(c,a));
}

int main(void)
{
    FILE* fp_input=fopen(FILE_PATHS[0], "r");
    if (fp_input == NULL) {
        printf("파일을 열 수 없습니다.\n");
        return 1;
    }
    
    double degree[3][2];
    
    for (int i=0;i<3;i++){
        fscanf(fp_input, "%lf %lf", &degree[i][0], &degree[i][1]);
        insert(i, degree[i]);
    }
    fclose(fp_input);
    double result[2];
    inscribed_circle_center(get_entry(0), get_entry(1),get_entry(2), result); // result[0], result[1] 각각 내접원 중심 좌표 x,y
    
    return 0;
}
