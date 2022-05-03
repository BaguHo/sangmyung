#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#define MAX_STACK_SIZE 100

typedef char element;

typedef struct stacktype {
	element data[MAX_STACK_SIZE];
	int top;
}StackType;

typedef struct {
	element data[MAX_STACK_SIZE];
	int top;
}Stack_Type;

void init_stack(Stack_Type* s)
{
	s->top = -1;
}

int is_full(Stack_Type* s)
{
	return (s->top == MAX_STACK_SIZE - 1);
}

int is_empty(Stack_Type* s)
{
	return (s->top == -1);
}

void Push(Stack_Type* s, element n)
{
	if (is_full(s))
	{
		fprintf(stderr, "포화에러\n");
		return;
	}
	else
		s->data[++(s->top)] = n;
}

element Pop(Stack_Type* s)
{
	if (is_empty(s))
	{
		fprintf(stderr, "공백에러\n");
		exit(1);
	}
	else
		return s->data[(s->top)--];
}

element peek(Stack_Type* s)
{
	if (is_empty(s))
	{
		fprintf(stderr, "공백 에러");
		exit(1);
	}
	else
		return s->data[s->top];
}

void comparison(char* data)
{
	StackType s;
	init_stack(&s);
	for (int i = 0; data[i] !=NULL ; i++)
	{
		data[i] = tolower(data[i]);
		Push(&s, data[i]);
	}
	printf("%s\n", data);
	char ch;
	char ch2;
	int i = 0;
	while (!is_empty(&s))
	{
		ch = data[i];
		ch2 = Pop(&s);
		if (ch == ' ')
		{
			ch = data[++i];
		}
		if (ch2 == ' ')
		{
			ch2 = Pop(&s);
		}
		printf("%c %c \n", ch, ch2);
		if (ch != ch2)
		{
			printf("회문이 아닙니다.");
			exit(1);
		}
		i++;
	}
	printf("회문입니다.");
}

int main(void)
{
	char* data = malloc(sizeof(char) * 50);
	printf("입력하시오:");
	scanf("%[^\n]s", data);
	comparison(data);
	free(data);
	return 0;
}