#include <stdio.h>

#define MAX_ELEMENTS 10
int NUM_ARY[MAX_ELEMENTS]; //전역 배열

int sequential_search(int A[], int n, int key);

int main(void){
    int num, key, i;
    int NUM_ARY[MAX_ELEMENTS] = { 5, 9, 10, 17, 21, 29, 33, 37, 38, 43 };

    
    printf("테스트 케이스의 수를 입력하시오 : "); // 테스트 할 횟수를 직접 설정
    scanf("%d",&num);
    
    for ( i = 0; i < num; i++){ // 테스트 케이스의 수 만큼 반복
        printf("찾고싶은 수를 입력하시오 : ");
        scanf("%d", &key); // 찾고자 하는 수를 입력받아 찾기
        printf("%d의 위치는 %d\n", key, sequential_search(NUM_ARY, MAX_ELEMENTS, key));
    }
    
    return 0;
}

int sequential_search(int* A, int n, int key){
    for (int i = 0; i<n; i++)
    if (A[i] == key)
        return i;        // 탐색이 성공하면 인덱스 반환
    return -1;            // 탐색이 실패하면 -1 반환
}
