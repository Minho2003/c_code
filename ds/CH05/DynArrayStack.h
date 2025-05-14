// 스택의 데이터(Element는 미리 정의되어 있어야 함)
int MAX_SIZE = 10;
Element* data = NULL;
int top;

//-------------------------------------------------------------
void error(char str[])
{
    printf("%s\n", str);
    exit(1);
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
//-------------------------------------------------------------

void init_stack(void)
{
    data = (Element*)malloc(sizeof(Element) * MAX_SIZE);
    top = -1;
}

void push(Element e)
{
    if (is_full()) {
        MAX_SIZE *= 2; // 용량을 두 배 늘림
        data = (Element*)realloc(data, sizeof(Element) * MAX_SIZE);
        printf(" realloc(%d)\n", MAX_SIZE);
        // error("Overflow Error!");
    }
    data[++top] = e;
}

//-------------------------------------------------------------
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
