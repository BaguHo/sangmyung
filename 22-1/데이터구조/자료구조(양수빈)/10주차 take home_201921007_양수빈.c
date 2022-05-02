/*
연결리스트 실습 (준비)

(1)  데이터 { 문자열 영화제목, 문자 장르, 정수 개봉년도 }를 저장하는 연결리스트 노드의
   자료구조 정의하시오 (여기서 장르는 ‘A’, ‘C’, ‘F’, ‘R’ 중 하나)

(2)  새 노드를 현재 리스트의 특정 위치에 삽입하는 함수 insert_node( ) 작성하시오
   (교재의 예제처럼 insert_first( )와 특정 위치를 지정해서 삽입하는 insert( )를 따로 작성할 수 있음)

(3)  현재 리스트에 연결된 노드의 개수를 계산해서 반환하는 함수 list_length( ) 를 작성하시오

(4)  현재 리스트에 연결된 각 노드에서 { 영화제목, 장르, 개봉년도 }를 차례로 출력하는 함수
   print_list( ) 를 작성하시오


main() 함수에서는 : 빈 리스트에서 시작하여 아래와 같은 메뉴로 테스트하시오.

   - insert_node( )를 호출하여 좋아하는 영화의 데이터를 저장한 새 노드를 만들고,
     현재 리스트에 삽입하여 연결.
    (이 때, ‘제목’의 오름차순을 유지하도록 연결하거나, 항상 맨 앞, 또는 맨 뒤에 연결하는
     방법 중 선택할 수 있음)

   - list_length( )를 호출하여, 현재 리스트에 연결된 노드의 개수를 계산
   - print_list( )를 호출하여 현재 리스트에 연결된 각 노드의 데이터를 출력
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#define ARRAY 100 
//노드 타입
typedef struct Element {
    char title[ARRAY];
    char genre;
    int year;
}Element;

typedef struct ListNode {
    Element data;
    struct ListNode* link;
}ListNode;

//연결 리스트 헤더
typedef struct ListType {
    int size;
    ListNode* head;
    ListNode* tail;
}ListType;

//오류 함수
void error(char* message) {
    fprintf(stderr, "%s\n", message);
    exit(1);
}

//리스트 헤더 생성 함수
ListType* create() {
    ListType* plist = (ListType*)malloc(sizeof(ListType));
    plist->size = 0;
    plist->head = plist->tail = NULL;
    return plist;
}

//프린트 함수
void print_list(ListType* plist) {

    ListNode* a = plist->head;
    for (; a != NULL; a = a->link) {
        printf("{%s %c %d}->", a->data.title, a->data.genre, a->data.year);
    }
    printf("NULL\n");
}


//길이 계산 함수
int list_length(ListType* plist) {
    return plist->size;
}

//plist는 연결 리스트의 헤더를 가리키는 포인터
void insert_node(ListType* plist, int choice) {
    ListNode* p = (ListNode*)malloc(sizeof(ListNode));
    p->link = NULL;
    printf("저장할 영화제목, 영화장르, 개봉년도 를 입력하세요: ");
    scanf("%s %c %d", p->data.title, &p->data.genre, &p->data.year);

    ListNode* a = plist->head;

    switch (choice) {
    case 1://제일 앞에 노드 연결
        p->link = plist->head;
        plist->head = p;
        plist->size++;
        break;
    case 2://제일 뒤에 노드 연결
        p->link = NULL;//초기화
        if (plist->tail == NULL) {//빈공간일 때
            plist->head = plist->tail = p;
        }
        else {
            plist->tail->link = p;
            plist->tail = p;
        }
        plist->size++;
        break;
    case 3://오름차순 노드 연결
        if (plist->tail == NULL) {//첫 번째 넣는 경우
            plist->head = plist->tail = p;
            plist->size++;
        }

        else if (strcmp(plist->head->data.title, p->data.title) == 1)//연결리스트 머리 > p
        {
            p->link = plist->head;
            plist->head = p;
            plist->size++;
        }

        else if (strcmp(plist->tail->data.title, p->data.title) == -1)//연결리스트 꼬리 < p
        {
            plist->tail->link = p;
            plist->tail = p;
            plist->size++;
        }

        else {//중간에 연결리스트 붙이기
            while (a->link != NULL) {
                if (strcmp(p->data.title, a->link->data.title) == -1) {
                    p->link = a->link;
                    a->link = p;
                    //p->link = NULL; a뒤에 값이 뭐가 들어가는 건 확실해 
                    plist->size++;
                    break;
                }
                a = a->link;
            }
        }
        break;
    }
}

int main(void) {
    int movie;
    int num;
    int choice;
    printf("몇 개의 영화를 입력하나요?: ");
    scanf("%d", &movie);

    printf("새로운 데이터 정렬 방법\n");
    printf("1. 제일 앞 2. 제일 뒤 3. 오름차순: ");
    scanf("%d", &choice);

    ListType* list1;
    list1 = create();

    for (int i = 0; i < movie; i++) {
        insert_node(list1, choice);
    }

    print_list(list1);

    num = list_length(list1);
    printf("현재 연결된 노드의 개수: %d\n", num);

    free(list1);
    return 0;
}