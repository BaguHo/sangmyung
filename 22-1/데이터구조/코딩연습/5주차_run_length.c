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
        fprintf(stderr, "Push_ERROR\n");
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
        fprintf(stderr, "Pop_ERROR\n");
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
        fprintf(stderr, "Peek_Error\n");
        exit(1);
    }
    else
    {
        return s->node[s->top];
    }
}

void RunLength(char* str)
{
    Stack s;
    InitStack(&s);
    char result[MAX_LENGTH];
    int result_idx = 0;
    int n = strlen(str);
    int k;
    for (int i = 0; i < n; i++)
    {
        if (i == 0){
            Push(&s, str[0]);
        }
        else if (str[i] == str[i - 1]){
            Push(&s, str[i]);
        }
        else if(str[i] != str[i - 1])
        {
            //bbbbccaa를 입력하였을 때 a 부분이 a1으로 출력된다(출력값 b4c2a1)
            char temp; 
            result[result_idx] = Peek(&s);
            for (k = 0; !IsEmpty(&s); k++){
                temp = Pop(&s);
            }
            result[result_idx + 1] = k + '0';
            result_idx += 2;
            Push(&s, str[i]);
        }
    }
    if(!IsEmpty(&s)){
        char temp_ch = Pop(&s);
        result[result_idx] = temp_ch;
        result[result_idx + 1] = k + '0';
    }
    int n2 = strlen(result);
    for (int i = 0; i < n2 - 1; i++)
    {
        printf("%c", result[i]);
    }
    printf("\n");
}

void main()
{
    char str[MAX_LENGTH];
    printf("2번문제 - 문자열을 입력해주세요\n");
    scanf("%s", str);
    RunLength(str);
}