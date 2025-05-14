#include "CircularQueue.h"

void init_deque(void) // 덱의 초기화는 큐의 초기화 함수를 호출하면 됨
{
    init_queue();
}
void add_rear(Element val) // 후단 삽입은 큐의 enqueue()와 동일
{
    enqueue(val);
}
Element delete_front(void) // 전단 삭제는 큐의 dequeue()와 동일
{
    return dequeue();
}
Element get_front(void) // 전단 참조는 큐의 peek()와 동일
{
    return peek();
}
// 큐에 없는 새로운 연산들
void add_front(Element val)
{
    if (is_full())
        error("Overflow Error!");
    data[front] = val;
    front = (front - 1 + MAX_SIZE) % MAX_SIZE;
}
Element delete_rear(void)
{
    if (is_empty())
        error("Underflow Error!");
    int prev = rear;
    rear = (rear - 1 + MAX_SIZE) % MAX_SIZE;
    return data[prev];
}
Element get_rear(void)
{
    if (is_empty())
        error("Underflow Error!");
    return data[rear];
}

