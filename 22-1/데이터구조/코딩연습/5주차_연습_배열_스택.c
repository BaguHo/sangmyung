#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#define MAX_LENGTH 101
#define TRUE 1
#define FALSE 0
//1번 문제
//1. 괄호 매칭 번호 매기기 ? 교재 143쪽 문제 11
//수식에 있는 괄호의 번호를 출력하는 프로그램을 작성하라. 
//왼쪽 괄호가 나올 때마다 괄호 번호는 하나씩 증가한다.오른쪽 괄호가 나오면 매칭되는 왼쪽 괄호의 번호를 출력한다.
//((()) (()))
//12332 45541

//2. run-length 압축 -  교재 143쪽 문제 12
//다음과 같이 문자열을 압축하는 프로그램을 작성하시오.  "4a3b"는 'a'가 4개, 'b'가 3개 있다는 의미이다.
//이러한 압축 방법을 런길이 압축이라고 한다.소문자와 대문자는 구분하지 않는다.
//압축된 문자열에서는 소문자로 출력한다.스택의 peek() 연산을 고려해보자.
//  예: 문자열 입력 aaaAbBb     압축결과 4a3b

//3. palindrome ? 교재 144쪽 문제 16
//회문은 앞뒤 어느 쪽에서 읽어도 같은 단어를 의미한다.예를 들면 "eye" "madam" "race car"  등이다.
//여기서 물로 구두점이나 스페이스, 대소문자 등은 무시해야 한다.스택을 사용해서 주어진 문자열이
//회문인지 아닌지 결정하는 프로그램을 작성하시오.
//예: 입력 문자열 "madam" 이면 출력은 "madam은 회문입니다"

typedef char Data;

typedef struct{
    Data node[MAX_LENGTH];
    int top_idx;
}StackNode;

typedef struct{
    StackNode* head;
}Stack;

void InitStack(Stack* s){
    s->head->top_idx = 0;
}

int IsEmpty(Stack *s){
    if(s->head->top_idx == 0){
        return TRUE;
    }
    else{
        return FALSE;
    }
}

void Push(Stack *s, Data data){
    s->head->node[s->head->top_idx++] = data;
}

Data Pop(Stack *s){
    if(s->head->top_idx == 0){
        printf("ERROR\n");
        return FALSE;
    }
    else{
        return s->head->node[s->head->top_idx--];
    }
}

Data Peek(Stack *s){
    if(s->head->top_idx == 0){
        printf("ERROR\n");
        return FALSE;
    }
    else{
        return s->head->node[s->head->top_idx];
    }
}

int main(){
    Stack s;
    InitStack(&s);
    int qurter;
    char* result = malloc(sizeof(char) * MAX_LENGTH);
    char str[MAX_LENGTH];
    int result_idx = 0;
    printf("몇 번 문제를 푸시겠습니까?\n");
    printf("1. 괄호 입력 문제\n");
    printf("2. 문자열 압축 문제\n");
    printf("3. 회문 판별 문제\n");
    scanf("%d", &qurter);

    if(qurter == 1){
        printf("괄호를 입력해주세요\n");
        scanf("%s", result);
        int idx = 1;
        for(int i = 0; result[i] != '\0'; i++){
            if(result[i] == '('){
                printf("%d ", idx);
                Push(&s, idx++);
            }
            else if(result[i] == ')'){
                idx--;
                printf("%d ", idx);
                Pop(&s);
            }
        }
        printf("\n");
    }
    else if(qurter == 2){
        printf("2번문제 - 문자열을 입력해주세요\n");
        scanf("%s", str);
        for(int i = 0; str[i] != '\0'; i++){
            if(i == 0){
                Push(&s, str[0]);
            }
            else if(str[i] == str[i - 1]){
                Push(&s, str[i]);
            }
            else{
                int i;
                char temp;
                result[result_idx + 1] = Pop(&s);
                for(i = 1; IsEmpty(&s) == TRUE; i++){
                    temp = Pop(&s);
                }
                result[result_idx] = i;
                result_idx += 2;
            }
        }
        for(int i = 0; result[i] != '\0'; i++){
            printf("%c", result[i]);
        }
        printf("\n");
    }
    else if(qurter == 3){
        //입력에 쓰레기 값이 들어감
        printf("3번문제 - 문자열을 입력해주세요\n");
        scanf("%[^\n]s", &str);
        int len = (int)strlen(str);

        for(int i = 0; i < len; i++){
            if('a' <= str[i] && str[i] <= 'z'){
                Push(&s, str[i]);
            }
            else{
                // 띄어쓰기를 처리하지 못함
                for(int k = i; k + 1 < len; k++){
                    str[k] = str[k + 1];
                    len--;
                }
            }
        }
        for(int i = 0; i < len; i++){
            printf("%c ", str[i]);
        }
        printf("\n");
        //스택을 이용하여 회문 검사
        
        for(int i = 0; i < len; i++){
            Push(&s, str[i]);
        }
        for(int i = 0; i < len; i++){
            if(Pop(&s) != str[i]){
                printf("회문이 아닙니다\n");
                printf("%c", Peek(&s));
            }
        }
        printf("회문입니다\n");
    }
    free(result);
}