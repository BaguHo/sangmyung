//후위표기수식의 값을 계산
//1)나머지 연산자 %포함 (5+7%3-2*3)
//2)거듭제곱연산자 ^포함(3+2^3^2-1)
//3)관계연산자 '<'와 '>을 포함 (3+4-2>(2*3)^2)
//1.573%+23*-
//2.3232^^+1-
//3.34+2-23*2^>
//피연산자부족한경우 573%+23*--
//연산자부족한경우 573%+233*-
//새로운식 1. 12*3+31%3+> (나머지,부등호)
//새로운식 2. 522*-2+1- (일반식)
//새로운식 3. 53%2+142*+< (나머지,부등호)
//새로운식 4. 22^3+4- (거듭제곱)
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX_STACK_SIZE 100

// 프로그램 4.3에서 스택 코드 추가 끝
typedef int element;
typedef struct {
	element data[MAX_STACK_SIZE];
	int top;
} StackType;

// 스택 초기화 함수
void init_stack(StackType* s)
{
	s->top = -1;
}

// 공백 상태 검출 함수
int is_empty(StackType* s)
{
	return (s->top == -1);
}

// 포화 상태 검출 함수
int is_full(StackType* s)
{
	return (s->top == (MAX_STACK_SIZE - 1));
}

// 삽입함수
void push(StackType* s, element item)
{
	if (is_full(s)) {
		fprintf(stderr, "스택 포화 에러\n");
		return;
	}
	else s->data[++(s->top)] = item;
}

// 삭제함수
element pop(StackType* s)
{
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
		return -1;
	}
	else return s->data[(s->top)--];
}

// 피크함수
element peek(StackType* s)
{
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
		return -1;
	}
	else return s->data[s->top];
}
// ===== 스택 코드의 끝 ===== 


// 후위 표기 수식 계산 함수
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
			value = ch - '0';	// 입력이 피연산자이면
			printf("push: %d\n", value);
			push(&s, value);
		}
		else {	//연산자이면 피연산자를 스택에서 제거
			op2 = pop(&s);
			op1 = pop(&s);
			if (op1 == -1 || op2 == -1) {//pop했을 때 공백상태가 검출되어 피연산자가 부족한 경우
				printf("피연산자가 부족합니다.\n");
				return 0;
			}
			printf("pop: %d\n", op2);
			printf("pop: %d\n", op1);
			switch (ch) { //연산을 수행하고 스택에 저장 
			case '+': 
				printf("%d + %d 계산결과 ", op1, op2); 
				printf("push: %d", op1 + op2); 
				push(&s, op1 + op2); 
				break;
			case '-': 
				printf("%d - %d 계산결과 ", op1, op2); 
				printf("push: %d\n", op1-op2); 
				push(&s, op1 - op2); 
				break;
			case '*': 
				printf("%d * %d 계산결과 ", op1, op2);
				printf("push: %d\n", op1*op2); 
				push(&s, op1 * op2); 
				break;
			case '/': 
				printf("%d / %d 계산결과 ", op1, op2); 
				printf("push: %d\n", op1/op2); 
				push(&s, op1 / op2); 
				break;
			case '%': 
				printf("%d %% %d 계산결과 ", op1, op2); 
				printf("push: %d\n", op1%op2); 
				push(&s, op1 % op2); 
				break;
			case '^': 
				printf("%d ^ %d 계산결과 ", op1, op2); 
				printf("push: %.0lf\n", pow(op1,op2)); 
				push(&s, pow(op1, op2)); 
				break;
			case '<': 
				printf("%d < %d 계산결과 ", op1, op2);
				printf("%d\n", op1<op2);
				push(&s, op1 < op2);
				break;
			case '>':
				printf("%d > %d 계산결과 ", op1, op2);
				printf("%d\n", op1 > op2);
				push(&s, op1 > op2);
				break;
			}
		}
	}
	if (s.top != 0) {//top이 0이아니라 피연산자가 남아있고 연산자가 부족한 경우
		printf("연산자가 부족합니다.");
		return 0;
	}
	return pop(&s);
}

int main(void) {
	char s[MAX_STACK_SIZE] = { 0, };
	int a;
	while (1) {
		printf("후위표기수식입력: ");
		scanf("%s", s);
		double result = eval(&s);
		printf("연산결과: %.0lf\n", result);
		printf("계속하시겠습니까? 1. 계속 2. 종료\n");
		scanf("%d", &a);
		printf("\n------------------------------------\n");
		if (a == 2)
			return 0;
	}
}
