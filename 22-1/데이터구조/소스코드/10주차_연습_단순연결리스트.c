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
    int numOfData;
}List;
// head에 더미노드가 들어있는 리스트

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
        printf("제목: %-15s\n가수: %-10s\n장르: %-3c\n출시연도: %-5d\n", 
            p->data.title, p->data.player, p->data.genre, p->data.year);
        printf("---------------------------------------------------------\n");
    }
    printf("NULL\n");
}

void PrintCurrentPoint(List* plist){
    for(Node* p = plist->head->next; p != NULL; p = p->next){
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

Node* SearchNode(List* plist){
    char search_title[50];
    printf("찾고자하는 노래 제목을 입력하세요\n");
    scanf("%s", search_title);
    for(Node* p = plist->head; p != NULL; p = p->next){
        if(strcmp(search_title, p->data.title) == 0){
            return p;
        }
    }
    printf("찾고자하는 노래가 없습니다\n");
    return 0;
}

Element DeleteNode(List* plist){
    if(plist->numOfData == 0){
        printf("List가 비어있습니다\n");
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

// plist->cur이 다음을 가리키게 하는 함수
void NextNode(List* plist){
    plist->cur = plist->cur->next;
}

int GetListLength(List* plist){
    return plist->numOfData;
}

List* AddList(List* plist1, List* plist2){
    List* added_list;
    InitList(added_list);
    added_list->head = plist1->head;
    Node* p = added_list->head;
    while(p->next != NULL){
        p = p->next;
    }
    p->next = plist2->head;
    added_list->numOfData = plist1->numOfData + plist2->numOfData;
    return added_list;
}

Node* reverse(Node* head)
{
    Node *p,*q,*r;
 
    p = head;
    q = NULL;
 
    while (p != NULL)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    return q;
}


int main(){
    List* list;
    InitList(list);
    Element data;
    Node* before;
    int temp = 0;
    while (1) {
        printf("1. 프로그램 종료\n2. 입력\n3. 리스트 출력\n4. 리스트 길이 출력\n5. 노래 삭제\n");
        printf("6. 리스트 병합\n7. 리스트 역순\n");
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
