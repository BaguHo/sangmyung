#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// 연결 리스트 만들기
// 삽입 연산 head, 중간, 마지막 위치에 삽입하는 함수
// 저 위에 기능을 다 할 수 있는 하나의 함수 -> cur를 통한 데이터 선택 및 삭제

// 삭제연산도 마찬가지
// head가 하나도 없을 때를 언제나 생각해야 한다

// 정렬되어 있는 단순연결리스트에서 값을 정렬해서 넣는 방법

// 방문코드(처음부터 끝까지 스캔)
// Count, Node* SearchValue(Node *head, Element x) 등등의 기능
// 삽입, 삭제를 cur로 할까 아니면 value로 해야할까?
// 두 개의 리스트를 합하는 함수
// 1. 2개 다 NULL
// 2. 둘 중 하나만 NULL
// 3. 모두 다 NULL이 아님
// 단순 연결 리스트에서 화살표 방향을 바꾸는 함수(역순으로, head도 바꿔줘야 함)

// 연결리스트로 다항식 나타내기

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
            // head에 들어가야하는 경우
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
        printf("제목: %-15s\n가수: %-10s\n장르: %-3c\n출시연도: %-5d\n", 
            p->data.title, p->data.player, p->data.genre, p->data.year);
        printf("---------------------------------------------------------\n");
    }
    printf("NULL\n");
}

void PrintCurrentPoint(List* plist){
    for(Node* p = plist->head; p != NULL; p = p->next){
        if(p == plist->cur){
            printf("==================현재 노드====================\n");
            printf("제목: %s\n가수: %s\n장르: %c\n출시연도: %d\n", 
                p->data.title, p->data.player, p->data.genre, p->data.year);
        }
        else{
            printf("제목: %s\n가수: %s\n장르: %c\n출시연도: %d\n", 
                p->data.title, p->data.player, p->data.genre, p->data.year);
        }
    }    
    printf("NULL\n");
}

Node* DeleteNextNode(List* plist){
    if(plist->numOfData == 0){
        printf("List가 비어있습니다\n");
        return 0;
    }
    Node* remove_node;
    remove_node = plist->cur->next;
    plist->cur->next = plist->cur->next->next;
    plist->numOfData--;
    return remove_node;
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
    int temp = 0;
    while (1) {
        printf("1. 프로그램 종료\n2. 입력\n3. 리스트 출력\n4. 리스트 길이\n");
        scanf("%d", &temp);
        printf("=======================================================================\n");
        if (temp == 1)
            break; 
        else if(temp == 2){
            Element data;
            printf("노래 제목, 가수, 장르, 출시연도를 입력하세요\n");
            scanf("%s %s %c %d", data.title, data.player, &data.genre, &data.year);
            InsertSortedData(list, data);
        }
        else if(temp == 3)
            PrintList(list);
        else if(temp == 4)
            printf("리스트 길이: %d\n", GetListLength(list));    
        printf("=======================================================================\n");
    }
}

// BlueberryEyes MAX T 2020
// Stay PostMalone B 2018
// Dream imaginedragons T 2015
// Amsterdam imagindragons T 2011
