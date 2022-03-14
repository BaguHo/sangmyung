//2. run-length 압축 -  교재 143쪽 문제 12
//다음과 같이 문자열을 압축하는 프로그램을 작성하시오.  "4a3b"는 'a'가 4개, 'b'가 3개 있다는 의미이다.
//이러한 압축 방법을 런길이 압축이라고 한다.소문자와 대문자는 구분하지 않는다.
//압축된 문자열에서는 소문자로 출력한다.스택의 peek() 연산을 고려해보자.
//  예: 문자열 입력 aaaAbBb     압축결과 4a3b

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
	StackType s1,s2;
	char ch, open_ch;
	char ch2, pick;
	int i, n = strlen(in);  	// n= 문자열의 길이
	init_stack(&s1);			// 스택의 초기화
	init_stack(&s2);

	for (i = 0; i < n; i++) {
		ch = in[i];		// ch = 다음 문자
		ch = tolower(ch);//소문자
		push(&s1, ch);//입력
	}

	for (i = 0; i < n; i++) {
		ch2 = pop(&s1);
		push(&s2, ch2);//역순배치
	}
	
	printf("런길이: ");
	i = 0;
	while(i<n){
		int count = 0;
		pick = in[i++];
		count++;//첫 번째 카운트
		while (pick == in[i]) {//pick과 in의 값이 같을 때 계속 반복
			count++;//같은 값마다 카운트
			i++;
		}
		printf("%d%c", count, pick);
	}


	printf("\n-----------------------\n");
	printf("입력했던 문자열:");

	for (i = 0; i < n; i++) {
		open_ch = pop(&s2);
		printf("%c", open_ch);
	}
	
	printf("\n-----------------------\n");


	if (!is_empty(&s2)) return 0; // 스택에 남아있으면 오류
	return 1;
}

int main(void) {
	char* p = malloc(sizeof(char) * 20);
	int result;
	int choice;
	printf("문자열입력: ");
	scanf("%s", p);

	printf("-----------------------\n");

	result = check_matching(p);
	if (result == 1)
		printf("성공\n");
	else
		printf("실패\n");


	printf("-----------------------\n");
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