#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<windows.h>

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
    int time;
}Element;

typedef struct __node{
    Element data;
    struct __node* next; 
    struct __node* pre; 
}Node;

typedef struct{
    Node* head;
    Node* cur;
    int numOfData;
}List;
// head�� ���̳�尡 ����ִ� ����Ʈ

void InitList(List* plist){
    plist->head = (Node*)malloc(sizeof(Node));
    plist->head->next = plist->head;
    plist->head->pre = plist->head;
    plist->cur = plist->head;
    plist->numOfData = 0;
}

void InsertSortedData(List* plist, Element data){
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;

    Node* p = plist->head;
    while(p != plist->head && strcmp(p->data.title, data.title) <= 0){
        p = p->next;
    }
    new_node->next = p->next;
    new_node->pre = p;
    p->next = new_node;
    new_node->next->pre = new_node;
    plist->cur = new_node;
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
    for(Node* p = plist->head->next; p != plist->head; p = p->next){
        printf("����: %-15s\n����: %-10s\n�帣: %-3c\n��ÿ���: %-5d\n", 
            p->data.title, p->data.player, p->data.genre, p->data.year);
        printf("---------------------------------------------------------\n");
    }
    printf("NULL\n");
}

void PrintLastMusic(List* plist){
    Node* p = plist->head->next;
    Node* lasted_year = p;
    while(p != plist->head){
        if(p->data.year > lasted_year->data.year){
            lasted_year->data.year = p->data.year;
        }
        p = p->next;
    }
    printf("����: %-15s\n����: %-10s\n�帣: %-3c\n��ÿ���: %-5d\n", 
        lasted_year->data.title, lasted_year->data.player, lasted_year->data.genre, lasted_year->data.year);
}

void Play(List* plist){
    printf("���� �������� �뷡: %s\n", plist->cur->data.title);
    int n = plist->cur->data.time;
    int i = 0;
    while(n > 0){
        Sleep(500);
        for(int i = 0; i < n; i++){
            printf(".");
        }
        for(int k = n - i; k < n; k++){
            printf("=");
        }
        printf("\n");
        n--;
    }
}

Node* SearchNode(List* plist){
    char search_title[50];
    printf("ã�����ϴ� �뷡 ������ �Է��ϼ���\n");
    scanf("%s", search_title);
    for(Node* p = plist->head->next; p != plist->head; p = p->next){
        if(strcmp(search_title, p->data.title) == 0){
            return p;
        }
    }
    printf("ã�����ϴ� �뷡�� �����ϴ�\n");
    return NULL;
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

void PreNode(List* plist){
    plist->cur = plist->cur->pre;
}

void GoToFirst(List* plist){
    plist->cur = plist->head->next;
}

void GoToLast(List* plist){
    Node* p = plist->head->next;
    while(p->next != plist->head){
        p = p->next;
    }
    plist->cur = p;
}

int GetListLength(List* plist){
    return plist->numOfData;
}

void PrintGenre(List* plist){
    char temp;
    if(plist->numOfData == 1){
        printf("���ϴ� �帣�� �Է��ϼ���\n");
        scanf("%c", &temp);
        if(plist->cur->data.genre == temp){
            printf("����: %-15s\n����: %-10s\n�帣: %-3c\n��ÿ���: %-5d\n", 
                plist->cur->data.title, plist->cur->data.player, plist->cur->data.genre, plist->cur->data.year);
            printf("---------------------------------------------------------\n");
        }
    }
    scanf("%c", &temp);
    for(Node* p = plist->head->next; p != plist->head; p = p->next){
        if(p->data.genre == temp){
            printf("����: %-15s\n����: %-10s\n�帣: %-3c\n��ÿ���: %-5d\n", 
                p->data.title, p->data.player, p->data.genre, p->data.year);
            printf("---------------------------------------------------------\n");
        }
    }
}

void DeleteList(List* plist){
    for(Node* p = plist->head->next; p != plist->head; p = p->next){
        free(p->pre);
    }
    free(plist);
}

int main(){
    List* list = (List*)malloc(sizeof(List));
    InitList(list);
    Element data;
    Node* before;
    int temp = 0;
    while (1) {
        printf("1. ���α׷� ����\n2. �Է�\n3. ����Ʈ ���\n4. ����Ʈ ���� ���\n5. �뷡 ����\n");
        printf("6. �뷡���\n7. �ֱٿ� ��ǥ�� ����\n8. ���� �帣�� ���� ã��\n");
        scanf("%d", &temp);
        printf("=======================================================================\n");
        switch (temp)
        {
        case 1:
            DeleteList(list);
            return 0;
        case 2:
            printf("�뷡 ����, ����, �帣, ��ÿ����� �Է��ϼ���\n");
            scanf("%s %s %c %d", data.title, data.player, &data.genre, &data.year);
            data.time = rand() % 15;
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
            break;
        case 6:
        {
            Node* p = list->head;
            while(1){
                char order;
                printf("��ɾ �Է����ּ��� >(������), <(������), q(���), 0(���α׷� ����), F, L\n");
                scanf("%c", &order);
                switch(order){
                    case '<':
                        PreNode(list);
                        break;
                    case '>':
                        NextNode(list);
                        break;
                    case '0':
                        DeleteList(list);
                        return 0;
                    case 'F':
                        GoToFirst(list);
                        break;
                    case 'L':
                        GoToLast(list);
                        break;
                    case 'q':
                        Play(list);
                        break;
                }
                printf("=======================================================================\n");
            }
            break;
        }
        case 7:
            PrintLastMusic(list);
            break;
        case 8:
            PrintGenre(list);
            break;
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