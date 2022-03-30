#include<stdio.h>
#include<stdlib.h>
#define TRUE 1
#define FALSE 0

//1번 문제
//1. 괄호 매칭 번호 매기기 ? 교재 143쪽 문제 11
//수식에 있는 괄호의 번호를 출력하는 프로그램을 작성하라. 
//왼쪽 괄호가 나올 때마다 괄호 번호는 하나씩 증가한다.오른쪽 괄호가 나오면 매칭되는 왼쪽 괄호의 번호를 출력한다.
//((()) (()))
//12332 45541

//2. run-length 압축 -  교재 143쪽 문제 12
//다음과 같이 문자열을 압축하는 프로그램을 작성하시오.  "4a3b"는 'a'가 4개, 'b'가 3개 있다는 의미이다.
//이러한 압축 방법을 런길이 압축이라고 한다.소문자와 대문자는 구분하지 않는다.
//압축된 문자열에서는 소문자로 출력한다.스택의 peek() 연산을 고려해보자.
//  예: 문자열 입력 aaaAbBb     압축결과 4a3b

//3. palindrome ? 교재 144쪽 문제 16
//회문은 앞뒤 어느 쪽에서 읽어도 같은 단어를 의미한다.예를 들면 "eye" "madam" "race car"  등이다.
//여기서 물로 구두점이나 스페이스, 대소문자 등은 무시해야 한다.스택을 사용해서 주어진 문자열이
//회문인지 아닌지 결정하는 프로그램을 작성하시오.
//예: 입력 문자열 "madam" 이면 출력은 "madam은 회문입니다"

typedef int Data;

typedef struct __node{
    Data data;
    struct Node* next;
}Node;

typedef struct{
    Node* head;
    int count;
}Stack;

void InitStack(Stack *s){
    s->head = NULL;
}

int IsEmpty(Stack s){
    if(s.count == 0){
        return TRUE;
    }
    else{
        return FALSE;
    }
}

void Push(Stack *s, Data data){
    Node *new_node = malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = s->head;
    s->head = new_node;
}

Data Pop(Stack *s){
    Node* temp_node;
    Data data;

    if(IsEmpty(*s)){
        printf("스택이 비었습니다\n");
        exit(-1);
    }
    data = s->head->data;
    temp_node = s->head;

    s->head = s->head->next;
    free(temp_node);
    return data;
    
}

int main(){
    
}