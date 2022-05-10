#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<windows.h>

typedef struct __element {
    char title[50];
    char player[20];
    char genre;
    int year;
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

    Node* p = plist->head->next;
    while(p != plist->head && strcmp(p->next->data.title, data.title) <= 0){
        p = p->next;
    }
    new_node->next = p->next;
    new_node->pre = p;
    p->next = new_node;
    new_node->next->pre = new_node;
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

Element RemoveNode(List* plist){
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
    remove_node->next->pre = before;
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

int GetListLength(List* plist){
    return plist->numOfData;
}

void GoToFirst(List* plist){
    plist->cur = plist->head;
}

void GoToLast(List* plist){
    Node* p = plist->head;
    while(p->next != NULL){
        p = p->next;
    }
    plist->cur = p;
}

void PrintGenre(List* plist){
    char temp;
    printf("���ϴ� �帣�� �Է��ϼ���\n");
    scanf("%c", &temp);
    for(Node* p = plist->head; p->next != NULL; p = p->next){
        if(p->data.genre == temp){
            printf("����: %-15s\n����: %-10s\n�帣: %-3c\n��ÿ���: %-5d\n", 
                p->data.title, p->data.player, p->data.genre, p->data.year);
            printf("---------------------------------------------------------\n");
        }
    }
}

void PrintLastMusic(List* plist){
    Node* p = plist->head->next;
    while(p != plist->head){
        p = p->next;
    }
    printf("����: %-15s\n����: %-10s\n�帣: %-3c\n��ÿ���: %-5d\n", 
        p->data.title, p->data.player, p->data.genre, p->data.year);
}

void Play(){
    int n = 10;
    while(n > 0){
        Sleep(1000);
        int i;
        for(i = 0; i < 10; i++){
            printf(".");
        }
        for(int k = 10 - i; k < 10; k++){
            printf("=");
        }
        printf("\n");
        n--;
    }
}

int main(){
    List* list;
    InitList(list);
    Element data;
    Node* before;
    Node* p;
    int temp = 0;
    char play;
    while (1) {
        printf("1. ���α׷� ����\n2. �Է�\n3. ����Ʈ ���\n4. ����Ʈ ���� ���\n5. �뷡 ����\n6. �帣���\n");
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
            RemoveNode(list);
            break;
        case 6:
            // ������α׷�
            while(1){
                if(list->head == NULL){
                printf("����: %-15s\n����: %-10s\n�帣: %-3c\n��ÿ���: %-5d\n", 
                    p->data.title, p->data.player, p->data.genre, p->data.year);
                printf("����: %-15s\n����: %-10s\n�帣: %-3c\n��ÿ���: %-5d\n", 
                    p->next->data.title, p->next->data.player, p->next->data.genre, p->next->data.year);
                }
                else{
                    printf("����: %-15s\n����: %-10s\n�帣: %-3c\n��ÿ���: %-5d\n", 
                        p->pre->data.title, p->pre->data.player, p->pre->data.genre, p->pre->data.year);
                    printf("����: %-15s\n����: %-10s\n�帣: %-3c\n��ÿ���: %-5d\n", 
                        p->data.title, p->data.player, p->data.genre, p->data.year);
                    printf("����: %-15s\n����: %-10s\n�帣: %-3c\n��ÿ���: %-5d\n", 
                        p->next->data.title, p->next->data.player, p->next->data.genre, p->next->data.year);
                }
                printf("��ɾ �Է��ϼ��� <, >, q, F/f, L/l, 0(�������)\n");
                scanf("%c", &play);
                switch (play)
                {
                case '<':
                    if(p == NULL){
                        return 0;
                    }
                    PreNode(list);
                    break;
                case '>':
                    if(p->next == NULL){
                        return 0;
                    }
                    NextNode(list);
                    break;
                case 'q':
                    printf("���� ������� ��: %s\n", p->data.title);
                    Play();
                    NextNode(list);
                    break;
                case '0':
                    printf("����� �����մϴ�\n");
                    return 0;
                case 'L': case 'l':
                    GoToLast(list);
                    break;
                case 'F': case 'f':
                    GoToFirst(list);
                    break;
                }
            }
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
