#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define MAX_ARRAY_SIZE 101

typedef char Data;

typedef struct
{
    Data node[MAX_ARRAY_SIZE];
    int node2[MAX_ARRAY_SIZE];
    int top;
} Stack;

void InitStack(Stack* s)
{
    s->top = -1;
}

int IsEmpty(Stack* s)
{
    return (s->top == -1);
}

int IsFull(Stack* s)
{
    return (s->top == MAX_ARRAY_SIZE - 1);
}

void Push(Stack* s, Data data)
{
    if (IsFull(s))
    {
        fprintf(stderr, "Push ERROR\n");
        return;
    }
    else
    {
        s->node[++(s->top)] = data;
    }
}

void Push2(Stack* s, int data)
{
    if (IsFull(s))
    {
        fprintf(stderr, "Push ERROR\n");
        return;
    }
    else
    {
        s->node2[++(s->top)] = data;
    }
}

Data Pop(Stack* s)
{
    if (IsEmpty(s))
    {
        fprintf(stderr, "Pop ERROR\n");
        exit(1);
    }
    else
    {
        return s->node[(s->top)--];
    }
}
int Pop2(Stack* s)
{
    if (IsEmpty(s))
    {
        fprintf(stderr, "Pop ERROR\n");
        exit(1);
    }
    else
    {
        return s->node2[(s->top)--];
    }
}

int Peek2(Stack* s)
{
    if (IsEmpty(s))
    {
        fprintf(stderr, "Pop ERROR\n");
        exit(1);
    }
    else
    {
        return s->node2[(s->top)--];
    }
}

Data Peek(Stack* s)
{
    if (IsEmpty(s))
    {
        fprintf(stderr, "Peek Error\n");
        exit(1);
    }
    else
    {
        return s->node[s->top];
    }
}


// 후위표기수식의 값을 계산
// 좌향결합성
// (4+9-1)%(2+1)
// 3+2^3^2-1
// 3+4-2>2*3^2
// 3+4-2>2*2^2&(5-3)%2<5*2
// 후위표기
// 49+1-21+%
// 323^+2^1-
// 34+2-222^*>53-2%52*<&

// 3+2^3^2-1
// 3+4-2>2*2^2&(5-3)%2<5*2
int CaculateProfix(char *str){
    Stack s;
    InitStack(&s);
    int a, b, c;
    int n = strlen(str);
    int num = 0;
    for(int i = 0; i < n; i++){
        if('0' <= str[i] && str[i] <= '9'){
            Push2(&s, str[i] - '0');
        }
        else if(str[i] == '*' || str[i] == '+' || str[i] == '-' || str[i] == '/' ||
                str[i] == '^' || str[i] == '>' || str[i] == '<' || str[i] == '=' ||
                str[i] == '&' || str[i] == '|' || str[i] == '%' ){

            b = Pop2(&s);
            a = Pop2(&s);
            
            switch (str[i])
            {
            case '*':
                c = a * b;
                printf("%d * %d = %d\n", a, b, c);
                Push2(&s, c);
                break;
            case '+':
                c = a + b;
                printf("%d + %d = %d\n", a, b, c);
                Push2(&s, c);
                break;
            case '-':
                c = a - b;
                printf("%d - %d = %d\n", a, b, c);
                Push2(&s, c);
                break;
            case '/':
                c = a / b;
                printf("%d / %d = %d\n", a, b, c);
                Push2(&s, c);
                break;
            case '%':
                c = a % b;
                printf("%d %% %d = %d\n", a, b, c);
                Push2(&s, c);
                break;
            case '^':
                c = 1;
                for(int k = 0; k < b; k++){
                    c *= a;
                }
                printf("%d ^ %d = %d\n", a, b, c);
                Push2(&s, c);
                break;
            case '>':
                c = a > b;
                printf("%d > %d = %d\n", a, b, c);
                Push2(&s, c);
                break;
            case '<':
                c = a < b;
                printf("%d < %d = %d\n", a, b, c);
                Push2(&s, c);
                break;
            case '=':
                break;
                c = a == b;
                printf("%d = %d = %d\n", a, b, c);
                Push2(&s, c);
            case '&':
                c = a && b;
                printf("%d & %d = %d\n", a, b, c);
                Push2(&s, c);
                break;
            case '|':
                c = a || b;
                printf("%d | %d = %d\n", a, b, c);
                Push2(&s, c);
                break;
            }    
        }
        else{
            Push2(&s, str[i] - '0');
            printf("Push: %c\n", str[i]);
        }
    }
    return (Pop2(&s) );
}

int GetPriority(char op){
    switch (op)
    {
    case '(': //case ')':
        return 0;
    case '&': case '|': 
        return 1;
    case '>': case '<':
        return 2;
    case '+': case '-': 
        return 3;
    case '*': case '/': case '%':
        return 4;
    case '^': 
        return 5;
    }
    return -1;
}

void ConvertInfixToPostfix(char *infix_arr){
    Stack s;
    InitStack(&s);
    char temp[MAX_ARRAY_SIZE];
    int temp_idx = 0;
    int n = 0;
    int length = strlen(infix_arr);
    for(int i = 0; i < length; i++){
        if('0' <= infix_arr[i] && infix_arr[i] <= '9'){
            temp[temp_idx++] = infix_arr[i];
        }
        else if(infix_arr[i] == '+' || infix_arr[i] == '-' || infix_arr[i] == '*' || infix_arr[i] == '/' || 
                infix_arr[i] == '%' || infix_arr[i] == '^' || infix_arr[i] == '>' || infix_arr[i] == '<' || 
                infix_arr[i] == '=' || infix_arr[i] == '&' || 
                infix_arr[i] == '|' || infix_arr[i] == '(' || infix_arr[i] == ')' ){
            if(!IsEmpty(&s)){
                if(infix_arr[i] == '('){
                    Push(&s, infix_arr[i]);
                    printf("push: %c\n", infix_arr[i]);
                    n++;
                }
                else if(infix_arr[i] == ')'){
                    while(Peek(&s) != '('){
                        printf("Pop: %c\n", Peek(&s));
                        temp[temp_idx++] = Pop(&s);
                        n++;
                    }
                    printf("Pop: %c\n", Peek(&s));
                    Pop(&s);
                }
                else if (GetPriority(Peek(&s)) < GetPriority(infix_arr[i]) || Peek(&s) == '^' && infix_arr[i] == '^'){
                    Push(&s, infix_arr[i]);
                    printf("push: %c\n", infix_arr[i]);
                }
                else { 
                    while(!IsEmpty(&s) && ((GetPriority(Peek(&s)) >= GetPriority(infix_arr[i])))){
                            printf("Pop: %c\n", Peek(&s));
                            temp[temp_idx++] = Pop(&s);
                    }
                    Push(&s, infix_arr[i]);
                    printf("push: %c\n", infix_arr[i]);
                }
            }
            else if(infix_arr[i] == '('){
                    Push(&s, infix_arr[i]);
                    printf("push: %c\n", infix_arr[i]);
                    n++;
            }
            else{
                Push(&s, infix_arr[i]);
                printf("push: %c\n", infix_arr[i]);
            }
        }
    }
    while(!IsEmpty(&s)){
        temp[temp_idx++] = Pop(&s);
        printf("Pop: %c\n", temp[temp_idx - 1]);
    }
    printf("후위표기법\n");
    for(int i = 0; i < length - n; i++){
        infix_arr[i] = temp[i];
        printf("%c", infix_arr[i]);
    }
    for(int i = length - n; i < length; i++){
        infix_arr[i] = '0';
    }
    printf("\n");
}

int main(){
    char infix_arr[MAX_ARRAY_SIZE];
    printf("수식을 입력해주세요\n");
    scanf("%[^\n]s", infix_arr);
    ConvertInfixToPostfix(infix_arr);
    printf("결과값: %d\n", CaculateProfix(infix_arr));
    return 0;
}