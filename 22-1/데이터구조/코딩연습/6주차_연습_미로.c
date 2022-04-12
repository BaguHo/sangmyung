#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define MAX_LENGTH 101

typedef struct {
    int row;
    int column;
}Matrix;

typedef Matrix Data;

typedef struct{
    Data node[MAX_LENGTH];
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
    return (s->top == MAX_LENGTH - 1);
}

void Push(Stack *s, Data data)
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

Data Pop(Stack *s)
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

Data Peek(Stack *s)
{
    if (IsEmpty(s))
    {
        fprintf(stderr, "������ ���� ERROR\n");
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
        Data temp;
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
    Data cur = {1,0};
    int row, column;
    printf("(%d , %d) -> \n", cur.row, cur.column);
    PrintMaze(maze);

    while(maze[cur.row][cur.column] != 'x'){
        row = cur.row;
        column = cur.column;
        maze[row][column] = '.';
        PrintMaze(maze);
        PushLocation(maze ,s, row + 1, column + 1);
        PushLocation(maze ,s, row, column + 1);
        PushLocation(maze ,s, row - 1, column + 1);
        PushLocation(maze ,s, row, column - 1);
        PushLocation(maze ,s, row - 1, column - 1);
        PushLocation(maze ,s, row + 1, column);
        PushLocation(maze ,s, row + 1, column - 1);
        PushLocation(maze ,s, row - 1, column);
        // ���ٸ� ���� ��쿡 Pop�ϴ� �������� '1'�� ä���ְ� ������ ��� �ؾ��ұ�

        if(IsEmpty(s)){
            printf("����\n");
        }
        else{
            cur = Pop(s);
            // ���� ������ ��θ� ��ǥ�� ����ϰ� �ʹ�
            // printf("(%d , %d) -> \n", cur.row, cur.column);
        }
    }
    printf("����\n");
}

int main(){
    char maze[10][10] = { {'1','1','1','1','1','1','1','1','1','1'},
                        {'0','0','0','0','1','0','0','0','0','1'},
                        {'1','0','0','0','1','0','0','0','0','1'},
                        {'1','0','1','1','1','0','0','1','0','1'},
                        {'1','0','0','0','1','0','0','1','0','1'},
                        {'1','0','1','0','1','0','0','1','0','1'},
                        {'1','0','1','0','1','0','0','1','0','1'},
                        {'1','0','1','0','1','m','0','1','0','1'},
                        {'1','0','1','0','0','0','0','1','0','x'},
                        {'1','1','1','1','1','1','1','1','1','1'}
    };
    Stack s;
    InitStack(&s);
    SearchExit(maze, &s);
}
