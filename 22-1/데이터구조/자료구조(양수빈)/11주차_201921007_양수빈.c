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
        printf("{%s %c %d}   ", a->data.title, a->data.genre, a->data.year);
    }
}

//��ȯȣ�� ����Ʈ �Լ�
void print_list2(ListType* plist,ListNode* a) {
   if (a !=NULL){
        printf("{%s %c %d}   ", a->data.title, a->data.genre, a->data.year);
        return print_list2(plist, a->link);
   }
}

//��ȯȣ�� ���� ����Ʈ �Լ�
void print_list3(ListType* plist, ListNode* a) {
    if (a != NULL) {
        print_list3(plist, a->link);
        printf("{%s %c %d}   ",a->data.title, a->data.genre, a->data.year);
    }
}

//���� ��� �Լ�
int list_length(ListType* plist) {
    return plist->size;
}

//��ȯ ȣ�� ���� ��� �Լ� 
int list_length2(ListType* plist,ListNode *a,int num) {
    if (a != NULL) {
        num++;
        return list_length2(plist, a->link, num);
    }
    else return num;
}

//��ȭ ã�� �Լ�
void find_movie(ListType* plist) {
    char name[ARRAY] = { NULL };// [ARRAY] ;//��ȭ���� �ڷḦ �˻����� ���ڿ�
    printf("��ȭ �����Է�: ");
    scanf("%s",name);

    
    ListNode* search = plist->head;

    if (plist == NULL)
        return 0;
    while (search != NULL) {
        if (strcmp(search->data.title, name)!=0) {
            search = search->link;
        }
        else if (strcmp(search->data.title, name) == 0) {
            printf("�˻� ���: {%s %c %d}\n", search->data.title, search->data.genre, search->data.year);
            break;
        }
        else
            return NULL;
    }
}

//�Է¹��� �帣�� ���� ��ȭ ��� �Լ�
void find_genre(ListType* plist) {
    char genre_name;//���ϴ� �帣�� �˻����� ����
    printf("��ȭ �帣�Է�('A','C','F','R' �� �ϳ�): ");
    getchar();
    scanf("%c", &genre_name);
    ListNode* search = plist->head;

    if (plist == NULL)
        return 0;
    while (search != NULL) {
        if (search->data.genre == genre_name) {
            printf("{%s %c %d}\n",search->data.title, search->data.genre, search->data.year);
        }
        search = search->link;
    }
}

//���� �ֱٿ� ������ ��ȭ�� ã�� �Լ�
void find_current(ListType* plist) {
   int curyear;
   ListNode* search = plist->head;

   if (plist == NULL)
       return 0;

   curyear = search->data.year;//curyear=����Ʈ�� ù ��° year
   for (; search != NULL; search = search->link) {
       if (curyear <= search->data.year) {//curyear���� ����Ʈ�� year�� �� ũ�� �� ����
           curyear = search->data.year;
       }
   }
   printf("%d", curyear);
   search = plist->head;

   for (; search != NULL; search = search->link) {
       if (curyear == search->data.year) {//curyear�� ����Ʈ�� year�� ������ ���
           printf("{%s %c %d}     ", search->data.title, search->data.genre, search->data.year);
       }
   }
}

//plist�� ���� ����Ʈ�� ����� ����Ű�� ������
void insert_node(ListType* plist,int choice1) {
    ListNode* p = (ListNode*)malloc(sizeof(ListNode));
    printf("������ ��ȭ����, ��ȭ�帣('A','C','F','R' �� �ϳ�), �����⵵ �� �Է��ϼ���: ");
    scanf("%s %c %d", p->data.title, &p->data.genre, &p->data.year);

    ListNode* a = plist->head;

    switch (choice1) {
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
        p->link = NULL;//�ʱ�ȭ
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
                    plist->size++;
                    break;
                }
                a = a->link;
            }
        }
        break;
    }
}

//���� �Լ�
void delete_node(ListType* plist) {
    char delete_name[ARRAY];//������ ��ȭ�� �Է¹��� ����
    printf("������ ��ȭ�� �̸��� �Է��ϼ���: ");
    scanf("%s", delete_name);
    ListNode* search = plist->head;

    if (plist->head == NULL) {
        error("error");
        return;
    }


    //��尪 ����
    if (strcmp(search->data.title, delete_name) == 0) {//head==delete_name
        plist->head = search->link;//search�� ���� ���� head����
        plist->size--;//size ���̱�
        free(search);//����
        return;
    }


    while (search != NULL) {
        if (strcmp(search->link->data.title, delete_name) == 0) {
            ListNode* removed = search->link;//���� search ��ġ�� ������ũ���� ����Ű�� removed
            search->link = removed->link;//removed�� ����Ű�� ���� ����� ��ũ�� search�� ����
            if (removed->link != NULL) {//�߰� �� ���� (�ڿ� ��尡 ���� ��)
                search->link = removed->link;
                plist->size--;
                free(removed);
            }
            else {//������ �� ���� (removed->link==NULL)
                search->link = NULL;
                plist->size--;
                free(removed);
            }
                
            return;
            break;
        }
        search = search->link;
    }
}

void menu() {
    printf("\n<------------------�޴�------------------->\n");
    printf("1.����\n");
    printf("2.���\n");
    printf("3.��ȯ���\n");
    printf("4.������ȯ���\n");
    printf("5.����� ���� ���\n");
    printf("6.����� ���� ��ȯ���\n");
    printf("7.��ȭ �˻�\n");
    printf("8.��� ����\n");
    printf("9.���� �ֱٿ� ������ ��ȭ �˻�\n");
    printf("10.���ϴ� �帣 ��ȭ �˻�\n");
    printf("0.����\n");
}

int main(void) {
    ListType* list1;
    list1 = create();
    int ch;
    ListNode* a = list1->head;

    int choice1;//������ ���Ĺ���� �Է¹��� ����
    printf("���ο� ������ ���� ���\n");
    printf("1. ���� �� 2. ���� �� 3. ��������: ");
    scanf("%d", &choice1);

    while (1) {
        menu();
        printf("\n");
        printf("����: ");
        scanf("%d", &ch);
        switch (ch) {
        case 1:
            printf("\n<------------------����------------------->\n");
            insert_node(list1,choice1);
            printf("���ԿϷ�\n");
            a = list1->head;
            break;
        case 2:
            printf("\n<---------------����Ʈȣ��---------------->\n");
            print_list(list1);
            break;
        case 3:
            printf("\n<----------------��ȯȣ��----------------->\n");
            print_list2(list1, a);
            break;
        case 4:
            printf("\n<------------������ȯȣ��----------------->\n");
            print_list3(list1, a);
            break;
        case 5:
            printf("\n<-------------����� ����----------------->\n");
            int num1;//list_length�� ���ϰ��� ���� ����
            num1 = list_length(list1);
            printf("���� ����� ����� ����: %d\n", num1);
            break;
        case 6:
            printf("\n<----------����� ���� ��ȯȣ��----------->\n");
            int num = 0;//��ȯȣ��� �� ����� ������ ��Ÿ���� ����
            int num2;//list_length2�� ���ϰ��� ���� ����
            num2 = list_length2(list1, a, num);
            printf("���� ����� ����� ����(��ȯȣ��): %d\n", num2);
            break;
        case 7:
            printf("\n<-----------------��ȭ�˻�---------------->\n");
            find_movie(list1);
            break;
        case 8:
            printf("\n<----------------��� ����---------------->\n");
            delete_node(list1);
            printf("���� �Ϸ�\n");
            break;
        case 9:
            printf("\n<-------------�ֽſ�ȭ�˻�---------------->\n");
            find_current(list1);
            break;
        case 10:
            printf("\n<-----------�����帣�ǿ�ȭ---------------->\n");
            find_genre(list1);
            break;
        case 0:
            break;
        }
        if (ch == 0)   break;
    }

    free(list1);
    return 0;
}