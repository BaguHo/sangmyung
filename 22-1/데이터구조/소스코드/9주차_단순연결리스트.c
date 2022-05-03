#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*
���Ḯ��Ʈ �ǽ� (�غ�)

(1)  ������ { ���ڿ� ��ȭ����, ���� �帣, ���� �����⵵ }�� �����ϴ� ���Ḯ��Ʈ �����
   �ڷᱸ�� �����Ͻÿ� (���⼭ �帣�� ��A��, ��C��, ��F��, ��R�� �� �ϳ�)

(2)  �� ��带 ���� ����Ʈ�� Ư�� ��ġ�� �����ϴ� �Լ� insert_node( ) �ۼ��Ͻÿ�
   (������ ����ó�� insert_first( )�� Ư�� ��ġ�� �����ؼ� �����ϴ� insert( )�� ���� �ۼ��� �� ����)

(3)  ���� ����Ʈ�� ����� ����� ������ ����ؼ� ��ȯ�ϴ� �Լ� list_length( ) �� �ۼ��Ͻÿ�

(4)  ���� ����Ʈ�� ����� �� ��忡�� { ��ȭ����, �帣, �����⵵ }�� ���ʷ� ����ϴ� �Լ�
   print_list( ) �� �ۼ��Ͻÿ�


main() �Լ������� : �� ����Ʈ���� �����Ͽ� �Ʒ��� ���� �޴��� �׽�Ʈ�Ͻÿ�.

   - insert_node( )�� ȣ���Ͽ� �����ϴ� ��ȭ�� �����͸� ������ �� ��带 �����,
     ���� ����Ʈ�� �����Ͽ� ����.
    (�� ��, �������� ���������� �����ϵ��� �����ϰų�, �׻� �� ��, �Ǵ� �� �ڿ� �����ϴ�
     ��� �� ������ �� ����)

   - list_length( )�� ȣ���Ͽ�, ���� ����Ʈ�� ����� ����� ������ ���
   - print_list( )�� ȣ���Ͽ� ���� ����Ʈ�� ����� �� ����� �����͸� ���
*/
typedef struct{
    char title[100];
    char genre;
    int year;
}Element;

typedef struct __node{
    Element data;
    struct Node* next;
}Node;

typedef struct{
    Node* head;
    Node* cur;
    Node* tail;
}List;

void InitList(List* plist){
    plist->head = NULL;
    plist->cur = NULL;
    plist->tail = NULL;
}

void Insert(List* plist, Element data){
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = plist->cur;
    plist->cur = new_node;
}

void InsertFront(List* plist, Element data){
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    
    if(plist->tail == NULL){
        plist->tail = new_node;
        new_node->next = new_node;
    }
    else{
        new_node->next = plist->tail->next;
        plist->tail->next = new_node;
    }
}

int main(){

}
/*
    main() �Լ������� : �� ����Ʈ���� �����Ͽ� �Ʒ��� ���� �޴��� �׽�Ʈ�Ͻÿ�.

   - insert_node( )�� ȣ���Ͽ� �����ϴ� ��ȭ�� �����͸� ������ �� ��带 �����,
     ���� ����Ʈ�� �����Ͽ� ����.
    (�� ��, �������� ���������� �����ϵ��� �����ϰų�, �׻� �� ��, �Ǵ� �� �ڿ� �����ϴ�
     ��� �� ������ �� ����)

   - list_length( )�� ȣ���Ͽ�, ���� ����Ʈ�� ����� ����� ������ ���
   - print_list( )�� ȣ���Ͽ� ���� ����Ʈ�� ����� �� ����� �����͸� ���
*/