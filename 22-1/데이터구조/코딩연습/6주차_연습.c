#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define MAX_ARRAY_SIZE 101

typedef char Data;

typedef struct
{
    Data node[MAX_ARRAY_SIZE];
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

//����ǥ������� ���� ���
//1)������ ������ %���� (5+7%3-2*3)
//2)�ŵ����������� ^����(3+2^3^2-1)
//3)���迬���� '<'�� '>�� ���� (3+4-2>(2*3)^2)
//1.573%+23*-
//2.3232^^+1-
//3.34+2-23*2^>
//�ǿ����ں����Ѱ�� 573%+23*--
//�����ں����Ѱ�� 573%+233*-
//���ο�� 1. 12*3+31%3+> (������,�ε�ȣ)
//���ο�� 2. 522*-2+1- (�Ϲݽ�)
//���ο�� 3. 53%2+142*+< (������,�ε�ȣ)
//���ο�� 4. 22^3+4- (�ŵ�����)

int CaculateProfix(char *str){
    Stack s;
    InitStack(&s);
    int a, b, c;
    char ch1, ch2;
    int n = strlen(str);
    for(int i = 0; i < n; i++){
        if('0' <= str[i] && str[i] <= '9'){
            Push(&s, str[i]);
        }
        else if(str[i] == '*' || str[i] == '+' || str[i] == '-' || str[i] == '/' ||
                str[i] == '^' || str[i] == '>' || str[i] == '<' || str[i] == '=' ||
                str[i] == '&' || str[i] == '|' ){
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
                for(int k = 0; k < a; k++){
                    c *= b;
                }
                printf("%d ^ %d = %d\n", b, a, c);
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
    // printf("�����: %d\n", Pop(&s) - '0');
    return Pop(&s) - '0';
}

int GetPriority(char op){
    switch (op)
    {
    case '(': case ')':
        return 0;
        break;
    case '&': case '|': case '>': case '<':
        return 1;
        break;
    case '+': case '-': 
        return 2;
        break; 
    case '*': case '/': case '%':
        return 3;
        break; 
    case '^': 
        return 4;
        break;
    }
    return -2;
}

void ConvertInfixToPostfix(char *infix_arr){
    Stack s;
    InitStack(&s);
    char temp[MAX_ARRAY_SIZE];
    int temp_idx = 0;
    int length = strlen(infix_arr);
    for(int i = 0; i < length; i++){
        if('0' <= infix_arr[i] && infix_arr[i] <= '9'){
            temp[temp_idx++] = infix_arr[i];
        }
        else if(infix_arr[i] == '+' || infix_arr[i] == '-' || infix_arr[i] == '*' || infix_arr[i] == '/' || 
                infix_arr[i] == '%' || infix_arr[i] == '^' || infix_arr[i] == '>' || infix_arr[i] == '<' || 
                infix_arr[i] == '=' || infix_arr[i] == '&' || 
                infix_arr[i] == '|' ){
                    if(!IsEmpty(&s)){
                        // '(' �κп��� 23*^ �̾���ϴµ� 232^*�̴�
                        if(infix_arr[i] == '('){
                            Push(&s, infix_arr[i]);
                            length--;
                        }
                        else if(infix_arr[i] == ')'){
                            while(Peek(&s) != '('){
                                temp[temp_idx++] = Pop(&s);
                            }
                            Pop(&s);
                        }
                        else if (GetPriority(Peek(&s)) <= GetPriority(infix_arr[i])){
                            Push(&s, infix_arr[i]);
                        }
                        else{
                            while(!IsEmpty(&s)){
                                temp[temp_idx++] = Pop(&s);
                            }
                            Push(&s, infix_arr[i]);
                        }
                    }
                    else{
                        Push(&s, infix_arr[i]);
                    }
        }
    }
    while(!IsEmpty(&s)){
        temp[temp_idx++] = Pop(&s);
    }
    for(int i = 0; i < length; i++){
        infix_arr[i] = temp[i];
        printf("%c", infix_arr[i]);
    }
    printf("\n");
}


int main(){
    char infix_arr[MAX_ARRAY_SIZE];
    printf("������ �Է����ּ���\n");
    scanf("%[^\n]s", infix_arr);
    printf("����ǥ���\n");
    ConvertInfixToPostfix(infix_arr);
    printf("�����: %d\n", CaculateProfix(infix_arr));
    return 0;
}