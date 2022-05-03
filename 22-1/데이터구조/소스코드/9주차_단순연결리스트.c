#include<stdio.h>
#include<stdlib.h>
#include<string.h>

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
    main() 함수에서는 : 빈 리스트에서 시작하여 아래와 같은 메뉴로 테스트하시오.

   - insert_node( )를 호출하여 좋아하는 영화의 데이터를 저장한 새 노드를 만들고,
     현재 리스트에 삽입하여 연결.
    (이 때, ‘제목’의 오름차순을 유지하도록 연결하거나, 항상 맨 앞, 또는 맨 뒤에 연결하는
     방법 중 선택할 수 있음)

   - list_length( )를 호출하여, 현재 리스트에 연결된 노드의 개수를 계산
   - print_list( )를 호출하여 현재 리스트에 연결된 각 노드의 데이터를 출력
*/