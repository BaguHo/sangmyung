#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

#define MAX_STACK_SIZE 100

typedef char element;

typedef struct {
   element data[MAX_STACK_SIZE];
   int top;
}Stack_Type;

void init(Stack_Type* s)
{
   s->top = -1;
}

int is_empty(Stack_Type* s)
{
   return (s->top == -1);
}

int is_full(Stack_Type* s)
{
   return (s->top == MAX_STACK_SIZE-1);
}

void push(Stack_Type* s, element n)
{
   if (is_full(s))
   {
      fprintf(stderr, "포화에러입니다.\n");
      exit(1);
   }
   s->data[++(s->top)] = n;
}

element pop(Stack_Type*s)
{
   if (is_empty(s))
   {
      fprintf(stderr, "공복에러입니다.\n");
      exit(1);
   }
   return s->data[(s->top)--];
}
element peek(Stack_Type* s)
{
   if (is_empty(s))
   {
      fprintf(stderr, "공복에러입니다.\n");
      exit(1);
   }
   return s->data[s->top];
}

void check(element* data)
{
   char ch;
   int op1, op2;
   int value;
   Stack_Type s;
   init(&s);
   int len = strlen(data);
   for (int i = 0; i < len; i++)
   {
      ch = data[i];
      if (ch != '+' && ch != '-' && ch != '*' && ch != '/'&& ch!='^' && ch != '<' && ch!= '>' && ch != '&' && ch != '|' && ch != '=')
      {
         value = ch - '0';
         push(&s, value);
      }
      else
      {
         op1 = pop(&s);
         op2 = pop(&s);
         switch (ch)
         {
         case '+':
            printf("%d + %d = %d\n", op2, op1, op2 + op1);
            push(&s, op2 + op1 + '0');
            break;
         case '-':
            printf("%d - %d = %d\n", op2, op1, op2 - op1);
            push(&s, op2 - op1);
            break;
         case '*':
            printf("%d * %d = %d\n", op2, op1, op2 * op1);
            push(&s, op2 * op1);
            break;
         case '/':
            printf("%d / %d = %d\n", op2, op1, op2 / op1);
            push(&s, op2 / op1);
            break;
         case '^':
            printf("%d ^ %d = %.0f\n", op2, op1, pow(op2,op1));
            push(&s, pow(op2,op1));
            break;
         case '&':
            printf("%d & %d = %d\n", op2, op1, op2 && op1);
            push(&s, op2 && op1);
            break;
         case '|':
            printf("%d | %d = %d\n", op2, op1, op2 || op1);
            push(&s, op2 || op1);
            break;
         case '=':
            printf("%d = %d = %d\n", op2, op1, op2 == op1);
            push(&s, op2 ==  op1);
            break;
         case '>':
            printf("%d > %d = %d\n", op2, op1, op2 > op1);
            push(&s, op2 > op1);
            break;
         case '<':
            printf("%d < %d = %d\n", op2, op1, op2 < op1);
            push(&s, op2 < op1);
            break;
         }
      }
   }
   printf("%d", pop(&s));
}

int main(void)
{
   char* data = malloc(sizeof(char) * 50);
   printf("후위표기식을 입력하시오:");
   scanf("%s", data);
   check(data);
   return 0;
}
//34+2-222^*>73-2/52*&