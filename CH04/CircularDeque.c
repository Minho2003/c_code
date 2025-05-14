#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10
// #define Element int
#include "radioactive_decay_2.h"

// 덱 요소의 출력 함수. front+1부터 size개의 요소를 순서대로 출력
void print_deque(CircularQueue* q,char* msg) {
    printf("%s front=%.0d, rear=%d --> ", msg, q->front, q->rear);
    int size = (q->rear - q->front + MAX_SIZE) % MAX_SIZE;

    for (int i = q->front + 1; i <= q->front + size; i++)
        printf("%.0f ", q->data[i % MAX_SIZE]);
    printf("\n");
}

int main(void)
{
    CircularQueue q;
    init_deque(&q);
    for (int i = 1; i < 10; i++) {
        if (i % 2) add_front(&q,i);    // i가 홀수이면 전단으로 삽입
        else add_rear(&q,i);           // 짝수이면 후단으로 삽입
    }
    print_deque(&q,"원형 덱 홀수-짝수 ");
    printf("\tdelete_front() --> %.0f\n", delete_front(&q));
    printf("\tdelete_rear () --> %.0f\n", delete_rear(&q));
    printf("\tdelete_front() --> %.0f\n", delete_front(&q));
    print_deque(&q,"원형 덱 삭제-홀짝홀");
    
    return 0;
}
