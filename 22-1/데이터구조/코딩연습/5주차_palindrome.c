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
        fprintf(stderr, "에러\n");
        exit(1);
    }
    else
    {
        return s->node[s->top];
    }
}

void Palindrome()
{
    char *str = malloc(sizeof(char) * 50);
    printf("3번문제 - 문자열을 입력해주세요\n");
    scanf("%[^\n]s", str);

    Stack s;
    InitStack(&s);
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (('a' <= str[i] && str[i] <= 'z') || ('A' <= str[i] && str[i] <= 'Z'))
        {
            str[i] = tolower(str[i]);
            Push(&s, str[i]);
        }
    }
    //스택을 이용하여 회문 검사
    char ch;
    for (int i = 0; str[i] != '\0'; i++)
    {
        if ('a' <= str[i] && str[i] <= 'z')
        {
            ch = Pop(&s);
            if (ch == str[i])
            {
                printf("%c %c\n", ch, str[i]);
            }
            else
            {
                printf("회문이 아닙니다\n");
                break;
            }
        }
        if (str[i + 1] == '\0')
        {
            printf("회문입니다\n");
        }
    }
    free(str);
}

int main()
{
    Palindrome();
}