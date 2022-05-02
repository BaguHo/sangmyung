#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// ���� ����Ʈ �����
// ���� ���� head, �߰�, ������ ��ġ�� �����ϴ� �Լ�
// �� ���� ����� �� �� �� �ִ� �ϳ��� �Լ� -> cur�� ���� ������ ���� �� ����

// �������굵 ��������
// head�� �ϳ��� ���� ���� ������ �����ؾ� �Ѵ�

// ���ĵǾ� �ִ� �ܼ����Ḯ��Ʈ���� ���� �����ؼ� �ִ� ���

// �湮�ڵ�(ó������ ������ ��ĵ)
// Count, Node* SearchValue(Node *head, Element x) ����� ���
// ����, ������ cur�� �ұ� �ƴϸ� value�� �ؾ��ұ�?
// �� ���� ����Ʈ�� ���ϴ� �Լ�
// 1. 2�� �� NULL
// 2. �� �� �ϳ��� NULL
// 3. ��� �� NULL�� �ƴ�
// �ܼ� ���� ����Ʈ���� ȭ��ǥ ������ �ٲٴ� �Լ�(��������, head�� �ٲ���� ��)

// ���Ḯ��Ʈ�� ���׽� ��Ÿ����

typedef int Element;

typedef struct {
    Element data;
    struct Node* next;
}Node;

// ���� ����� next�� �����ϰ� ���� ��带 �߰��� ���� �����Ѵ�
Node* InsertNextNode(Node* cur, Element value){ 
    Node* p = (Node*)malloc(sizeof(Node));
    p->data = value;
    p->next = cur->next;
    cur->next = p;
    cur = p;
    return cur;
}
// ���� ��带 �����Ѵ�
Node* DeleteNode(Node* cur){
    Node* p;
    p = cur->next;
    free(cur->next);
    cur->next = p->next;
    return cur;
}

// ���� ���ĵ� ����Ʈ���� ���������� ���� �˾Ƽ� �����ϴ� �Լ�
Node* InsertSortedList(Node* head, Element data){
       
}

// Ư���� ���� �ִ� Node�� ã�� �Լ� 
Node* Search(Node* head, Element data){
    for(Node* p = head; p != NULL; p = p->next){
        if(p->data == data){
            return p;
        }
    }
    printf("ã�� ���� �����ϴ�\n");
    return 0;
}

// 2���� ����Ʈ�� �����ϴ� �Լ�
Node* ConcatList(Node* head1, Node* head2){
    if(head1 == NULL) return head2;
    else{
        Node* p;
        p = head1;
        while(p->next != NULL)
            p = p->next;
        p->next = head2;
        return head1;
    }
}

int main(){
    
}