﻿//1번 문제
//1. 괄호 매칭 번호 매기기 – 교재 143쪽 문제 11
//수식에 있는 괄호의 번호를 출력하는 프로그램을 작성하라. 
//왼쪽 괄호가 나올 때마다 괄호 번호는 하나씩 증가한다.오른쪽 괄호가 나오면 매칭되는 왼쪽 괄호의 번호를 출력한다.
//((()) (()))
//12332 45541

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_STACK_SIZE 100

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
		exit(1);
	}
	else return s->data[(s->top)--];
}

// 피크함수
element peek(StackType* s)
{
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else return s->data[s->top];
}
// ===== 스택 코드의 끝 ===== 







int check_matching(const char* in)
{
	StackType s;
	StackType num;//괄호의 숫자입력
	char ch, open_ch;
	int i, n = strlen(in);// n= 문자열의 길이
	init_stack(&s);// 스택의 초기화
	init_stack(&num);
	int number = 1;

	for (i = 0; i < n; i++) {
		ch = in[i];// ch = 다음 문자
		switch (ch) {
		case '(':   case '[':    case '{':
			push(&s, ch);
			printf("%d", number);
			push(&num, number);
			number++;
			break;
		case ')':   case ']':    case '}':
			if (is_empty(&s))  return 0;
			else {
				open_ch = pop(&s);
				printf("%d", pop(&num));
				if ((open_ch == '(' && ch != ')') ||
					(open_ch == '[' && ch != ']') ||
					(open_ch == '{' && ch != '}')) {
					return 0;
				}
				break;
			}
		}
	}



	if (!is_empty(&s)) return 0;// 스택에 남아있으면 오류
	return 1;
}

int main(void) {
	char* p = malloc(sizeof(char) * 10);
	int choice;
	printf("<괄호 입력>\n");
	scanf("%s", p);

	printf("-----------------\n");
	
	if (check_matching(p) == 1)
		printf("\n괄호 매칭 성공\n");
	else
		printf("\n괄호 매칭 실패\n");
	
	printf("-----------------\n");
	printf("계속하시겠습니까? 1.예 그 외. 아니오");
	scanf("%d", &choice);
	if (choice == 1) {
		main();
	}
	else {
		free(p);
		return 0;
	}
}