// 5���� �ǽ� ----------------------------------------------------------------------------------------- (4/5) 
// �Ʒ� �������� �ذ��Ͻÿ� ? ������ ����ؾ� �� 
// main()������ �� �����鿡 ���� ������ ���ڿ��� Ű���� �Է��ϰ� �Լ��� ȣ���Ͽ� �׽�Ʈ 
// 1. ��ȣ ��Ī ��ȣ �ű�� ? ���� 143�� ���� 11 
// ���Ŀ� �ִ� ��ȣ�� ��ȣ�� ����ϴ� ���α׷��� �ۼ��϶�. ���� ��ȣ�� ���� ������ 
// ��ȣ ��ȣ�� �ϳ��� �����Ѵ�. ������ ��ȣ�� ������ ��Ī�Ǵ� ���� ��ȣ�� ��ȣ�� ����Ѵ�. 
//  ��: ( ( ( ) ) ( ( ) ) ) 
//  1 2 3 3 2 4 5 5 4 1 
 
// 2. run-length ���� - ���� 143�� ���� 12 
//  ������ ���� ���ڿ��� �����ϴ� ���α׷��� �ۼ��Ͻÿ�. "4a3b"�� 'a'�� 4��, 'b'�� 3�� �ִٴ� 
// �ǹ��̴�. �ҹ��ڿ� �빮�ڴ� �������� �ʰ�, ����� ���� �ҹ��ڷ� ����Ѵ�. 
//  ��: ���ڿ� �Է� aaaAbBb ������ 4a3b 
 


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define MAX_SIZE 100

typedef char Data;

typedef struct{
    Data data[MAX_SIZE];
    int top;
}Stack;

int IsEmpty(Stack *s){
    if(s->top == -1)
        return 1;
    else
        return 0;
}

int IsFull(Stack *s){
    if(s->top == MAX_SIZE)
        return 1;
    else
        return 0;
}

void InitStack(Stack *s){
    s->top = -1;
}

void Push(Stack *s, Data data){
    if(IsFull(s)){
        fprintf(stderr, "������ ��ȭ�����Դϴ�\n");
    }
    else{
        s->data[++s->top] = data;
    }
}

Data Pop(Stack *s){
    if(IsEmpty(s)){
        fprintf(stderr, "������ ����ִ� �����Դϴ�(Pop)\n");
    }
    else{
        return s->data[s->top--];
    }
}

Data Peek(Stack *s){
    if(IsEmpty(s)){
        fprintf(stderr, "������ ����ִ� �����Դϴ�(Peek)\n");
    }
    else{
        return s->data[s->top];
    }
}

void Barket(){
    Stack s;
    InitStack(&s);
    char arr[MAX_SIZE];
    printf("��ȣ�� �Է����ּ���\n");
    scanf("%s", arr);
    int idx = 1;
    for(int i = 0; arr[i] != '\0'; i++){
        if(arr[i] == '('){
            printf("%d ", idx++);
            Push(&s, (idx - '0'));
        }
        else if(arr[i] == ')'){
            printf("%d ", (Pop(&s) + '0') - 1);
        }
    }
}

void RunLength(){
    Stack s;
    InitStack(&s);
    char arr[MAX_SIZE];
    char result[MAX_SIZE];
    printf("���ڸ� �Է����ּ���\n");
    scanf("%s", arr);
    int idx = 0;
    char ch = arr[0];
    Push(&s, ch);
    int i;
    for(i = 1; arr[i] != '\0'; i++){
        if(arr[i] == ch){
            Push(&s, ch);
        }
        else{
            result[idx++] = Peek(&s);
            ch = arr[i];
            int temp = 0;
            while(!IsEmpty(&s)){
                Pop(&s);
                temp++;
            }
            Push(&s, arr[i]);
            result[idx++] = temp + '0';
        }
    }
    if(!IsEmpty(&s)){
        result[idx++] = Peek(&s);
        int temp = 0;
        while(!IsEmpty(&s)){
            Pop(&s);
            temp++;
        }
        Push(&s, arr[i]);
        result[idx++] = temp + '0';
    }
    for(int i = 0; i < idx; i++){
        printf("%c", result[i]);
    }
}

// 3. palindrome ? ���� 144�� ���� 16 
//  ȸ���� �յ� ��� �ʿ��� �о ���� �ܾ �ǹ��Ѵ� (��: "eye" "madam" "race car" ��) 
//  �������̳� �����̽�, ��ҹ��� ���� �����ؾ� �Ѵ�. 
// ������ ����ؼ� �־��� ���ڿ��� ȸ������ �ƴ��� �����ϴ� ���α׷��� �ۼ��Ͻÿ�. 

int Palindrome(){
    Stack s;
    InitStack(&s);
    char arr[MAX_SIZE];
    int temp;
    scanf("%d", temp);
    scanf("%[^\n]s", arr);
    int length = strlen(arr);
    for(int i = 0; i < length; i++){
        if( ('a' <= arr[i] && arr[i] <= 'z') || ('A' <= arr[i] && arr[i] <= 'Z') ){
            arr[i] = tolower(arr[i]);
            Push(&s, arr[i]);
        }
        else{
            for(int k = i; k < length; k++){
                arr[k] =  arr[k + 1];
            }
            length--;
            arr[i] = tolower(arr[i]);
            Push(&s, arr[i]);
        }
    }
    int i;
    for(i = 0; i < length; i++){
        printf("%c %c \n", arr[i], Peek(&s));
        if(arr[i] != Pop(&s)){
            printf("ȸ���� �ƴմϴ�\n");
            break;
        }
        if(i + 1 == length){
            printf("ȸ���Դϴ�\n");
        }
    }
}

// 4. ���� �����ڵ��� �����ϴ� ����ǥ��� ����ϴ� ���α׷��� ������ �̿��Ͽ� �ۼ��Ͻÿ�. 
// +, -, *, /, ^(�ŵ�����) >, <, =(EQ), & (AND), | (OR) 
//  (��) 3 4 + 2 - 2 2 2 ^ * > 7 3 ? 2 / 5 2 * &

int GetPriority(char op){
    switch (op)
    {
    // case ')':
    //     return -1;
    case '(': 
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
    return -5;
}

void Postfix(){
    char str[MAX_SIZE];
    printf("������ �Է����ּ���\n");
    scanf("%s", str);
    ConvertInfixToPostfix(str);
    CalculatePostfix(str);
}

int CalculatePostfix(char *str){
    
}

void ConvertInfixToPostfix(char *str){
    Stack s;
    InitStack(&s);
    char result[MAX_SIZE];
    int idx = 0;
    for(int i = 0; str[i] != '\0'; i++){
        if(isdigit(str[i])){
            result[idx++] = str[i];
        }
        else{
            if(IsEmpty(&s)){
                Push(&s, str[i]);
            }
            else if(str[i] == ')'){
                while(Peek(&s) == '('){
                    result[idx++] = Pop(&s);
                }
                Pop(&s);   
            }
            else{
                while(IsEmpty(&s) || GetPriority(str[i]) > GetPriority(Peek(&s))){
                    result[idx++] = Pop(&s);
                }
                Push(&s, str[i]);
            }
        }
    }
    while(!IsEmpty(&s)){
        result[idx++] = Pop(&s);
    }
    for(int i = 0; i < idx; i++){
        str[i] = result[i];
    }
    str[idx] = '\0';
    return 0;
}

int main(){
    int qurter;
    printf("�� �� ������ Ǫ�ðڽ��ϱ�?\n");
    printf("1. Barket check\n");
    printf("2. Run_length\n");
    printf("3. Palindrome\n");
    printf("4. profix\n");
    scanf("%d", &qurter);
    printf("==================================\n");
    switch (qurter)
    {
    case 1:
        Barket();
        break;
    case 2:
        RunLength();
        break;
    case 3:
        Palindrome();
        break;
    case 4:
        PostFix();
        break;
    }
}