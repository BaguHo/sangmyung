#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#define MAX_STACK_SIZE 10000

typedef int element;
typedef struct {
    element data[MAX_STACK_SIZE];
    int top;
} StackType;

// ���� �ʱ�ȭ �Լ�
void init_stack(StackType* s)
{
    s->top = -1;
}

// ���� ���� ���� �Լ�
int is_empty(StackType* s)
{
    return (s->top == -1);
}

// ��ȭ ���� ���� �Լ�
int is_full(StackType* s)
{
    return (s->top == (MAX_STACK_SIZE - 1));
}

// �����Լ�
void push(StackType* s, element item)
{
    if (is_full(s)) {
        fprintf(stderr, "���� ��ȭ ����\n");
        return;
    }
    else s->data[++(s->top)] = item;
}

// �����Լ�
element pop(StackType* s)
{
    if (is_empty(s)) {
        fprintf(stderr, "���� ���� ����\n");
        exit(1);
    }
    else return s->data[(s->top)--];
}

// ��ũ�Լ�
element peek(StackType* s)
{
    if (is_empty(s)) {
        fprintf(stderr, "���� ���� ����\n");
        exit(1);
    }
    else return s->data[s->top];
}
// ===== ���� �ڵ��� �� ===== 



int check_matching(const char *p,FILE *fp2)
{
    StackType s;
    char ch, open_ch;
    int i, n = strlen(p);     // n= ���ڿ��� ����
    init_stack(&s);         // ������ �ʱ�ȭ
    
    for (i = 0; i < n; i++) {
        ch = p[i];      // ch = ���� ����
        switch (ch) {
        case '\''://��������ǥ
            i++;
            while (p[i] != '\'') {
                i++;
            }
            break;
        case'\"'://ū����ǥ
            i++;
            while (p[i] != '\"') {
                i++;
            }
            break;
        case '/'://�ּ�
            if (p[i + 1] == '/') {// //�ּ�ó��
                while (p[i] != '\n')
                    i++;
            }
            else if (p[i + 1] == '*') {// /**/ �κ��ּ�ó��
                while (p[i] != '\0') {
                    i++;
                    if (p[i] == '*' && p[i + 1] == '/') {
                        i++;
                        break;//while�� Ż��
                    }
                }
            }
            break;//caseŻ��
        case '(':   case '[':    case '{':
            push(&s, ch);
            printf("push: %c\n", ch);
            fprintf(fp2,"push: %c\n", ch);//�����Է�
            break;
        case ')':   case ']':    case '}':
            if (is_empty(&s))  return 0;
            else {
                open_ch = pop(&s);
                printf("pop: %c\n", open_ch);
                fprintf(fp2,"pop: %c\n", open_ch);//�����Է�
                if ((open_ch == '(' && ch != ')') ||
                    (open_ch == '[' && ch != ']') ||
                    (open_ch == '{' && ch != '}')) {
                    return 0;
                }
                break;
            }
        }
    }
    if (!is_empty(&s)) return 0; // ���ÿ� ���������� ����
    return 1;
}



int main(void) {
    FILE* fp1 = fopen("stack.in.txt", "r");
    if (fp1 == NULL) {
        printf("������ �������� �ʽ��ϴ�.\n");
        exit(1);
    }

    char* p = malloc(sizeof(char) * MAX_STACK_SIZE);

    int i = 0;

    while (!feof(fp1)) {
        p[i] = fgetc(fp1);
        i++;
    }
    p[i] = NULL; //���ʿ��� ������ ���� ���̱�

    FILE* fp2 = fopen("stack.out.txt", "w");

    if (check_matching(p,fp2) == 1) {
        printf("��ȣ ��Ī ����\n");
        fprintf(fp2,"��ȣ ��Ī ����\n");
    }
    else {
        printf("\n��ȣ ��Ī ����\n");
        fprintf(fp2,"��ȣ ��Ī ����\n");
    }

    free(p);
    fclose(fp2);
    fclose(fp1);
    return 0;
}