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
 //////////////////////////////////////////////////////////////////////////////////////
   ���Ḯ��Ʈ �ǽ� (5/25)

��(1) ���ο� ��ȭ�� ���� ��带 �����ϴ� �Լ� (�غ�Ϸ�)

��(2) ��� ��忡 ����� ��ȭ������ ���ʷ� ��� (�غ� �Ϻ� �Ϸ�)

��   ��ȯȣ���� �̿��ؼ�, ���ʷ� ����ϴ� �Լ� print_list_2 ( )�� �ۼ��Ͻÿ�

��  ��ȯȣ���� �̿��ؼ�, �������� ����ϴ� �Լ� print_list_3 ( ) �� �ۼ��Ͻÿ�.

��(3) ���� ����Ʈ�� ����� ��ȭ���� ����� ������ ��� (�غ� �Ϻ� �Ϸ�)

��            ��ȯȣ���� �̿��ؼ� list_length_2 ( ) �� �ٽ� �ۼ��Ͻÿ�.

��(4)  ��ȭ�������� �ڷ� �˻��ϴ� �Լ� :
    ����Ʈ���� ã���� �ش� ��带 ��ȯ�ϰ�, ����Ʈ�� �������� ������ NULL ��ȯ

��(5)  Ư�� ��ȭ�� ���� ��带 �����ϴ� �Լ�.

��(6)  ���� �ֱٿ� ������ ��ȭ �˻��ϴ� �Լ�.

��------(7)  ���ϴ� �帣�� ��ȭ�鸸 ����ϴ� �Լ�:
     �Լ��� �Ű����� �� �ϳ��� ��A��, ��C��, ��F��, ��R�� ���� ���� ������ ����,




main() �Լ��� �Ʒ��� �Ʒ��� ���� �޴� �� �����ϸ鼭 �ݺ� �����ϸ�, ���� �� ��ġ���� �Ѵ�.

-  ���ο� ��ȭ�� ���� ��带 ����� ���ϴ� ��ġ�� ����
-  ���� ����Ʈ�� ����� ��� ����� ��ȭ������ ���
    : ����� ������ �������� ����ϵ��� ���� ����.
-  ���� ����Ʈ�� ��� ������ ����ؼ� ���
-  ��ȭ �������� Ư�� ��ȭ�� �˻��ؼ� ����� ������ ���
-  ��ȭ �������� �˻��ؼ� �ش� ��带 ����
-  ���� �ֱٿ� ������ ��ȭ�� ã�Ƽ� �� ����� ������ ���
-  Ư�� �帣�� ��ȭ���� ��� �� ����� ������ ���
*/
/*
   ���߿��Ḯ��Ʈ ���α׷���
   ��ȭ���� ���α׷��� �ܼ����Ḯ��Ʈ���� ���߿��Ḯ��Ʈ�� �����Ͽ� �����Ͻÿ�.
   (��1) �������ʵ忡 ����ð�(1~10��)�� ����Ÿ������ �߰��ȴ�.
   (��2) ���� 230-231�ʿ� ���õ� ����带 ���´�.

   ����޴����� ������ ���� ����� ���� �Ǵ� �߰��ȴ�.

   (1) ����, ����, �˻�, ��� ��� ���� ���߿��Ḯ��Ʈ�� �µ��� �����Ѵ�.
   (2) ����޴� 'P'�� �߰��Ѵ�:
       - ȣ���Լ��� ���� ����� ����ð���ŭ ����Ѵ�(����ð��� 0�� �� ������ ����)
         �ð��� ȿ���� ���� progressive bar(��..........) ��� ����
       - ����� �Ϸ�Ǹ� �ڵ����� ���� ���� �̵��Ѵ�.
   (3) ���� ����� ���� ���� �̵��ؼ� ����ϴ� '>'�� �߰��Ѵ�.
   (4) ���� ����� ���� ���� �̵��ؼ� ����ϴ� '<'�� �߰��Ѵ�.
   (5) �� ���� ��ȭ�� �̵��ؼ� ����ϴ� 'F/f'�� �߰��Ѵ�.
   (6) �� ���� ��ȭ�� �̵��ؼ� ����ϴ� 'L/l'�� �߰��Ѵ�.
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<windows.h>

#define ARRAY 100 
//��� Ÿ��
typedef struct Element {
    char title[ARRAY];
    char genre;
    int year;
    int time;
}Element;

typedef struct DListNode {
    Element data;
    struct DListNode* llink;
    struct DListNode* rlink;
}DListNode;

DListNode* current;

//���� �Լ�
void error(char* message) {
    fprintf(stderr, "%s\n", message);
    exit(1);
}

//���� ���� ����Ʈ�� �ʱ�ȭ �Լ�
void init(DListNode* phead) {
    phead->llink = phead;
    phead->rlink = phead;
}

//���� ���� ����Ʈ�� ����Ʈ �Լ�
void print_dlist(DListNode* phead) {
    DListNode* p;
    for (p = phead->rlink; p != phead; p = p->rlink) {
        if (current == p) {
            printf("*{%s %c %d %d��}*\n", p->data.title, p->data.genre, p->data.year, p->data.time);
            p = p->rlink;
            if (p == phead) {//p�� head�� �ð�� �� if���� �ɾ����� ������ ���� 128��° ���� ����Ǹ鼭 �����Ⱚ�� ��µȴ�.
                return;
            }
        }
        printf("-{%s %c %d %d��}-\n", p->data.title, p->data.genre, p->data.year,p->data.time);
    }
    printf("\n");
}

//���� ��� �Լ�
int list_length(DListNode* phead) {
    int num = 0;
    DListNode* p;
    for (p = phead->rlink; p != phead; p = p->rlink) {
        num++;
    }
    return num;
}

//��ȭ ã�� �Լ�
void find_movie(DListNode* phead) {
    char name[ARRAY] = { NULL };// [ARRAY] ;//��ȭ���� �ڷḦ �˻����� ���ڿ�
    printf("��ȭ �����Է�: ");
    scanf("%s", name);


    DListNode* search = phead->rlink;

    printf("\n");

    if (search == NULL)
        return 0;
    while (search != phead) {
        if (strcmp(search->data.title, name) != 0) {
            search = search->rlink;
        }
        else if (strcmp(search->data.title, name) == 0) {
            printf("�˻� ���: {%s %c %d %d��}\n", search->data.title, search->data.genre, search->data.year, search->data.time);
            break;
        }
        else
            return NULL;
    }
}

//�Է¹��� �帣�� ���� ��ȭ ��� �Լ�
void find_genre(DListNode* phead) {
    char genre_name;//���ϴ� �帣�� �˻����� ����
    printf("��ȭ �帣�Է�('A','C','F','R' �� �ϳ�): ");
    getchar();
    scanf("%c", &genre_name);
    DListNode* search = phead->rlink;

    printf("\n");

    if (search == NULL)
        return 0;
    while (search != phead) {
        if (search->data.genre == genre_name) {
            printf("{%s %c %d %d��}\n", search->data.title, search->data.genre, search->data.year, search->data.time);
        }
        search = search->rlink;
    }
}

//���� �ֱٿ� ������ ��ȭ�� ã�� �Լ�
void find_current(DListNode* phead) {
    int curyear;
    DListNode* search = phead->rlink;

    if (search == NULL)
        return 0;

    curyear = search->data.year;//curyear=����Ʈ�� ù ��° year
    for (; search != phead; search = search->rlink) {
        if (curyear <= search->data.year) {//curyear���� ����Ʈ�� year�� �� ũ�� �� ����
            curyear = search->data.year;
        }
    }
    
    search = phead->rlink;

    for (; search != phead; search = search->rlink) {
        if (curyear == search->data.year) {//curyear�� ����Ʈ�� year�� ������ ���
            printf("\n{%s %c %d %d��}     ", search->data.title, search->data.genre, search->data.year, search->data.time);
        }
    }
    printf("\n");
}

//plist�� ���� ����Ʈ�� ����� ����Ű�� ������
void insert_node(DListNode* phead, int choice1) {
    DListNode* newnode = (DListNode*)malloc(sizeof(DListNode));
    printf("������ ��ȭ����, ��ȭ�帣('A','C','F','R' �� �ϳ�), �����⵵, ����ð��� �Է��ϼ���: ");
    scanf("%s %c %d %d", newnode->data.title, &newnode->data.genre, &newnode->data.year, &newnode->data.time);


    DListNode* p = phead;

    switch (choice1) {
    case 1://���� �տ� ��� ����
        newnode->llink = p;//1
        newnode->rlink = p->rlink;//2
        p->rlink->llink = newnode;//3
        p->rlink = newnode;//4
        break;
    case 2://���� �ڿ� ��� ����
        newnode->rlink = p;//1
        newnode->llink = p->llink->rlink;//2
        p->llink->rlink = newnode;//3
        p->llink = newnode;//4
        break;
    case 3://�������� ��� ����
        if(strcmp(p->rlink->data.title, newnode->data.title) == 1)//���Ḯ��Ʈ ������ġ �� > newnode
        {
            newnode->llink = p;//1
            newnode->rlink = p->rlink;//2
            p->rlink->llink = newnode;//3
            p->rlink = newnode;//4
        }

        else if (strcmp(p->llink->data.title, newnode->data.title) == -1)//���Ḯ��Ʈ �ǵ� < newnode
        {
            newnode->rlink = p;//1
            newnode->llink = p->llink->rlink;//2
            p->llink->rlink = newnode;//3
            p->llink = newnode;//4
        }

        else {//�߰��� ���Ḯ��Ʈ ���̱�
            do {
                if (strcmp(newnode->data.title, p->rlink->data.title) == -1 && strcmp(newnode->data.title, p->data.title) == 1) { //���Ḯ��Ʈ ������ġ �� > newnode && ���Ḯ��Ʈ ������ġ < newnode
                    newnode->llink = p;//1
                    newnode->rlink = p->rlink;//2
                    p->rlink->llink = newnode;//3
                    p->rlink = newnode;//4
                    break;
                }
                p = p->rlink;
            } while (p != phead);
        }
        break;
    }
}

//���� �Լ�
void delete_node(DListNode* phead) {
    char delete_name[ARRAY];//������ ��ȭ�� �Է¹��� ����
    printf("������ ��ȭ�� �̸��� �Է��ϼ���: ");
    scanf("%s", delete_name);
    DListNode* removed = phead;

    //��尡 �ϳ��ۿ� ���� �� ����(���������)
    if (strcmp(removed->rlink->data.title, delete_name) == 0) {
        phead = phead->llink->rlink = phead->rlink->llink;
        free(removed);//����
        return;
    }

    removed = removed->rlink;

    do {
        if (strcmp(removed->data.title, delete_name) == 0) {
            removed->llink->rlink = removed->rlink;
            removed->rlink->llink = removed->llink;
            free(removed);
            return;
            break;
        }
            removed = removed->rlink;
    }while (removed != phead);

    printf("������ ��尡 �����ϴ�.");
    return;
}

void menu() {
    printf("\n<==================�޴�===================>\n");
    printf("1.����\n");
    printf("2.���\n");
    printf("3.����� ���� ���\n");
    printf("4.��ȭ �˻�\n");
    printf("5.��� ����\n");
    printf("6.���� �ֱٿ� ������ ��ȭ �˻�\n");
    printf("7.���ϴ� �帣 ��ȭ �˻�\n");
    printf("0.����\n");
}

void menu_p() {
    printf("\n<=================����޴�=================>\n");
    printf("p.���� ��ġ ���\n");
    printf(">.���� �� ���\n");
    printf("<.���� �� ���\n");
    printf("F/f �������Ʈ�� ��������\n");
    printf("L/l �������Ʈ�� ����������\n");
}

void play_node(DListNode* phead) {
    int count = current->data.time;
    print_dlist(phead);
    printf("\n");

    printf("==========={%s %c %d %d��}===========\n", current->data.title, current->data.genre, current->data.year, current->data.time);
    for (int i = 1; i <= count; i++) {
        printf("%d ", i);
        Sleep(1000);
    }
    current = current->rlink;
    if (current == phead)
        current = current->rlink;

    printf("\n");
}

void transfer_node(DListNode* phead,char ch) {
    switch (ch) {
    case '>':
        current = current->rlink;
        if (current == phead)
            current = current->rlink;
        play_node(phead);
        break;
    case '<':
        current = current->llink;
        if (current == phead)
            current = current->llink;
        play_node(phead);
        break;
    case 'F': case 'f':
        current = phead->rlink;
        play_node(phead);
        break;
    case 'L': case 'l':
        current = phead->llink;
        play_node(phead);
        break;
    }
}

int main(void) {
    DListNode* head = (DListNode *)malloc(sizeof(DListNode));
    init(head);
    char ch;

    int choice1;//������ ���Ĺ���� �Է¹��� ����
    printf("���ο� ������ ���� ���\n");
    printf("1. ���� �� 2. ���� �� 3. ��������: ");
    scanf("%d", &choice1);


    while (1) {
        menu();
        menu_p();
        printf("\n");
        getchar();
        printf("����: ");
        scanf("%c", &ch);
        switch (ch) {
        case '1':
            printf("\n<------------------����------------------->\n");
            insert_node(head, choice1);
            current = head->rlink;
            printf("���ԿϷ�\n");
            break;
        case '2':
            printf("\n<---------------����Ʈȣ��---------------->\n");
            print_dlist(head);
            break;
        case '3':
            printf("\n<-------------����� ����----------------->\n");
            int num1;//list_length�� ���ϰ��� ���� ����
            num1 = list_length(head);
            printf("\n���� ����� ����� ����: %d\n", num1);
            break;
        case '4':
            printf("\n<-----------------��ȭ�˻�---------------->\n");
            find_movie(head);
            break;
        case '5':
            printf("\n<----------------��� ����---------------->\n");
            delete_node(head);
            printf("���� �Ϸ�\n");
            break;
        case '6':
            printf("\n<-------------�ֽſ�ȭ�˻�---------------->\n");
            find_current(head);
            break;
        case '7':
            printf("\n<-----------�����帣�ǿ�ȭ---------------->\n");
            find_genre(head);
            break;
        case 'p':
            play_node(head);
            break;
        case '<': case '>': case 'L': case 'l': case 'F': case 'f':
            transfer_node(head, ch);
            break;
        case '0':
            break;
        }
        if (ch == '0')   break;
    }

    free(head);
    return 0;
}