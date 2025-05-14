#define MAX_SIZE 10

typedef double Element;

typedef struct {
    Element data[MAX_SIZE];
    int front;
    int rear;
} CircularQueue;

void error(char* str)
{
    printf("%s\n", str);
    exit(1);
}


void init_queue(CircularQueue* q) {
    q->front = q->rear = 0;
}

int is_empty(CircularQueue* q) {
    return q->front == q->rear;
}

int is_full(CircularQueue* q) {
    return q->front == (q->rear + 1) % MAX_SIZE;
}

void enqueue(CircularQueue* q, Element val) {
    if (is_full(q))
        error("Overflow Error!");
    q->rear = (q->rear + 1) % MAX_SIZE;
    q->data[q->rear] = val;
}

Element dequeue(CircularQueue* q) {
    if (is_empty(q))
        error("Underflow Error!");
    q->front = (q->front + 1) % MAX_SIZE;
    return q->data[q->front];
}

Element peek(CircularQueue* q) {
    if (is_empty(q))
        error("Underflow Error!");
    return q->data[(q->front + 1) % MAX_SIZE];
}
/*
void print_queue(CircularQueue* q, char* msg) { // 큐의 내용을 화면에 출력하는 함수
    printf("%s front=%d, rear=%d --> ", msg, q->front, q->rear);
    int size = (q->rear - q->front + MAX_SIZE) % MAX_SIZE;
    for (int i = q->front + 1; i <= q->front + size; i++)
        printf("%.1lf ", q->data[i % MAX_SIZE]);
    printf("\n");
}
 
void print_cal_decay(CircularQueue* n, CircularQueue* t, CircularQueue* k){
    double result;
    
    printf("front=%d, rear=%d --> ", n->front, n->rear);
    double size = (n->rear - n->front + MAX_SIZE) % MAX_SIZE;

    printf("현재 방사능 수치는 ");
    for ( int i = n -> front + 1; i <= n-> front + size;i++){
        result= n->data[i % MAX_SIZE] * exp(-(t->data[i % MAX_SIZE]*k->data[i % MAX_SIZE]));
        printf("%.0lf에서 %.5lf 남음 ",n->data[i % MAX_SIZE], result);
    }
    printf("\n");
    
}
*/
