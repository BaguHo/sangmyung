#include<stdio.h>
#include<stdlib.h>

typedef int Data;

typedef struct{
    Data data;
    struct Node* next;
}Node;

// 필요한 ADT
// push, pop, GetData, IsEmpty, InitList

void InitList(){
    //head, cur, tail
    Node* head = malloc(sizeof(Node));
    Node* tail = malloc(sizeof(Node));
    head->next = NULL;
    tail->next = NULL;
}

void Push(Node* head, Node* tail, Data data){
    Node* new_node = malloc(sizeof(Node));
    new_node->data = data;
    if(head->next == NULL){
        head->next = new_node;
    }
    else{
        tail->next = new_node;
    }
}
 
void Pop(Node* head, Node* tail){
    if(head->next == NULL){
        printf("데이터가 없습니다\n");
    }
    else{
        //여기서 tail의 데이터를 pop할거면 그 이전의 데이터가 필요한데 이것을 Node* pre로 해결해야하나
        //아니면 Node* cur를 사용해야하나
        //pre를 사용하면 이중연결리스트가 되어버리는데 단순연결 리스트안에서 문제를 해결할 수는 없을까?

    }
}

int main(){
    
}