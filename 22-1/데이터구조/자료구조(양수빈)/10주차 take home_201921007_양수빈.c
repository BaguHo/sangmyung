/*
���Ḯ��Ʈ �ǽ� (�غ�)

(1)  ������ { ���ڿ� ��ȭ����, ���� �帣, ���� �����⵵ }�� �����ϴ� ���Ḯ��Ʈ �����
   �ڷᱸ�� �����Ͻÿ� (���⼭ �帣�� ��A��, ��C��, ��F��, ��R�� �� �ϳ�)

(2)  �� ��带 ���� ����Ʈ�� Ư�� ��ġ�� �����ϴ� �Լ� insert_node( ) �ۼ��Ͻÿ�
   (������ ����ó�� insert_first( )�� Ư�� ��ġ�� �����ؼ� �����ϴ� insert( )�� ���� �ۼ��� �� ����)

(3)  ���� ����Ʈ�� ����� ����� ������ ����ؼ� ��ȯ�ϴ� �Լ� list_length( ) �� �ۼ��Ͻÿ�

(4)  ���� ����Ʈ�� ����� �� ��忡�� { ��ȭ����, �帣, �����⵵ }�� ���ʷ� ����ϴ� �Լ�
   print_list( ) �� �ۼ��Ͻÿ�


main() �Լ������� : �� ����Ʈ���� �����Ͽ� �Ʒ��� ���� �޴��� �׽�Ʈ�Ͻÿ�.

   - insert_node( )�� ȣ���Ͽ� �����ϴ� ��ȭ�� �����͸� ������ �� ��带 �����,
     ���� ����Ʈ�� �����Ͽ� ����.
    (�� ��, �������� ���������� �����ϵ��� �����ϰų�, �׻� �� ��, �Ǵ� �� �ڿ� �����ϴ�
     ��� �� ������ �� ����)

   - list_length( )�� ȣ���Ͽ�, ���� ����Ʈ�� ����� ����� ������ ���
   - print_list( )�� ȣ���Ͽ� ���� ����Ʈ�� ����� �� ����� �����͸� ���
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#define ARRAY 100 
//��� Ÿ��
typedef struct Element {
    char title[ARRAY];
    char genre;
    int year;
}Element;

typedef struct ListNode {
    Element data;
    struct ListNode* link;
}ListNode;

//���� ����Ʈ ���
typedef struct ListType {
    int size;
    ListNode* head;
    ListNode* tail;
}ListType;

//���� �Լ�
void error(char* message) {
    fprintf(stderr, "%s\n", message);
    exit(1);
}

//����Ʈ ��� ���� �Լ�
ListType* create() {
    ListType* plist = (ListType*)malloc(sizeof(ListType));
    plist->size = 0;
    plist->head = plist->tail = NULL;
    return plist;
}

//����Ʈ �Լ�
void print_list(ListType* plist) {

    ListNode* a = plist->head;
    for (; a != NULL; a = a->link) {
        printf("{%s %c %d}->", a->data.title, a->data.genre, a->data.year);
    }
    printf("NULL\n");
}


//���� ��� �Լ�
int list_length(ListType* plist) {
    return plist->size;
}

//plist�� ���� ����Ʈ�� ����� ����Ű�� ������
void insert_node(ListType* plist, int choice) {
    ListNode* p = (ListNode*)malloc(sizeof(ListNode));
    p->link = NULL;
    printf("������ ��ȭ����, ��ȭ�帣, �����⵵ �� �Է��ϼ���: ");
    scanf("%s %c %d", p->data.title, &p->data.genre, &p->data.year);

    ListNode* a = plist->head;

    switch (choice) {
    case 1://���� �տ� ��� ����
        p->link = plist->head;
        plist->head = p;
        plist->size++;
        break;
    case 2://���� �ڿ� ��� ����
        p->link = NULL;//�ʱ�ȭ
        if (plist->tail == NULL) {//������� ��
            plist->head = plist->tail = p;
        }
        else {
            plist->tail->link = p;
            plist->tail = p;
        }
        plist->size++;
        break;
    case 3://�������� ��� ����
        if (plist->tail == NULL) {//ù ��° �ִ� ���
            plist->head = plist->tail = p;
            plist->size++;
        }

        else if (strcmp(plist->head->data.title, p->data.title) == 1)//���Ḯ��Ʈ �Ӹ� > p
        {
            p->link = plist->head;
            plist->head = p;
            plist->size++;
        }

        else if (strcmp(plist->tail->data.title, p->data.title) == -1)//���Ḯ��Ʈ ���� < p
        {
            plist->tail->link = p;
            plist->tail = p;
            plist->size++;
        }

        else {//�߰��� ���Ḯ��Ʈ ���̱�
            while (a->link != NULL) {
                if (strcmp(p->data.title, a->link->data.title) == -1) {
                    p->link = a->link;
                    a->link = p;
                    //p->link = NULL; a�ڿ� ���� ���� ���� �� Ȯ���� 
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
    printf("�� ���� ��ȭ�� �Է��ϳ���?: ");
    scanf("%d", &movie);

    printf("���ο� ������ ���� ���\n");
    printf("1. ���� �� 2. ���� �� 3. ��������: ");
    scanf("%d", &choice);

    ListType* list1;
    list1 = create();

    for (int i = 0; i < movie; i++) {
        insert_node(list1, choice);
    }

    print_list(list1);

    num = list_length(list1);
    printf("���� ����� ����� ����: %d\n", num);

    free(list1);
    return 0;
}