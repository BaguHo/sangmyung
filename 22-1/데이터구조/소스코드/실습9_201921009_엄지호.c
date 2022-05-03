#define CRT_SECURE_NO_WARNING

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct __element {
    char title[50];
    char player[20];
    char genre;
    int year;
}Element;

typedef struct __node {
    Element data;
    struct __node* next;
}Node;

Node* InsertNode(Node* head) {
    Element data;
    printf("노래 제목, 가수, 장르, 출시연도를 입력하세요\n");
    scanf("%s %s %c %d", data.title, data.player, &data.genre, &data.year);

    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;

    if (head == NULL) {
        new_node->next = head;
        head = new_node;
        return head;
    }
    else {
        Node* p;
        for (p = head; p->next != NULL; p = p->next) {
            if (strcmp(p->next->data.title, data.title) > 0) {
                new_node->next = p->next;
                p->next = new_node;
                return head;
            }
        }
        // 마지막에 삽입
        p->next = new_node;
        new_node->next = NULL;
    }
    return head;
}

int GetListLength(Node* head) {
    int i = 0;
    for (Node* p = head; p != NULL; p = p->next) {
        i++;
    }
    return i;
}

void PrintList(Node* head) {
    for (Node* p = head; p != NULL; p = p->next) {
        printf("제목: %s\n가수: %s\n 장르: %c\n발표년도: %d\n",
            p->data.title, p->data.player, p->data.genre, p->data.year);
    }
    printf("-> NULL\n");
    printf("=============================================================\n");
}

// 특정한 값이 있는 Node를 찾는 함수 
Node* Search(Node* head, Element data) {
    for (Node* p = head; p != NULL; p = p->next) {
        if (strcmp(p->data.title, data.title)) {
            return p;
        }
    }
    printf("찾는 값이 없습니다\n");
    return NULL;
}

int main() {
    Node* head = NULL;

    int temp = 0;
    while (1) {
        printf("1. 프로그램 종료\n2. 입력\n3. 리스트 출력\n4. 리스트 길이\n");
        scanf("%d", &temp);
        if (temp == 1)
            break; 
        else if(temp == 2)
            head = InsertNode(head);
        else if(temp == 3)
            PrintList(head);
        else if(temp == 4)
            printf("리스트 길이: %d\n", GetListLength(head));    
        printf("=======================================================================\n");
    }
}


// BlueberryEyes MAX T 2018
// stay PostMalone B 2019
// dream imaginedragons T 2017
// amsterdam imagindragons T 2017
