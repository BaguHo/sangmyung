#include<stdio.h>
#include<stdlib.h>
#include<string.h>

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
    Node* top;
    Node* cur;
    int numOfData;
}List;
// top에 더미노드가 들어있는 리스트

void InitList(List* plist){
    plist->top = (Node*)malloc(sizeof(Node));
    plist->top->next = NULL;
    plist->numOfData = 0;
}

void Push(List* plist, Element data){
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;

    Node* p = plist->top;
    new_node->next = plist->top;
    plist->top = new_node;
    plist->numOfData++;
}

void PrintList(List* plist){
    for(Node* p = plist->top->next; p != NULL; p = p->next){
        printf("제목: %-15s\n가수: %-10s\n장르: %-3c\n출시연도: %-5d\n", 
            p->data.title, p->data.player, p->data.genre, p->data.year);
        printf("---------------------------------------------------------\n");
    }
    printf("NULL\n");
}

Node* SearchNode(List* plist){
    char search_title[50];
    printf("찾고자하는 노래 제목을 입력하세요\n");
    scanf("%s", search_title);
    for(Node* p = plist->top; p != NULL; p = p->next){
        if(strcmp(search_title, p->data.title) == 0){
            return p;
        }
    }
    printf("찾고자하는 노래가 없습니다\n");
    return 0;
}

Element Pop(List* plist){
    if(plist->numOfData == 0){
        printf("Stack이 비어있습니다\n");
        exit(1);
    }
    Element remove_data;
    Node* p = plist->top;
    plist->top = plist->top->next;
    remove_data = p->data;
    free(p);
    return remove_data;
}

// plist->cur이 다음을 가리키게 하는 함수
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
        printf("1. 프로그램 종료\n2. 입력\n3. 리스트 출력\n4. 리스트 길이 출력\n5. 노래 삭제\n");
        scanf("%d", &temp);
        printf("=======================================================================\n");
        switch (temp)
        {
        case 1:
            return 0;
            break;
        case 2:
            printf("노래 제목, 가수, 장르, 출시연도를 입력하세요\n");
            scanf("%s %s %c %d", data.title, data.player, &data.genre, &data.year);
            InsertSortedData(list, data);
            break;
        case 3:
            PrintList(list);
            break;
        case 4:
            printf("리스트 길이: %d\n", GetListLength(list));
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
