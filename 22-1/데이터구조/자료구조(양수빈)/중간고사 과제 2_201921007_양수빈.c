//미로의 크기를 10 * 10으로 만들고, 스택을 이용하는 미로찾기 문제를 수정해서,
//탈출에 성공했을 때 입구부터 출구까지의 미로 경로를 출력하시오.

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAZE_SIZE 10
#define MAX_STACK_SIZE 100

typedef struct {
	short r;
	short c;
}element;

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



element here = { 1,0 }, entry = { 1,0 };
element rec[MAX_STACK_SIZE];

char maze[MAZE_SIZE][MAZE_SIZE] = {
	{'1','1','1','1','1','1','1','1','1','1'},
	{'e','0','1','1','0','0','0','0','0','1'},
	{'1','0','1','1','0','1','0','1','1','1'},
	{'1','0','0','0','0','1','0','0','0','1'},
	{'1','1','0','1','0','0','1','1','1','1'},
	{'1','0','1','0','0','1','1','1','1','1'},
	{'1','0','1','0','1','0','0','0','0','1'},
	{'1','0','0','0','0','0','1','1','0','x'},
	{'1','1','1','0','1','0','0','0','1','1'},
	{'1','1','1','1','1','1','1','1','1','1'},
};

void push_loc(StackType* s, int r, int c) {
	if (r < 0 || c < 0) return;//갈 수 없는 테두리벽
	if (maze[r][c] != '1' && maze[r][c] != '.') {//벽이 아니고 갔던 길이 아닌 경우
		element tmp;
		tmp.r = r;
		tmp.c = c;
		push(s, tmp);
	}
}

void maze_print(char maze[MAZE_SIZE][MAZE_SIZE], int num) {
	printf("<%d번째 움직임>\n", num);

	printf("\n");

	for (int r = 0; r < MAZE_SIZE; r++) {
		for (int c = 0; c < MAZE_SIZE; c++) {
			printf("%c", maze[r][c]);
		}
		printf("\n");
	}
	printf("\n------------------------------------\n");
}

int main(void) {
	int r, c;
	StackType s;
	int num = 1;
	int a = 0;
	init_stack(&s);

	here = entry;
	while (maze[here.r][here.c] != 'x') {
		r = here.r;
		c = here.c;

		maze[r][c] = '.';
		maze_print(maze, num++);
		push_loc(&s, r - 1, c);
		push_loc(&s, r + 1, c);
		push_loc(&s, r, c - 1);
		push_loc(&s, r, c + 1);

		if (is_empty(&s)) {
			printf("실패\n");
			return 0;
		}
		else {
			here = pop(&s);
			rec[a++] = here;
		}
	}
	printf("성공\n\n");

	printf("<움직인 좌표 자리>\n");
	printf("1번째 움직인좌표: (%d,%d)\n", entry.r,entry.c);
	for (int i = 0; i < a; i++) {
		printf("%d번째 움직인좌표: (%d,%d)\n", i + 2, rec[i].r, rec[i].c);
	}

	return 0;
}