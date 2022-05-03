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
    // ������ Ÿ�� ����
    pre->next = new_node;
    return head;
}

int GetListLength(Node* head) {
    int i = 0;
    // ������ Ÿ�� ����
    for (Node* p = head; p != NULL; p = p->next) {
        i++;
    }
    return i;
}
void PrintList(Node* head) {
    // ������ Ÿ�� ����
    for (Node* p = head; p->next != NULL; p = p->next) {
        printf("����: %s\n����: %s\n �帣: %c\n��ǥ�⵵: %d\n",
            head->data.title, head->data.player, head->data.genre, head->data.year);
    }
}

// Ư���� ���� �ִ� Node�� ã�� �Լ� 
Node* Search(Node* head, Element data) {
    for (Node* p = head; p != NULL; p = p->next) {
        if (strcmp(p->data.title, data.title)) {
            return p;
        }
    }
    printf("ã�� ���� �����ϴ�\n");
    return 0;
}


// �������� ����
int main() {
    Node* head = (Node*)malloc(sizeof(Node));
    Node* pre = (Node*)malloc(sizeof(Node));
    // ����Ʈ ����� �����ְ� Next�� ���ؼ� cur�� �Ű� ����
}