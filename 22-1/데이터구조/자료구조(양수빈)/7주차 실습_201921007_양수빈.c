//����ǥ������� ���� ���
//1)������ ������ %���� (5+7%3-2*3)
//2)�ŵ����������� ^����(3+2^3^2-1)
//3)���迬���� '<'�� '>�� ���� (3+4-2>(2*3)^2)
//1.573%+23*-
//2.3232^^+1-
//3.34+2-23*2^>
//�ǿ����ں����Ѱ�� 573%+23*--
//�����ں����Ѱ�� 573%+233*-
//���ο�� 1. 12*3+31%3+> (������,�ε�ȣ)
//���ο�� 2. 522*-2+1- (�Ϲݽ�)
//���ο�� 3. 53%2+142*+< (������,�ε�ȣ)
//���ο�� 4. 22^3+4- (�ŵ�����)
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX_STACK_SIZE 100

// ���α׷� 4.3���� ���� �ڵ� �߰� ��
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
		return -1;
	}
	else return s->data[(s->top)--];
}

// ��ũ�Լ�
element peek(StackType* s)
{
	if (is_empty(s)) {
		fprintf(stderr, "���� ���� ����\n");
		return -1;
	}
	else return s->data[s->top];
}
// ===== ���� �ڵ��� �� ===== 


// ���� ǥ�� ���� ��� �Լ�
int eval(char exp[])
{
	int op1, op2, value, i = 0;
	int len = strlen(exp);
	char ch;
	StackType s;
	init_stack(&s);

	for (i = 0; i < len; i++) {
		ch = exp[i];
		if (ch != '+' && ch != '-' && ch != '*' && ch != '/' && ch != '%' && ch != '^' && ch != '<' && ch != '>') {
			value = ch - '0';	// �Է��� �ǿ������̸�
			printf("push: %d\n", value);
			push(&s, value);
		}
		else {	//�������̸� �ǿ����ڸ� ���ÿ��� ����
			op2 = pop(&s);
			op1 = pop(&s);
			if (op1 == -1 || op2 == -1) {//pop���� �� ������°� ����Ǿ� �ǿ����ڰ� ������ ���
				printf("�ǿ����ڰ� �����մϴ�.\n");
				return 0;
			}
			printf("pop: %d\n", op2);
			printf("pop: %d\n", op1);
			switch (ch) { //������ �����ϰ� ���ÿ� ���� 
			case '+': 
				printf("%d + %d ����� ", op1, op2); 
				printf("push: %d", op1 + op2); 
				push(&s, op1 + op2); 
				break;
			case '-': 
				printf("%d - %d ����� ", op1, op2); 
				printf("push: %d\n", op1-op2); 
				push(&s, op1 - op2); 
				break;
			case '*': 
				printf("%d * %d ����� ", op1, op2);
				printf("push: %d\n", op1*op2); 
				push(&s, op1 * op2); 
				break;
			case '/': 
				printf("%d / %d ����� ", op1, op2); 
				printf("push: %d\n", op1/op2); 
				push(&s, op1 / op2); 
				break;
			case '%': 
				printf("%d %% %d ����� ", op1, op2); 
				printf("push: %d\n", op1%op2); 
				push(&s, op1 % op2); 
				break;
			case '^': 
				printf("%d ^ %d ����� ", op1, op2); 
				printf("push: %.0lf\n", pow(op1,op2)); 
				push(&s, pow(op1, op2)); 
				break;
			case '<': 
				printf("%d < %d ����� ", op1, op2);
				printf("%d\n", op1<op2);
				push(&s, op1 < op2);
				break;
			case '>':
				printf("%d > %d ����� ", op1, op2);
				printf("%d\n", op1 > op2);
				push(&s, op1 > op2);
				break;
			}
		}
	}
	if (s.top != 0) {//top�� 0�̾ƴ϶� �ǿ����ڰ� �����ְ� �����ڰ� ������ ���
		printf("�����ڰ� �����մϴ�.");
		return 0;
	}
	return pop(&s);
}

int main(void) {
	char s[MAX_STACK_SIZE] = { 0, };
	int a;
	while (1) {
		printf("����ǥ������Է�: ");
		scanf("%s", s);
		double result = eval(&s);
		printf("������: %.0lf\n", result);
		printf("����Ͻðڽ��ϱ�? 1. ��� 2. ����\n");
		scanf("%d", &a);
		printf("\n------------------------------------\n");
		if (a == 2)
			return 0;
	}
}
