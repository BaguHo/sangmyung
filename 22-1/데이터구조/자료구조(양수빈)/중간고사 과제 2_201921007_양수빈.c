//�̷��� ũ�⸦ 10 * 10���� �����, ������ �̿��ϴ� �̷�ã�� ������ �����ؼ�,
//Ż�⿡ �������� �� �Ա����� �ⱸ������ �̷� ��θ� ����Ͻÿ�.

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
	if (r < 0 || c < 0) return;//�� �� ���� �׵θ���
	if (maze[r][c] != '1' && maze[r][c] != '.') {//���� �ƴϰ� ���� ���� �ƴ� ���
		element tmp;
		tmp.r = r;
		tmp.c = c;
		push(s, tmp);
	}
}

void maze_print(char maze[MAZE_SIZE][MAZE_SIZE], int num) {
	printf("<%d��° ������>\n", num);

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
			printf("����\n");
			return 0;
		}
		else {
			here = pop(&s);
			rec[a++] = here;
		}
	}
	printf("����\n\n");

	printf("<������ ��ǥ �ڸ�>\n");
	printf("1��° ��������ǥ: (%d,%d)\n", entry.r,entry.c);
	for (int i = 0; i < a; i++) {
		printf("%d��° ��������ǥ: (%d,%d)\n", i + 2, rec[i].r, rec[i].c);
	}

	return 0;
}