#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#define MAX_STACK_SIZE 10000

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



int check_matching(const char *p,FILE *fp2)
{
    StackType s;
    char ch, open_ch;
    int i, n = strlen(p);     // n= 문자열의 길이
    init_stack(&s);         // 스택의 초기화
    
    for (i = 0; i < n; i++) {
        ch = p[i];      // ch = 다음 문자
        switch (ch) {
        case '\''://작은따옴표
            i++;
            while (p[i] != '\'') {
                i++;
            }
            break;
        case'\"'://큰따옴표
            i++;
            while (p[i] != '\"') {
                i++;
            }
            break;
        case '/'://주석
            if (p[i + 1] == '/') {// //주석처리
                while (p[i] != '\n')
                    i++;
            }
            else if (p[i + 1] == '*') {// /**/ 부분주석처리
                while (p[i] != '\0') {
                    i++;
                    if (p[i] == '*' && p[i + 1] == '/') {
                        i++;
                        break;//while문 탈출
                    }
                }
            }
            break;//case탈출
        case '(':   case '[':    case '{':
            push(&s, ch);
            printf("push: %c\n", ch);
            fprintf(fp2,"push: %c\n", ch);//파일입력
            break;
        case ')':   case ']':    case '}':
            if (is_empty(&s))  return 0;
            else {
                open_ch = pop(&s);
                printf("pop: %c\n", open_ch);
                fprintf(fp2,"pop: %c\n", open_ch);//파일입력
                if ((open_ch == '(' && ch != ')') ||
                    (open_ch == '[' && ch != ']') ||
                    (open_ch == '{' && ch != '}')) {
                    return 0;
                }
                break;
            }
        }
    }
    if (!is_empty(&s)) return 0; // 스택에 남아있으면 오류
    return 1;
}



int main(void) {
    FILE* fp1 = fopen("stack.in.txt", "r");
    if (fp1 == NULL) {
        printf("파일이 존재하지 않습니다.\n");
        exit(1);
    }

    char* p = malloc(sizeof(char) * MAX_STACK_SIZE);

    int i = 0;

    while (!feof(fp1)) {
        p[i] = fgetc(fp1);
        i++;
    }
    p[i] = NULL; //불필요한 데이터 공간 줄이기

    FILE* fp2 = fopen("stack.out.txt", "w");

    if (check_matching(p,fp2) == 1) {
        printf("괄호 매칭 성공\n");
        fprintf(fp2,"괄호 매칭 성공\n");
    }
    else {
        printf("\n괄호 매칭 실패\n");
        fprintf(fp2,"괄호 매칭 실패\n");
    }

    free(p);
    fclose(fp2);
    fclose(fp1);
    return 0;
}