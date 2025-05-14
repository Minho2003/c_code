#include "radioactive_decay.h"

void init_deque(CircularQueue* q) // 덱의 초기화는 큐의 초기화 함수를 호출하면 됨
{
    init_queue(q);
}
void add_rear(CircularQueue* q, Element val) // 후단 삽입은 큐의 enqueue()와 동일
{
    enqueue(q, val);
}
Element delete_front(CircularQueue* q) // 전단 삭제는 큐의 dequeue()와 동일
{
    return dequeue(q);
}
Element get_front(CircularQueue* q) // 전단 참조는 큐의 peek()와 동일
{
    return peek(q);
}
// 큐에 없는 새로운 연산들
void add_front(CircularQueue* q, Element val)
{
    if (is_full(q))
        error("Overflow Error!");
    q->data[q->front] = val;
    q->front = (q->front - 1 + MAX_SIZE) % MAX_SIZE;
}
Element delete_rear(CircularQueue* q)
{
    if (is_empty(q))
        error("Underflow Error!");
    int prev = q->rear;
    q->rear = (q->rear - 1 + MAX_SIZE) % MAX_SIZE;
    return q->data[prev];
}
Element get_rear(CircularQueue* q)
{
    if (is_empty(q))
        error("Underflow Error!");
    return q->data[q->rear];
}

