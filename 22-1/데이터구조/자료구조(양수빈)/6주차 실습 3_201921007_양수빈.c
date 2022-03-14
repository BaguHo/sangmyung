//3. palindrome – 교재 144쪽 문제 16
//회문은 앞뒤 어느 쪽에서 읽어도 같은 단어를 의미한다.예를 들면 "eye" "madam" "race car"  등이다.
//여기서 물로 구두점이나 스페이스, 대소문자 등은 무시해야 한다.스택을 사용해서 주어진 문자열이
//회문인지 아닌지 결정하는 프로그램을 작성하시오.
//예: 입력 문자열 "madam" 이면 출력은 "madam은 회문입니다"

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
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
	char ch, open_ch;
	int i, n = strlen(in);  	// n= 문자열의 길이
	init_stack(&s);			// 스택의 초기화

	for (i = 0; i < n; i++) {
		ch = in[i];		// ch = 다음 문자
		if (ch == ' ' || ch == ',' || ch == '\'') continue;
		ch = tolower(ch);//소문자
		push(&s, ch);//push
	}
	for (i = 0; i < n; i++) {
		ch = in[i];
		if (ch == ' ' || ch == ','|| ch == '\'') continue;
		ch = tolower(ch);//소문자
		open_ch = pop(&s);//pop
		if (ch != open_ch) {//실패
			return 0;
		}
	}
	if (!is_empty(&s)) return 0; // 스택에 남아있으면 오류
	return 1;
}

int main(void) {
	char* p = malloc(sizeof(char) * 10);
	int result;
	int choice;

	printf("문자열입력: ");
	gets(p);


	result = check_matching(p);
	if (result == 1) {
		printf("회문입니다.\n");
	}
	else
		printf("회문이 아닙니다.\n");

	printf("-----------------------\n");
	printf("계속하시겠습니까? 1.예 그 외. 아니오");
	scanf("%d", &choice);
	if (choice == 1) {
		getchar();
		main();
	}
	else {
		free(p);
		return 0;
	}
}