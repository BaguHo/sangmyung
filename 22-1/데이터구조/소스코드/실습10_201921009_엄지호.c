#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<windows.h>

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
// head에 더미노드가 들어있는 리스트

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
        printf("제목: %-15s\n가수: %-10s\n장르: %-3c\n출시연도: %-5d\n", 
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
    printf("제목: %-15s\n가수: %-10s\n장르: %-3c\n출시연도: %-5d\n", 
        lasted_year->data.title, lasted_year->data.player, lasted_year->data.genre, lasted_year->data.year);
}

void Play(List* plist){
    printf("현재 실행중인 노래: %s\n", plist->cur->data.title);
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
    printf("찾고자하는 노래 제목을 입력하세요\n");
    scanf("%s", search_title);
    for(Node* p = plist->head->next; p != plist->head; p = p->next){
        if(strcmp(search_title, p->data.title) == 0){
            return p;
        }
    }
    printf("찾고자하는 노래가 없습니다\n");
    return NULL;
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
        printf("원하는 장르를 입력하세요\n");
        scanf("%c", &temp);
        if(plist->cur->data.genre == temp){
            printf("제목: %-15s\n가수: %-10s\n장르: %-3c\n출시연도: %-5d\n", 
                plist->cur->data.title, plist->cur->data.player, plist->cur->data.genre, plist->cur->data.year);
            printf("---------------------------------------------------------\n");
        }
    }
    scanf("%c", &temp);
    for(Node* p = plist->head->next; p != plist->head; p = p->next){
        if(p->data.genre == temp){
            printf("제목: %-15s\n가수: %-10s\n장르: %-3c\n출시연도: %-5d\n", 
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
        printf("1. 프로그램 종료\n2. 입력\n3. 리스트 출력\n4. 리스트 길이 출력\n5. 노래 삭제\n");
        printf("6. 노래재생\n7. 최근에 발표된 음악\n8. 같은 장르의 음악 찾기\n");
        scanf("%d", &temp);
        printf("=======================================================================\n");
        switch (temp)
        {
        case 1:
            DeleteList(list);
            return 0;
        case 2:
            printf("노래 제목, 가수, 장르, 출시연도를 입력하세요\n");
            scanf("%s %s %c %d", data.title, data.player, &data.genre, &data.year);
            data.time = rand() % 15;
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
            break;
        case 6:
        {
            Node* p = list->head;
            while(1){
                char order;
                printf("명령어를 입력해주세요 >(다음곡), <(이전곡), q(재생), 0(프로그램 종료), F, L\n");
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