#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define MAX_STACK_LENGTH 101

typedef struct {
    int row;
    int column;
}Matrix;

typedef struct{
    Matrix node[MAX_STACK_LENGTH];
    int top;
} Stack;

void InitStack(Stack *s)
{
    s->top = -1;
}

int IsEmpty(Stack *s)
{
    return (s->top == -1);
}

int IsFull(Stack *s)
{
    return (s->top == MAX_STACK_LENGTH - 1);
}

void Push(Stack *s, Matrix data)
{
    if (IsFull(s))
    {
        fprintf(stderr, "ERROR\n");
        return;
    }
    else
    {
        s->node[++(s->top)] = data;
    }
}

Matrix Pop(Stack *s)
{
    if (IsEmpty(s))
    {
        fprintf(stderr, "ERROR\n");
        exit(1);
    }
    else
    {
        return s->node[(s->top)--];
    }
}

Matrix Peek(Stack *s)
{
    if (IsEmpty(s))
    {
        fprintf(stderr, "데이터 없음 ERROR\n");
        exit(1);
    }
    else
    {
        return s->node[s->top];
    }
}

void PushLocation(char maze[][10] ,Stack *s, int row, int column){
    if(row < 0 || column < 0) return;
    if(maze[row][column] != '1' && maze[row][column] != '.'){
        Matrix temp;
        temp.row = row;
        temp.column = column;
        Push(s, temp);
    }
}

void PrintMaze(char maze[10][10]){
    for(int i = 0; i < 10; i++){
        for(int k = 0; k < 10; k++){
            printf("%c ", maze[i][k]);
        }
        printf("\n");
    }
    printf("======================================\n");
}

void SearchExit(char maze[][10], Stack *s){
    Matrix cur = {1,0};
    Matrix temp;
    int row, column;
    Stack way;
    printf("(1 , 0) -> \n");
    // 길이 아닌 경로는 지우기
    while(maze[cur.row][cur.column] != 'x'){
        row = cur.row;
        column = cur.column;
        maze[row][column] = '.';
        PushLocation(maze ,s, row, column + 1);
        PushLocation(maze ,s, row, column - 1);
        PushLocation(maze ,s, row + 1, column);
        PushLocation(maze ,s, row - 1, column);
        
        if(IsEmpty(s)){
            printf("실패\n");
            return;
        }
        else{
            cur = Pop(s);
            printf("(%d , %d) -> \n", cur.row, cur.column);
        }
    }
    printf("성공\n");
}

int main(){
    char maze[10][10] = { {'1','1','1','1','1','1','1','1','1','1'},
                        {'0','0','0','0','1','0','0','0','0','1'},
                        {'1','0','0','0','1','1','0','0','0','1'},
                        {'1','0','1','1','1','0','0','1','0','1'},
                        {'1','0','0','0','1','1','0','1','0','1'},
                        {'1','0','1','0','1','1','0','1','0','1'},
                        {'1','0','1','0','1','0','0','1','0','1'},
                        {'1','0','1','0','1','0','1','1','0','1'},
                        {'1','0','1','0','0','0','0','1','0','x'},
                        {'1','1','1','1','1','1','1','1','1','1'}
    };
    PrintMaze(maze);
    Stack s;
    InitStack(&s);
    SearchExit(maze, &s);
    // 함수를 하나 더 만들어서 갈 수 있었던 길만 계속 저장
}
