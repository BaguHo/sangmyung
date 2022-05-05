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

typedef struct __element {
    char title[50];
    char player[20];
    char genre;
    int year;
}Element;

typedef struct __node{
    Element data;
    struct __node* next; 
}Node;

typedef struct{
    Node* head;
    Node* cur;
    Node* tail;
    int numOfData;
}List;

void InitList(List* plist){
    plist->head = NULL;
    plist->cur = NULL;
    plist->tail = NULL;
    plist->numOfData = 0;
}

void InsertSortedData(List* plist, Element data){
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;

    if (plist->head == NULL) {
        new_node->next = plist->head;
        plist->head = new_node;
        plist->numOfData++;
    }
    else {
        Node* p;
        for (p = plist->head; p->next != NULL; p = p->next) {
            // head�� �����ϴ� ���
            if(strcmp(plist->head->data.title, data.title) < 0){
                new_node->next = plist->head;
                plist->head = new_node;
                break;
            }
            if (strcmp(p->next->data.title, data.title) < 0) {
                new_node->next = p->next;
                p->next = new_node;
                break;
            }
        }
        if(p->next == NULL){
            p->next = new_node;
            new_node->next = NULL;
            plist->numOfData++;
        }
    }
}

void InsertData(List* plist, Element data){
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    if(plist->numOfData == 0){
        plist->head = new_node;
        plist->cur = new_node;
        plist->tail = new_node;
    }
    else{
        new_node->next = plist->cur->next;
        plist->cur->next = new_node;
        plist->tail = plist->cur->next;        
    }
    plist->numOfData++;
}


void PrintList(List* plist){
    for(Node* p = plist->head; p != NULL; p = p->next){
        printf("����: %-15s\n����: %-10s\n�帣: %-3c\n��ÿ���: %-5d\n", 
            p->data.title, p->data.player, p->data.genre, p->data.year);
        printf("---------------------------------------------------------\n");
    }
    printf("NULL\n");
}

void PrintCurrentPoint(List* plist){
    for(Node* p = plist->head; p != NULL; p = p->next){
        if(p == plist->cur){
            printf("==================���� ���====================\n");
            printf("����: %s\n����: %s\n�帣: %c\n��ÿ���: %d\n", 
                p->data.title, p->data.player, p->data.genre, p->data.year);
        }
        else{
            printf("����: %s\n����: %s\n�帣: %c\n��ÿ���: %d\n", 
                p->data.title, p->data.player, p->data.genre, p->data.year);
        }
    }    
    printf("NULL\n");
}

Node* DeleteNextNode(List* plist){
    if(plist->numOfData == 0){
        printf("List�� ����ֽ��ϴ�\n");
        return 0;
    }
    Node* remove_node;
    remove_node = plist->cur->next;
    plist->cur->next = plist->cur->next->next;
    plist->numOfData--;
    return remove_node;
}

// plist->cur�� ������ ����Ű�� �ϴ� �Լ�
void NextNode(List* plist){
    plist->cur = plist->cur->next;
}

int GetListLength(List* plist){
    return plist->numOfData;
}

int main(){
    List* list;
    InitList(list);
    int temp = 0;
    while (1) {
        printf("1. ���α׷� ����\n2. �Է�\n3. ����Ʈ ���\n4. ����Ʈ ����\n");
        scanf("%d", &temp);
        printf("=======================================================================\n");
        if (temp == 1)
            break; 
        else if(temp == 2){
            Element data;
            printf("�뷡 ����, ����, �帣, ��ÿ����� �Է��ϼ���\n");
            scanf("%s %s %c %d", data.title, data.player, &data.genre, &data.year);
            InsertSortedData(list, data);
        }
        else if(temp == 3)
            PrintList(list);
        else if(temp == 4)
            printf("����Ʈ ����: %d\n", GetListLength(list));    
        printf("=======================================================================\n");
    }
}

// BlueberryEyes MAX T 2020
// Stay PostMalone B 2018
// Dream imaginedragons T 2015
// Amsterdam imagindragons T 2011
