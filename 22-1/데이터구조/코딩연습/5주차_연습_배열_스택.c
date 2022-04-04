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
        str[i] = tolower(str[i]);
        Push(&s, str[i]);
    }
    //������ �̿��Ͽ� ȸ�� �˻�
    printf("%s\n", str);

    for (int i = 0; str[i] != '\0'; i++){
        
    }
}

int main()
{
    Stack s;
    InitStack(&s);
    int qurter;
    char result[MAX_LENGTH];
    char str[MAX_LENGTH];
    int result_idx = 0;
    printf("�� �� ������ Ǫ�ðڽ��ϱ�?\n");
    printf("1. ��ȣ �Է� ����\n");
    printf("2. ���ڿ� ���� ����\n");
    printf("3. ȸ�� �Ǻ� ����\n");
    scanf("%d", &qurter);

    if (qurter == 1)
    {
        printf("��ȣ�� �Է����ּ���\n");
        scanf("%s", result);
        int idx = 1;
        for (int i = 0; result[i] != '\0'; i++)
        {
            if (result[i] == '(')
            {
                printf("%d ", idx);
                Push(&s, idx++);
            }
            else if (result[i] == ')')
            {
                idx--;
                printf("%d ", idx);
                Pop(&s);
            }
        }
        printf("\n");
    }
    else if (qurter == 2)
    {
        printf("2������ - ���ڿ��� �Է����ּ���\n");
        scanf("%s", str);
        for (int i = 0; str[i] != '\0'; i++)
        {
            if (i == 0)
            {
                Push(&s, str[0]);
            }
            else if (str[i] == str[i - 1])
            {
                Push(&s, str[i]);
            }
            else
            {
                int i;
                char temp;
                result[result_idx + 1] = Pop(&s);
                for (i = 1; IsEmpty(&s); i++)
                {
                    temp = Pop(&s);
                }
                result[result_idx] = i;
                result_idx += 2;
            }
        }
        for (int i = 0; result[i] != '\0'; i++)
        {
            printf("%c", result[i]);
        }
        printf("\n");
    }
    else if (qurter == 3)
    {
        printf("3������ - ���ڿ��� �Է����ּ���\n");
        //�Է��� �׳� �ǳʶپ� ����
        // gets(str);
        scanf("%[^\n]s", str);
        Palindrome(str);
    }
}