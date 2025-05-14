#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_ELEMENTS 3
int MAX_ARY[MAX_ELEMENTS];

int find_max(int* ary); // fin_max 함수 선언
int compare(const void* a,  const void* b); // qsort() 함수에 필요한 오름차수 로직 함수 선언

int main(void){
    int num, i, j;
    printf("테스트 케이스의 수를 입력하시오 : ");
    scanf("%d",&num); // 최댓값을 구하는 테스트 케이스의 횟수 입력

    for ( i = 0; i < num; i++){ // 테스트 케이스의 횟수 만큼 반복
        printf("최댓값을 구할 수를 입력 하시오 : ");
        for ( j = 0; j < 3; j++){ // MAX_ELEMENTS 만큼 반복하여 배열에 입력
            scanf("%d",&MAX_ARY[j]);
        }
        printf("최댓값 = %d\n", find_max(MAX_ARY)); // 최댓값을 출력
    }
    
    
    return 0;
}

int find_max(int* ary) { // 최댓값을 구하는 함수
    qsort(ary, MAX_ELEMENTS, sizeof(int), compare); // qsort 함수를 이용한 오름차순 정렬
    return ary[MAX_ELEMENTS-1]; // 정렬된 배열에서 MAX_ELEMENTS-1 번째의 값이 최댓값이므로 반환
}

int compare(const void *a, const void *b) { // qsort() 오름차순으로 정렬하기 위한 로직 함수
    return (*(int*)a - *(int*)b);
}
