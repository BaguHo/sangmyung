#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define MAX_LENGTH 101

typedef char Data;

typedef struct
{
    Data node[MAX_LENGTH];
    int top;
} Stack;

void InitStack(Stack* s)
{
    s->top = -1;
}

int IsEmpty(Stack* s)
{
    return (s->top == -1);
}

int IsFull(Stack* s)
{
    return (s->top == MAX_LENGTH - 1);
}

void Push(Stack* s, Data data)
{
    if (IsFull(s))
    {
        fprintf(stderr, "Push ERROR\n");
        return;
    }
    else
    {
        s->node[++(s->top)] = data;
    }
}

Data Pop(Stack* s)
{
    if (IsEmpty(s))
    {
        fprintf(stderr, "Pop ERROR\n");
        exit(1);
    }
    else
    {
        return s->node[(s->top)--];
    }
}

Data Peek(Stack* s)
{
    if (IsEmpty(s))
    {
        fprintf(stderr, "Peek Error\n");
        exit(1);
    }
    else
    {
        return s->node[s->top];
    }
}

int Barket()
{
    Stack s;
    InitStack(&s);
    char str[MAX_LENGTH];
    printf("��ȣ�� �Է����ּ���\n");
    scanf("%s", str);
    int n = strlen(str);
    for (int i = 0; i < n; i++)
    {
        char ch = str[i];
        switch (ch)
        {
        case '(': case '{': case '[':
            Push(&s, str[i]);
            printf("%d ", s.top + 1);
            break;
        case ')': case '}': case ']':
            if (IsEmpty(&s))
                return 0;
            else {
                char ch2 = Pop(&s);
                printf("%d ", s.top + 2);
                if (ch2 == '(' && ch != ')' || (ch2 == '{' && ch != '}') || ch2 == '[' && ch != ']') {
                    return 0;
                }
                break;
            }
        }
    }
    printf("\n");
    if (!IsEmpty(&s)) return 0;
    return 1;
}

void Palindrome()
{
    char str[MAX_LENGTH];
    Stack s;
    InitStack(&s);
    printf("3������ - ���ڿ��� �Է����ּ���\n");
    char a;
    scanf("%c", &a);
    scanf("%[^\n]s", str);
    printf("%s\n", str);
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

void Profix() {
    Stack s;
    InitStack(&s);
    char str[MAX_LENGTH];
    printf("����ǥ��� ������ �Է����ּ���\n");
    scanf("%s", str);
    int a, b, c;
    char ch1, ch2;
    int n = strlen(str);
    for (int i = 0; i < n; i++) {
        if ('0' <= str[i] && str[i] <= '9') {
            Push(&s, str[i] - '0');
        }
        else if (str[i] == '*') {
            b = Pop(&s);
            a = Pop(&s);
            c = a * b;
            printf("%d * %d = %d\n", a, b, c);
            Push(&s, c);
        }
        else if (str[i] == '+') {
            b = Pop(&s);
            a = Pop(&s);
            c = a + b;
            printf("%d + %d = %d\n", a, b, c);
            Push(&s, c);
        }
        else if (str[i] == '-') {
            b = Pop(&s);
            a = Pop(&s);
            c = a - b;
            printf("%d - %d = %d\n", a, b, c);
            Push(&s, c);
        }
        else if (str[i] == '/') {
            b = Pop(&s);
            a = Pop(&s);
            c = a / b;
            printf("%d / %d = %d\n", a, b, c);
            Push(&s, c);
        }
        else if (str[i] == '^') {
            b = Pop(&s);
            a = Pop(&s);
            c = 1;
            for (int k = 0; k < b; k++) {
                c *= a;
            }
            printf("%d ^ %d = %d\n", a, b, c);
            Push(&s, c);
        }
        else if (str[i] == '>') {
            b = Pop(&s);
            a = Pop(&s);
            c = a > b;
            printf("%d > %d = %d\n", a, b, c);
            Push(&s, c);
        }
        else if (str[i] == '<') {
            b = Pop(&s);
            a = Pop(&s);
            c = a < b;
            printf("%d < %d = %d\n", a, b, c);
            Push(&s, c);
        }
        else if (str[i] == '=') {
            b = Pop(&s);
            a = Pop(&s);
            c = a == b;
            printf("%d = %d = %d\n", a, b, c);
            Push(&s, c);
        }
        else if (str[i] == '&') {
            b = Pop(&s);
            a = Pop(&s);
            c = a && b;
            printf("%d & %d = %d\n", a, b, c);
            Push(&s, c);
        }
        else if (str[i] == '|') {
            b = Pop(&s);
            a = Pop(&s);
            c = a || b;
            printf("%d | %d = %d\n", a, b, c);
            Push(&s, c);
        }
    }
    printf("�����: %d\n", Pop(&s));
}

void RunLength()
{
    Stack s;
    InitStack(&s);
    printf("2������ - ���ڿ��� �Է����ּ���\n");
    char str[MAX_LENGTH];
    char result[MAX_LENGTH];
    int result_idx = 0;
    scanf("%s", str);

    int n = strlen(str);
    int k;
    for (int i = 0; i < n; i++)
    {
        if (i == 0) {
            Push(&s, str[0]);
        }
        else if (str[i] == str[i - 1]) {
            Push(&s, str[i]);
        }
        else if (str[i] != str[i - 1])
        {
            //bbbbccaa�� �Է��Ͽ��� �� a �κ��� a1���� ��µȴ�(��°� b4c2a1)
            char temp;
            result[result_idx] = Peek(&s);
            for (k = 0; !IsEmpty(&s); k++) {
                temp = Pop(&s);
            }
            result[result_idx + 1] = k + '0';
            result_idx += 2;
            Push(&s, str[i]);
        }
    }
    if (!IsEmpty(&s)) {
        char temp_ch = Pop(&s);
        result[result_idx] = temp_ch;
        result[result_idx + 1] = k + '0';
    }
    int n2 = strlen(result);
    for (int i = 0; i < n2 - 3; i++)
    {
        printf("%c", result[i]);
    }
    printf("\n");
}

int main()
{
    int n;
    printf("�� �� ������ Ǫ�ðڽ��ϱ�?\n");
    printf("1. Barket check\n");
    printf("2. Run_length\n");
    printf("3. Palindrome\n");
    printf("4. profix\n");
    scanf("%d", &n);
    printf("==================================\n");
    switch (n)
    {
    case 1:
        if (Barket() == 1) {
            printf("��ȣ �˻� ����\n");
        }
        else {
            printf("��ȣ �˻� ����\n");
        }
        break;
    case 2:
        RunLength();
        break;
    case 3:
        Palindrome();
        break;
    case 4:
        Profix();
        break;
    }
}

// 34+2-222^*>73?2/52*&