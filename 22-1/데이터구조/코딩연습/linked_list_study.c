#include<stdio.h>
#include<stdlib.h>

typedef int Data;

typedef struct{
    Data data;
    struct Node* next;
}Node;

// �ܼ����Ḯ��Ʈ
// �ʿ��� ADT
// Insert, Delete, GetData, IsEmpty, InitList

void InitList(){
    //head, cur, tail
    Node* head = malloc(sizeof(Node));
    head->next = NULL;
}

void Push(Node* head, Data data){
    Node* new_node = malloc(sizeof(Node));
    new_node->data = data;
    if(head->next == NULL){
        head->next = new_node;
    }
}

void Pop(Node* head){
    if(head->next == NULL){
        printf("�����Ͱ� �����ϴ�\n");
    }
    else{
        //���⼭ tail�� �����͸� pop�ҰŸ� �� ������ �����Ͱ� �ʿ��ѵ� �̰��� Node* pre�� �ذ��ؾ��ϳ�
        //�ƴϸ� Node* cur�� ����ؾ��ϳ�
        //pre�� ����ϸ� ���߿��Ḯ��Ʈ�� �Ǿ�����µ� �ܼ����� ����Ʈ�ȿ��� ������ �ذ��� ���� ������?
        //pop�� �ƴ϶� delete�� ����ؾ��� �� ����.

    }
}

int main(){
    
}