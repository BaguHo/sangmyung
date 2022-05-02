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

/*
���������ڵ��������ϴ�����ǥ��İ���ϴ����α׷����������̿��Ͽ��ۼ��Ͻÿ�.
+,-,*,/,^(�ŵ�����) >,<,=(EQ), &(AND), |(OR)  
(��)34+2-222^*>73?2/52*&
*/
void Profix(){
    Stack s;
    InitStack(&s);
    char str[MAX_LENGTH];
    printf("����ǥ��� ������ �Է����ּ���\n");
    scanf("%s", str);
    int a, b, c;
    char ch1, ch2;
    int n = strlen(str);
    for(int i = 0; i < n; i++){
        if('0' <= str[i] && str[i] <= '9'){
            Push(&s, str[i]);
        }
        else if(str[i] == '*' || str[i] == '+' || str[i] == '-' || str[i] == '/' || str[i] == '^' || str[i] == '>' || str[i] == '<'  || str[i] == '=' || str[i] == '&' || str[i] == '|' ){
            b = Pop(&s) - '0';
            a = Pop(&s) - '0';
            switch (str[i])
            {
            case '*':
                c = a * b;
                printf("%d * %d = %d\n", a, b, c);
                // char to int
                Push(&s, c + '0');
                break;
            case '+':
                c = a + b;
                printf("%d + %d = %d\n", a, b, c);
                Push(&s, c + '0');
                break;
            case '-':
                c = a - b;
                printf("%d - %d = %d\n", a, b, c);
                Push(&s, c + '0');
                break;
            case '/':
                c = a / b;
                printf("%d / %d = %d\n", a, b, c);
                Push(&s, c + '0');
                break;
            case '^':
                c = 1;
                for(int k = 0; k < b; k++){
                    c *= a;
                }
                printf("%d ^ %d = %d\n", a, b, c);
                Push(&s, c + '0');
                break;
            case '>':
                c = a > b;
                printf("%d > %d = %d\n", a, b, c);
                Push(&s, c + '0');
                break;
            case '<':
                c = a < b;
                printf("%d < %d = %d\n", a, b, c);
                Push(&s, c + '0');
                break;
            case '=':
                break;
                c = a == b;
                printf("%d = %d = %d\n", a, b, c);
                Push(&s, c + '0');
            case '&':
                c = a && b;
                printf("%d & %d = %d\n", a, b, c);
                Push(&s, c + '0');
                break;
            case '|':
                c = a || b;
                printf("%d | %d = %d\n", a, b, c);
                Push(&s, c + '0');
                break;            
            }    
        }    
   }
   printf("�����: %c\n" ,Pop(&s));
}

int main(){
    Profix();
}

// 34+2-222^*>73-2/52*&