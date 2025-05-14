Element data[MAX_SIZE]; // 요소의 배열
int front; // 전단 인덱스
int rear; // 후단 인덱스

void error(char* str)
{
    printf("%s\n", str);
    exit(1);
}
// 원형 큐의 주요 연산들
void init_queue(void)
{
    front = rear = 0;
}
int is_empty(void)
{
    return front == rear;
}
int is_full(void)
{
    return front == (rear + 1) % MAX_SIZE;
}
void enqueue(Element val)
{
    if (is_full())
        error("Overflow Error!");
    rear = (rear + 1) % MAX_SIZE;
    data[rear] = val;
}
// 원형큐의 삭제 연산
Element dequeue(void)
{
    if (is_empty())
        error("Underflow Error!");
    front = (front + 1) % MAX_SIZE;
    return data[front];
}
// 원형큐의 탐색(peek) 연산
Element peek(void)
{
    if (is_empty())
        error("Underflow Error!");
    return data[(front + 1) % MAX_SIZE];
}
