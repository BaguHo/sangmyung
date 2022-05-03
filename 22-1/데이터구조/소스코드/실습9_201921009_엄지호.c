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
    printf("�뷡 ����, ����, �帣, ��ÿ����� �Է��ϼ���\n");
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
        // �������� ����
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
        printf("����: %s\n����: %s\n �帣: %c\n��ǥ�⵵: %d\n",
            p->data.title, p->data.player, p->data.genre, p->data.year);
    }
    printf("-> NULL\n");
    printf("=============================================================\n");
}

// Ư���� ���� �ִ� Node�� ã�� �Լ� 
Node* Search(Node* head, Element data) {
    for (Node* p = head; p != NULL; p = p->next) {
        if (strcmp(p->data.title, data.title)) {
            return p;
        }
    }
    printf("ã�� ���� �����ϴ�\n");
    return NULL;
}

int main() {
    Node* head = NULL;

    int temp = 0;
    while (1) {
        printf("1. ���α׷� ����\n2. �Է�\n3. ����Ʈ ���\n4. ����Ʈ ����\n");
        scanf("%d", &temp);
        if (temp == 1)
            break; 
        else if(temp == 2)
            head = InsertNode(head);
        else if(temp == 3)
            PrintList(head);
        else if(temp == 4)
            printf("����Ʈ ����: %d\n", GetListLength(head));    
        printf("=======================================================================\n");
    }
}


// BlueberryEyes MAX T 2018
// stay PostMalone B 2019
// dream imaginedragons T 2017
// amsterdam imagindragons T 2017
