#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct __element {
    char title[100];
    char player[20];
    char genre;
    int year;
}Element;

typedef struct __node {
    Element data;
    struct Node* next;
}Node;

Node* InsertNode(Node* head, Node* pre, Element data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = pre->next;
    // 포인터 타입 에러
    pre->next = new_node;
    return head;
}

int GetListLength(Node* head) {
    int i = 0;
    // 포인터 타입 에러
    for (Node* p = head; p != NULL; p = p->next) {
        i++;
    }
    return i;
}
void PrintList(Node* head) {
    // 포인터 타입 에러
    for (Node* p = head; p->next != NULL; p = p->next) {
        printf("제목: %s\n가수: %s\n 장르: %c\n발표년도: %d\n",
            head->data.title, head->data.player, head->data.genre, head->data.year);
    }
}

// 특정한 값이 있는 Node를 찾는 함수 
Node* Search(Node* head, Element data) {
    for (Node* p = head; p != NULL; p = p->next) {
        if (strcmp(p->data.title, data.title)) {
            return p;
        }
    }
    printf("찾는 값이 없습니다\n");
    return 0;
}


// 오름차순 정렬
int main() {
    Node* head = (Node*)malloc(sizeof(Node));
    Node* pre = (Node*)malloc(sizeof(Node));
    // 리스트 목록을 보여주고 Next를 통해서 cur를 옮겨 간다
}