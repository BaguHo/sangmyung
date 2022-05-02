#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define MAX_LENGTH 101

typedef char Data;

typedef struct
{
    Data node[MAX_LENGTH];
    int top;
} Stack;

void InitStack(Stack *s)
{
    s->top = -1;
}

int IsEmpty(Stack *s)
{
    return (s->top == -1);
}

int IsFull(Stack *s)
{
    return (s->top == MAX_LENGTH - 1);
}

void Push(Stack *s, Data data)
{
    if (IsFull(s))
    {
        fprintf(stderr, "ERROR\n");
        return;
    }
    else
    {
        s->node[++(s->top)] = data;
    }
}

Data Pop(Stack *s)
{
    if (IsEmpty(s))
    {
        fprintf(stderr, "ERROR\n");
        exit(1);
    }
    else
    {
        return s->node[(s->top)--];
    }
}

Data Peek(Stack *s)
{
    if (IsEmpty(s))
    {
        fprintf(stderr, "������ ���� ERROR\n");
        exit(1);
    }
    else
    {
        return s->node[s->top];
    }
}

int Barket()
{
    Stack s;
    InitStack(&s);
    char str[MAX_LENGTH];
    printf("��ȣ�� �Է����ּ���\n");
    scanf("%s", str);
    int n = strlen(str);
    for (int i = 0; i < n; i++)
    {
        char ch = str[i];
        switch(ch)
        {
        case '(': case '{': case '[':
            Push(&s, str[i]);
            printf("%d ", s.top + 1);
            break;
        case ')': case '}': case ']':
            if(IsEmpty(&s)) 
                return 0;
            else{
                char ch2 = Pop(&s);
                printf("%d ", s.top + 2);
                if(ch2 == '(' && ch != ')' || (ch2 == '{' && ch != '}') || ch2 == '[' && ch != ']'){
                    return 0;
                }
                break;
            }
        }
    }
    printf("\n");
    if(!IsEmpty(&s)) return 0;
    return 1;
}

int main()
{
    if(Barket() == 1){
        printf("��ȣ �˻� ����\n");
    }
    else{
        printf("��ȣ �˻� ����\n");
    }
}