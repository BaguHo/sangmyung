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

typedef int Element;

typedef struct {
    Element data;
    struct Node* next;
}Node;

// 현재 노드의 next에 연결하고 현재 노드를 추가한 노드로 변경한다
Node* InsertNextNode(Node* cur, Element value){ 
    Node* p = (Node*)malloc(sizeof(Node));
    p->data = value;
    p->next = cur->next;
    cur->next = p;
    cur = p;
    return cur;
}
// 다음 노드를 삭제한다
Node* DeleteNode(Node* cur){
    Node* p;
    p = cur->next;
    free(cur->next);
    cur->next = p->next;
    return cur;
}

// 값이 정렬된 리스트에서 오름차순에 맞춰 알아서 삽입하는 함수
Node* InsertSortedList(Node* head, Element data){
       
}

// 특정한 값이 있는 Node를 찾는 함수 
Node* Search(Node* head, Element data){
    for(Node* p = head; p != NULL; p = p->next){
        if(p->data == data){
            return p;
        }
    }
    printf("찾는 값이 없습니다\n");
    return 0;
}

// 2개의 리스트를 연결하는 함수
Node* ConcatList(Node* head1, Node* head2){
    if(head1 == NULL) return head2;
    else{
        Node* p;
        p = head1;
        while(p->next != NULL)
            p = p->next;
        p->next = head2;
        return head1;
    }
}

int main(){
    
}