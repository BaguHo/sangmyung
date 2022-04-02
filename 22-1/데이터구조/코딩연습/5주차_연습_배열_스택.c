#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#define MAX_LENGTH 101
#define TRUE 1
#define FALSE 0
//1�� ����
//1. ��ȣ ��Ī ��ȣ �ű�� ? ���� 143�� ���� 11
//���Ŀ� �ִ� ��ȣ�� ��ȣ�� ����ϴ� ���α׷��� �ۼ��϶�. 
//���� ��ȣ�� ���� ������ ��ȣ ��ȣ�� �ϳ��� �����Ѵ�.������ ��ȣ�� ������ ��Ī�Ǵ� ���� ��ȣ�� ��ȣ�� ����Ѵ�.
//((()) (()))
//12332 45541

//2. run-length ���� -  ���� 143�� ���� 12
//������ ���� ���ڿ��� �����ϴ� ���α׷��� �ۼ��Ͻÿ�.  "4a3b"�� 'a'�� 4��, 'b'�� 3�� �ִٴ� �ǹ��̴�.
//�̷��� ���� ����� ������ �����̶�� �Ѵ�.�ҹ��ڿ� �빮�ڴ� �������� �ʴ´�.
//����� ���ڿ������� �ҹ��ڷ� ����Ѵ�.������ peek() ������ ����غ���.
//  ��: ���ڿ� �Է� aaaAbBb     ������ 4a3b

//3. palindrome ? ���� 144�� ���� 16
//ȸ���� �յ� ��� �ʿ��� �о ���� �ܾ �ǹ��Ѵ�.���� ��� "eye" "madam" "race car"  ���̴�.
//���⼭ ���� �������̳� �����̽�, ��ҹ��� ���� �����ؾ� �Ѵ�.������ ����ؼ� �־��� ���ڿ���
//ȸ������ �ƴ��� �����ϴ� ���α׷��� �ۼ��Ͻÿ�.
//��: �Է� ���ڿ� "madam" �̸� ����� "madam�� ȸ���Դϴ�"

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
    printf("�� �� ������ Ǫ�ðڽ��ϱ�?\n");
    printf("1. ��ȣ �Է� ����\n");
    printf("2. ���ڿ� ���� ����\n");
    printf("3. ȸ�� �Ǻ� ����\n");
    scanf("%d", &qurter);

    if(qurter == 1){
        printf("��ȣ�� �Է����ּ���\n");
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
        printf("2������ - ���ڿ��� �Է����ּ���\n");
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
        //�Է¿� ������ ���� ��
        printf("3������ - ���ڿ��� �Է����ּ���\n");
        scanf("%[^\n]s", &str);
        int len = (int)strlen(str);

        for(int i = 0; i < len; i++){
            if('a' <= str[i] && str[i] <= 'z'){
                Push(&s, str[i]);
            }
            else{
                // ���⸦ ó������ ����
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
        //������ �̿��Ͽ� ȸ�� �˻�
        
        for(int i = 0; i < len; i++){
            Push(&s, str[i]);
        }
        for(int i = 0; i < len; i++){
            if(Pop(&s) != str[i]){
                printf("ȸ���� �ƴմϴ�\n");
                printf("%c", Peek(&s));
            }
        }
        printf("ȸ���Դϴ�\n");
    }
    free(result);
}