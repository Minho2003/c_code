#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <sys/time.h>

#define SIZE

void shuffleArray(int arr[], int size) {
    for (int i = size - 1; i > 0; i--) {
        // 0부터 i까지의 인덱스에서 랜덤한 값을 선택
        int j = rand() % (i + 1);

        // swap arr[i] and arr[j]
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

// 🔹 0부터 n까지의 값을 랜덤으로 배열하는 함수
void generateRandomArray(int ary[], int n) {
    // 0부터 n까지의 값을 배열에 넣기
    for (int i = 0; i <= n; i++) {
        ary[i] = i;
    }

    // 배열을 랜덤하게 섞기
    shuffleArray(ary, n + 1);
}

void swap(int ary[], int i, int j){ // ary의 i번째와 j번째의 인덱스를 변경
    int temp=ary[i];
    ary[i]=ary[j];
    ary[j]=temp;
}

int partition(int ary[], int low, int high){ // 배열을 분할하는 함수
    int pivot = ary[high]; // pivot은 마지막 인덱스
    
    int i = low - 1; // pivot의 위치
    
    for ( int j = low; j < high; j++ ){ // pivot 보다 작으면 swap을 통해 앞으로 이동
        if ( ary[j] < pivot){
            i++; // low 앞 순번
            swap(ary, i, j); // j번과 i번 값 변경
        }
    }
    swap(ary, i + 1, high); // pivot의 위치와 low 앞의 위치
    return i + 1; // pivot의 위치 return
}

void quick_sort(int ary[],int low, int high){//랜덤 피벗 보다 작으면 왼쪽 크면 오른쪽 (main에서 동적할당을 하면 int *ary로 만들것)
    if (low < high){
        int pi=partition(ary, low, high);
        
        quick_sort(ary, low, pi - 1); // low부터 이전 pivot 앞 까지
        quick_sort(ary, pi + 1, high); // 이전 pivot 뒤 부터 high까지
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// 🔹 메인 함수
int main(void) {
    struct timeval start, end;

    // 시작 시간 기록
    gettimeofday(&start, NULL);
    
    int n;
    scanf("%d",&n);
    int arr[n + 1]; // 배열 크기 설정

    generateRandomArray(arr, n); // 랜덤 배열 생성
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("정렬 전 배열: ");
    printArray(arr, size);

    quick_sort(arr, 0, size - 1); // 퀵 정렬 실행

    printf("정렬 후 배열: ");
    printArray(arr, size);

    // 종료 시간 기록
    gettimeofday(&end, NULL);

    // 실행 시간 계산 (초 단위와 마이크로초 단위로 계산)
    double elapsed_time = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1000000.0;

    // 실행 시간 출력
    printf("실행 시간: %f 초\n", elapsed_time);
    
    return 0;
}
