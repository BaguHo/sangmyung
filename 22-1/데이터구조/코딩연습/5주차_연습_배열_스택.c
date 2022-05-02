#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define MAX_LENGTH 101
// 1번 문제
// 1. 괄호 매칭 번호 매기기 ? 교재 143쪽 문제 11
//수식에 있는 괄호의 번호를 출력하는 프로그램을 작성하라.
//왼쪽 괄호가 나올 때마다 괄호 번호는 하나씩 증가한다.오른쪽 괄호가 나오면 매칭되는 왼쪽 괄호의 번호를 출력한다.
//((()) (()))
// 12332 45541

// 2. run-length 압축 -  교재 143쪽 문제 12
//다음과 같이 문자열을 압축하는 프로그램을 작성하시오.  "4a3b"는 'a'가 4개, 'b'가 3개 있다는 의미이다.
//이러한 압축 방법을 런길이 압축이라고 한다.소문자와 대문자는 구분하지 않는다.
//압축된 문자열에서는 소문자로 출력한다.스택의 peek() 연산을 고려해보자.
//   예: 문자열 입력 aaaAbBb     압축결과 4a3b

// 3. palindrome ? 교재 144쪽 문제 16
//회문은 앞뒤 어느 쪽에서 읽어도 같은 단어를 의미한다.예를 들면 "eye" "madam" "race car"  등이다.
//여기서 물로 구두점이나 스페이스, 대소문자 등은 무시해야 한다.스택을 사용해서 주어진 문자열이
//회문인지 아닌지 결정하는 프로그램을 작성하시오.
//예: 입력 문자열 "madam" 이면 출력은 "madam은 회문입니다"

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
        fprintf(stderr, "에러\n");
        exit(1);
    }
    else
    {
        return s->node[s->top];
    }
}
//여기서 입력을 또 안받는다
void Palindrome()
{
    char str[MAX_LENGTH];
    printf("3번문제 - 문자열을 입력해주세요\n");
    scanf("%[^\n]s", str);
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
    //스택을 이용하여 회문 검사
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
                printf("회문이 아닙니다\n");
                break;
            }
        }
        if (str[i + 1] == '\0')
        {
            printf("회문입니다\n");
        }
    }
}

void First()
{
    Stack s;
    InitStack(&s);
    char result[MAX_LENGTH];
    printf("괄호를 입력해주세요\n");
    scanf("%s", result);
    for (int i = 0; result[i] != '\0'; i++)
    {
        switch (result[i])
        {
        case '(':
        case '[':
        case '{':
            Push(&s, result[i]);
            printf("%d ", s.top + 1);
            break;
        case ')':
            if (Peek(&s) == '(')
            {
                printf("%d ", s.top + 1);
                Pop(&s);
            }
        case ']':
            if (Peek(&s) == '[')
            {
                printf("%d ", s.top + 1);
                Pop(&s);
            }
        case '}':
            if (Peek(&s) == '{')
            {
                printf("%3d ", s.top + 1);
                Pop(&s);
            }
        default:
            break;
        }
    }
    printf("\n");
}
// 2번문제에서 출력이 이상함
void Second()
{
    Stack s;
    InitStack(&s);
    char str[MAX_LENGTH];
    char result[MAX_LENGTH];
    int result_idx = 0;
    printf("2번문제 - 문자열을 입력해주세요\n");
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

int main()
{
    int qurter;
    printf("몇 번 문제를 푸시겠습니까?\n");
    printf("1. 괄호 입력 문제\n");
    printf("2. 문자열 압축 문제\n");
    printf("3. 회문 판별 문제\n");
    scanf("%d", &qurter);

    if (qurter == 1)
    {
        First();
    }
    else if (qurter == 2)
    {
        Second();
    }
    else if (qurter == 3)
    {
        Palindrome();
    }
}