#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0

// 1�� ����
// 1. ��ȣ ��Ī ��ȣ �ű�� ? ���� 143�� ���� 11
//���Ŀ� �ִ� ��ȣ�� ��ȣ�� ����ϴ� ���α׷��� �ۼ��϶�.
//���� ��ȣ�� ���� ������ ��ȣ ��ȣ�� �ϳ��� �����Ѵ�.������ ��ȣ�� ������ ��Ī�Ǵ� ���� ��ȣ�� ��ȣ�� ����Ѵ�.
//((()) (()))
// 12332 45541

// 2. run-length ���� -  ���� 143�� ���� 12
//������ ���� ���ڿ��� �����ϴ� ���α׷��� �ۼ��Ͻÿ�.  "4a3b"�� 'a'�� 4��, 'b'�� 3�� �ִٴ� �ǹ��̴�.
//�̷��� ���� ����� ������ �����̶�� �Ѵ�.�ҹ��ڿ� �빮�ڴ� �������� �ʴ´�.
//����� ���ڿ������� �ҹ��ڷ� ����Ѵ�.������ peek() ������ ����غ���.
//   ��: ���ڿ� �Է� aaaAbBb     ������ 4a3b

// 3. palindrome ? ���� 144�� ���� 16
//ȸ���� �յ� ��� �ʿ��� �о ���� �ܾ �ǹ��Ѵ�.���� ��� "eye" "madam" "race car"  ���̴�.
//���⼭ ���� �������̳� �����̽�, ��ҹ��� ���� �����ؾ� �Ѵ�.������ ����ؼ� �־��� ���ڿ���
//ȸ������ �ƴ��� �����ϴ� ���α׷��� �ۼ��Ͻÿ�.
//��: �Է� ���ڿ� "madam" �̸� ����� "madam�� ȸ���Դϴ�"

typedef int Data;

typedef struct __node
{
    Data data;
    struct Node *next;
} Node;

typedef struct
{
    Node *head;
} Stack;

void InitStack(Stack *s)
{
    s->head = NULL;
}

int IsEmpty(Stack *s)
{
    if (s->head == NULL)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

void Push(Stack *s, Data data)
{
    Node *new_node = malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = s->head;
    s->head = new_node;
}

Data Pop(Stack *s)
{
    Node *temp_node;
    Data data;

    if (IsEmpty(s))
    {
        printf("������ ������ϴ�\n");
        exit(-1);
    }
    data = s->head->data;
    temp_node = s->head;

    s->head = s->head->next;
    free(temp_node);
    return data;
}

Data Peek(Stack *s)
{
    if (IsEmpty(s))
    {
        printf("ERROR");
        exit(-1);
    }
}

int main()
{
}