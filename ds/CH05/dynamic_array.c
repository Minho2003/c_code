#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void rand_array(int* A, int n);
void print_array(int* A, int n);
double average_array(int* A, int n);

int main(void)
{
    srand((unsigned)time(NULL));
    
    int size;
    printf("배열의 크기: ");
    scanf("%d", &size);
    int* data = (int*)malloc(sizeof(int) * size);
    double sum=0;
    for(int i=0; i<size;i++){
        
        rand_array(data, size);
//        print_array(data, size);
        double avg = average_array(data, size);
        sum+=avg;
        printf("배열의 평균: %.5f\n", avg);
    }
    free(data);
    printf("%lf",sum/size);
    
    return 0;
}

void rand_array(int* A, int n)
{
    for (int i = 0; i < n; i++)
        A[i] = rand() % 100 +1;
}
void print_array(int* A, int n)
{
    printf("배열의 요소: ");
    for (int i = 0; i < n; i++)
        printf("%3d", A[i]);
    printf("\n");
}
double average_array(int* A, int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += A[i];
    return ((double)sum / n);
}
