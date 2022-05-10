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
    int numOfData;
}List;
// head�� ���̳�尡 ����ִ� ����Ʈ

void InitList(List* plist){
    plist->head = (Node*)malloc(sizeof(Node));
    plist->head->next = NULL;
    plist->numOfData = 0;
}

void InsertSortedData(List* plist, Element data){
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;

    Node* p = plist->head;
    while(p->next != NULL && strcmp(p->next->data.title, data.title) <= 0){
        p = p->next;
    }
    new_node->next = p->next;
    p->next = new_node;
    plist->numOfData++;
}

void InsertNextPoint(List* plist, Element data){
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    
    new_node->next = plist->cur->next;
    plist->cur->next = new_node;
    plist->cur = plist->cur->next;
    plist->numOfData++;
}

void PrintList(List* plist){
    for(Node* p = plist->head->next; p != NULL; p = p->next){
        printf("����: %-15s\n����: %-10s\n�帣: %-3c\n��ÿ���: %-5d\n", 
            p->data.title, p->data.player, p->data.genre, p->data.year);
        printf("---------------------------------------------------------\n");
    }
    printf("NULL\n");
}

void PrintCurrentPoint(List* plist){
    for(Node* p = plist->head->next; p != NULL; p = p->next){
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

Node* SearchNode(List* plist){
    char search_title[50];
    printf("ã�����ϴ� �뷡 ������ �Է��ϼ���\n");
    scanf("%s", search_title);
    for(Node* p = plist->head; p != NULL; p = p->next){
        if(strcmp(search_title, p->data.title) == 0){
            return p;
        }
    }
    printf("ã�����ϴ� �뷡�� �����ϴ�\n");
    return 0;
}

Element DeleteNode(List* plist){
    if(plist->numOfData == 0){
        printf("List�� ����ֽ��ϴ�\n");
        exit(1);
    }
    Node* remove_node = SearchNode(plist);
    Element remove_data = remove_node->data;
    Node* before = plist->head;
    while(before->next != remove_node){
        before = before->next;
    }
    before->next = remove_node->next;
    free(remove_node);
    plist->numOfData--;
    return remove_data;
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
    Element data;
    Node* before;
    int temp = 0;
    while (1) {
        printf("1. ���α׷� ����\n2. �Է�\n3. ����Ʈ ���\n4. ����Ʈ ���� ���\n5. �뷡 ����\n");
        scanf("%d", &temp);
        printf("=======================================================================\n");
        switch (temp)
        {
        case 1:
            return 0;
            break;
        case 2:
            printf("�뷡 ����, ����, �帣, ��ÿ����� �Է��ϼ���\n");
            scanf("%s %s %c %d", data.title, data.player, &data.genre, &data.year);
            InsertSortedData(list, data);
            break;
        case 3:
            PrintList(list);
            break;
        case 4:
            printf("����Ʈ ����: %d\n", GetListLength(list));
            break;
        case 5:
            DeleteNode(list);
        default:
            break;
        }        
        printf("=======================================================================\n");
    }
}

// BlueberryEyes MAX T 2020
// Stay PostMalone B 2018
// Dream imaginedragons T 2015
// Amsterdam imagindragons T 2011
