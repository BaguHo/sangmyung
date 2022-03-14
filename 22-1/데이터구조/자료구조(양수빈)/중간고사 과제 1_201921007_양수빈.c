/*
중위표기수식을 후위표기수식으로 변환(교재 프로그램4.8)하고,
이어서, 변환된 후위표기수식의 값을 계산(교재 프로그램 4.7)하는 전체 프로그램을 완성하시오.

입력 예 : 중위표기(2 + 3)* (4 – 1)
중간결과 예 : 후위표기      2 3 + 4 1 - *
연산결과 값 : 15


(1) + , -, *, / 에 추가하여 나머지 연산자 % 를 포함하시오.
예 : (4 + 9 - 1) % (2 + 1)

(2) 거듭제곱 연산의 기호를 ‘ ^ ’라고 가정하고 거듭제곱연산을 포함하시오.
예 : 3 + 2 ^ 3 ^ 2 – 1

(3) 관계연산자 ‘<’와 ‘>’을 포함하시오.
예 : 3 + 4 – 2 > 2 * 3 ^ 2

(4) 논리연산 AND와 OR의 기호를 각각 ‘ & ’와 ‘ | ’라고 가정하고, 이 연산자들을 포함하시오.
예:    3 + 4 – 2 > 2 * 2 ^ 2 & (5 – 3) % 2 < 5 * 2


    main()에서는:
-위 사칙연산자와 위의(1)~(4) 연산자를 포함하는 중위표기식을 키보드로 입력하고,
-함수호출하여 중위표기식을 후위표기식으로 변환해서 문자열에 저장하고,
-함수호출하여 후위표기 결과를 계산하고 결과값을 출력한다.
- 위의 두 과정에서, 스택의 동작이 화면에 출력되도록 하시오(7주차 실습 참조)

키보드입력 : (2 + 3)* (4 – 1)
중간결과 : 2 3 + 4 1 - *
계산결과 : 15
*/

/*
//피연산자부족한경우 573%+23*--
//연산자부족한경우 573%+233*-
//새로운식 1. 12*3+31%3+> (나머지,관계연산)   ->    1+2*3>3+1%3    =1
//새로운식 2. 522*-2+1- (일반식)            ->    5-2*2+2-1        =2
//새로운식 3. 53%2+142*+< (나머지,관계연산)   ->    5%3+2<1+4*2    =1
//새로운식 4. 22^3+4- (거듭제곱)            ->    2^2+3-4
//새로운식 5. 5-4>2+3|1+2-1>3+1 (논리연산) -> 0
//새로운식 6. 1+2-2<5&1+4<2+4 (논리연산)   -> 1
//기존 식(거듭제곱) 3+2^3^2-1
//기존 식(나머지 연산자) (4+9-1)%(2+1)
//기존 식(관계연산) 3+4-2>2*3^2        ->    0
//기존 식(논리연산) 3+4-2>2*2^2&(5-3)%2<5*2 ->    0
*/
#include <stdio.h>
#include <string.h>
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

//연산자의 우선순위를 반환
int prec(char op)
{
	switch (op) {
	case'&': case'|': return 0;
	case'<': case'>': return 1;
	case'(': case ')': return 2;
	case'+': case'-': return 3;
	case'*': case'/': case'%': return 4;
	case'^': return 5;
	}
}

//중위 표기 후위 표기 수식 변환
void infix_to_postfix(char exp[]) {
	int i = 0;
	int a = 0;
	char ch, top_op,rec[MAX_STACK_SIZE],rec_ch;
	int len = strlen(exp);
	StackType s;

	init_stack(&s);
	for (i = 0; i < len; i++) {
		ch = exp[i];
		switch (ch) {
		case'+':case'-':case'*':case'/':case'%':case'<':case'>':case'&':case'|':
			//스택에 있는 연산자의 우선순위가 더 크거나 같으면 출력
			while (!is_empty(&s) && (prec(ch) <= prec(peek(&s)))) {
				rec_ch = pop(&s);
				printf("pop: %c\n", rec_ch);
				rec[a++] = rec_ch;
			}
			printf("push: %c\n", ch);
			push(&s, ch);
			break;
		case '^':
			printf("push: %c\n", ch);
			push(&s, ch);
			break;
		case '(':
			printf("push: %c\n", ch);
			push(&s, ch);
			break;
		case')':
			top_op = pop(&s);
			printf("pop: %c\n", top_op);
			//왼쪽괄호를 만날 때까지 배열에다가 값을 넣음
			while (top_op != '(') {
				rec_ch = top_op;
				rec[a++] = rec_ch;
				top_op = pop(&s);
				printf("pop: %c\n", top_op);
			}
			break;
		default:
			rec_ch = ch;
			rec[a++] = rec_ch;
			break;
		}
	}
	while (!is_empty(&s)) { //스택에 저장된 연산자들 출력
		rec_ch = pop(&s);
		printf("pop: %c\n", rec_ch);
		rec[a++] = rec_ch;
	}

	rec[a] = NULL;//증가시켰던 a인덱스에서 마지막 값을 NULL로 바꿔서 뒤에 다 없앤다
	strcpy(exp, rec);
}

// 후위 표기 수식 계산 함수
int eval(char exp[])
{
	int op1, op2, value, i = 0;
	int len = strlen(exp);
	char ch;
	int result =0;
	StackType s;
	init_stack(&s);

	for (i = 0; i < len; i++) {
		ch = exp[i];
		if (ch != '+' && ch != '-' && ch != '*' && ch != '/' && ch != '%' && ch != '^' && ch != '<' && ch != '>' && ch != '&' && ch != '|') {
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
				printf("push: %d\n", op1 - op2);
				push(&s, op1 - op2);
				break;
			case '*':
				printf("%d * %d 계산결과 ", op1, op2);
				printf("push: %d\n", op1 * op2);
				push(&s, op1 * op2);
				break;
			case '/':
				printf("%d / %d 계산결과 ", op1, op2);
				printf("push: %d\n", op1 / op2);
				push(&s, op1 / op2);
				break;
			case '%':
				printf("%d %% %d 계산결과 ", op1, op2);
				printf("push: %d\n", op1 % op2);
				push(&s, op1 % op2);
				break;
			case '^':
				printf("%d ^ %d 계산결과 ", op1, op2);
				printf("push: %.0lf\n", pow(op1, op2));
				push(&s, pow(op1, op2));
				break;
			case '<':
				printf("%d < %d 계산결과 ", op1, op2);
				printf("%d\n", op1 < op2);
				push(&s, op1 < op2);
				break;
			case '>':
				printf("%d > %d 계산결과 ", op1, op2);
				printf("%d\n", op1 > op2);
				push(&s, op1 > op2);
				break;
			case '|':
				if (op1 != 0 || op2 != 0)
					result = 1;
				else//op1=0 op2=0
					result = 0;
				printf("%d | %d 계산 결과 %d\n", op1, op2, result);
				push(&s, result);
				break;

			case '&':
				if (op1 == 1 && op2 == 1)
					result = 1;
				else
					result = 0;
				printf("%d & %d 계산 결과 %d\n", op1, op2, result);
				push(&s, result);
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
		printf("중위표기수식입력: ");
		scanf("%s", s);

		infix_to_postfix(s);


		printf("\n------------------------------------\n");
		printf("후위표기수식: ");
		for (int i = 0; i < strlen(s); i++)
			printf("%c", s[i]);
		printf("\n");

		double result = eval(s);
		
		printf("\n");

		printf("연산결과: %.0lf\n", result);
		printf("계속하시겠습니까? 1. 계속 2. 종료\n");
		scanf("%d", &a);
		printf("\n------------------------------------\n");
		if (a == 2)
			return 0;
	}
}

