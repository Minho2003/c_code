// 스택의 데이터(Element와 MAX_SIZE는 미리 정의되어 있어야 함)
Element data[MAX_SIZE]; // 스택 요소의 배열
int top; // 스택 상단 인덱스
void error(char str[])
{
    printf("%s\n", str);
    exit(1);
}
// 스택의 주요 연산들
void init_stack(void)
{
    top = -1;
}
int is_empty(void)
{
    if (top == -1) return 1;
    else return 0;
}
int is_full(void)
{
    return (top == (MAX_SIZE - 1));
}
void push(Element e)
{
    if (is_full())
        error("Overflow Error!");
    else data[++top] = e;
}
Element pop(void)
{
    if (is_empty())
        error("Underflow Error!");
    return data[top--];
}
Element peek(void)
{
    if (is_empty())
        error("Underflow Error!");
    return data[top];
}

int size(void)
{
    return top + 1;
}
