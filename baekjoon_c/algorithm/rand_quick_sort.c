#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

//#define SIZE

void swap(int* ary, int i, int j){ // ary의 i번째와 j번째의 인덱스를 변경
    int temp=ary[i];
    ary[i]=ary[j];
    ary[j]=temp;
}

int rand_idx(int* ary, int low, int high){ //start부터 end-1까지의 인덱스중 랜덤
    int rand_index = low + rand() % (high - low + 1);
    
    swap(ary, high, rand_index);
    
    return ary[high];
}


int partition(int* ary, int low, int high){ // 배열을 분할하는 함수
    int pivot = rand_idx(ary,low,high); // pivot은 랜덤 인덱스
    
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



int main(void) {
    int arr;
    int n = sizeof(arr) / sizeof(arr[0]);

    quick_sort(arr, 0, n - 1); // 퀵 정렬 실행
    
    return 0;
}
