#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define MAX_LENGTH 101
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

typedef char Data;

typedef struct
{
    Data node[MAX_LENGTH];
    int top;
} Stack;

void InitStack(Stack *s)
{
    s->top = -1;
}

int IsEmpty(Stack *s)
{
    return (s->top == -1);
}

int IsFull(Stack *s)
{
    return (s->top == MAX_LENGTH - 1);
}

void Push(Stack *s, Data data)
{
    if (IsFull(s))
    {
        fprintf(stderr, "ERROR\n");
        return;
    }
    else
    {
        s->node[++(s->top)] = data;
    }
}

Data Pop(Stack *s)
{
    if (IsEmpty(s))
    {
        fprintf(stderr, "ERROR\n");
        exit(1);
    }
    else
    {
        return s->node[(s->top)--];
    }
}

Data Peek(Stack *s)
{
    if (IsEmpty(s))
    {
        fprintf(stderr, "����\n");
        exit(1);
    }
    else
    {
        return s->node[s->top];
    }
}

void Palindrome(char *str)
{
    Stack s;
    InitStack(&s);
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (('a' <= str[i] && str[i] <= 'z') || ('A' <= str[i] && str[i] <= 'Z'))
        {
            str[i] = tolower(str[i]);
            Push(&s, str[i]);
        }
    }
    //������ �̿��Ͽ� ȸ�� �˻�
    char ch;
    for (int i = 0; str[i] != '\0'; i++)
    {
        if ('a' <= str[i] && str[i] <= 'z')
        {
            ch = Pop(&s);
            if (ch == str[i])
            {
                printf("%c %c\n", ch, str[i]);
            }
            else
            {
                printf("ȸ���� �ƴմϴ�\n");
                break;
            }
        }
        if (str[i + 1] == '\0')
        {
            printf("ȸ���Դϴ�\n");
        }
    }
}

int main()
{
    char *str = malloc(sizeof(char) * 50);

    printf("3������ - ���ڿ��� �Է����ּ���\n");
    //�Է��� �׳� �ǳʶپ� ����
    // gets(str);
    scanf("%[^\n]s", str);
    Palindrome(str);
}