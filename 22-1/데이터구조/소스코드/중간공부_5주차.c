// 5주차 실습 ----------------------------------------------------------------------------------------- (4/5) 
// 아래 문제들을 해결하시오 ? 스택을 사용해야 함 
// main()에서는 각 문제들에 대해 임의의 문자열을 키보드 입력하고 함수를 호출하여 테스트 
// 1. 괄호 매칭 번호 매기기 ? 교재 143쪽 문제 11 
// 수식에 있는 괄호의 번호를 출력하는 프로그램을 작성하라. 왼쪽 괄호가 나올 때마다 
// 괄호 번호는 하나씩 증가한다. 오른쪽 괄호가 나오면 매칭되는 왼쪽 괄호의 번호를 출력한다. 
//  예: ( ( ( ) ) ( ( ) ) ) 
//  1 2 3 3 2 4 5 5 4 1 
 
// 2. run-length 압축 - 교재 143쪽 문제 12 
//  다음과 같이 문자열을 압축하는 프로그램을 작성하시오. "4a3b"는 'a'가 4개, 'b'가 3개 있다는 
// 의미이다. 소문자와 대문자는 구분하지 않고, 출력할 때는 소문자로 출력한다. 
//  예: 문자열 입력 aaaAbBb 압축결과 4a3b 
 


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
        fprintf(stderr, "스택이 포화상태입니다\n");
    }
    else{
        s->data[++s->top] = data;
    }
}

Data Pop(Stack *s){
    if(IsEmpty(s)){
        fprintf(stderr, "스택이 비어있는 상태입니다(Pop)\n");
    }
    else{
        return s->data[s->top--];
    }
}

Data Peek(Stack *s){
    if(IsEmpty(s)){
        fprintf(stderr, "스택이 비어있는 상태입니다(Peek)\n");
    }
    else{
        return s->data[s->top];
    }
}

void Barket(){
    Stack s;
    InitStack(&s);
    char arr[MAX_SIZE];
    printf("괄호를 입력해주세요\n");
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
    printf("문자를 입력해주세요\n");
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

// 3. palindrome ? 교재 144쪽 문제 16 
//  회문은 앞뒤 어느 쪽에서 읽어도 같은 단어를 의미한다 (예: "eye" "madam" "race car" 등) 
//  구두점이나 스페이스, 대소문자 등은 무시해야 한다. 
// 스택을 사용해서 주어진 문자열이 회문인지 아닌지 결정하는 프로그램을 작성하시오. 

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
            printf("회문이 아닙니다\n");
            break;
        }
        if(i + 1 == length){
            printf("회문입니다\n");
        }
    }
}

// 4. 다음 연산자들을 포함하는 후위표기식 계산하는 프로그램을 스택을 이용하여 작성하시오. 
// +, -, *, /, ^(거듭제곱) >, <, =(EQ), & (AND), | (OR) 
//  (예) 3 4 + 2 - 2 2 2 ^ * > 7 3 ? 2 / 5 2 * &

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
    printf("수식을 입력해주세요\n");
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
    printf("몇 번 문제를 푸시겠습니까?\n");
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