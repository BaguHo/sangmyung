#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define MAX_SIZE 101
#define MAX_QUEUE 10

typedef struct {
    int row;
    int column;
}Matrix;

typedef struct{
    Matrix node[MAX_SIZE];
    int top;
} Stack;

void InitStack(Stack *s)
{
    s->top = -1;
}

int SIsEmpty(Stack *s)
{
    return (s->top == -1);
}

int SIsFull(Stack *s)
{
    return (s->top == MAX_SIZE - 1);
}

void SPush(Stack *s, Matrix data)
{
    if (SIsFull(s))
    {
        fprintf(stderr, "ERROR\n");
        return;
    }
    else
    {
        s->node[++(s->top)] = data;
    }
}

Matrix SPop(Stack *s)
{
    if (SIsEmpty(s))
    {
        fprintf(stderr, "ERROR\n");
        exit(1);
    }
    else
    {
        return s->node[(s->top)--];
    }
}

Matrix SPeek(Stack *s)
{
    if (SIsEmpty(s))
    {
        fprintf(stderr, "������ ���� ERROR\n");
        exit(1);
    }
    else
    {
        return s->node[s->top];
    }
}

// 1. �̷��� ũ�⸦ 10*10���� �����, ������ �̿��ϴ� �̷�ã�� ������ �����ؼ� 
// Ż�⿡ �������� �� �Ա����� �ⱸ������ �̷� ��θ� ����Ͻÿ�. 

void PusLocation(char maze[][10], Stack *s, int row, int column){
    if(row < 0 || column < 0) return;
    if(maze[row][column] != '1' && maze[row][column] != '.'){
        Matrix temp;
        temp.row = row;
        temp.column = column;
        SPush(s, temp);
    }
}

void SearchExit(char maze[][10]){
    Stack s;
    InitStack(&s);
    Matrix cur = {1,0};
    Matrix temp;
    while(maze[cur.row][cur.column] != 'x'){
        maze[cur.row][cur.column] = '.';
        PusLocation(maze, &s, cur.row + 1, cur.column);
        PusLocation(maze, &s, cur.row , cur.column + 1);
        PusLocation(maze, &s, cur.row - 1, cur.column);
        PusLocation(maze, &s, cur.row, cur.column - 1);

        if(SIsEmpty(&s)){
            printf("����\n");
            return;
        }
        else{
            cur = SPop(&s);
            printf("%d %d -> \n", cur.row, cur.column);
        }
    }
    printf("����\n");
}

void Maze1(){
    char maze[10][10] = { {'1','1','1','1','1','1','1','1','1','1'},
                        {'0','0','0','0','1','0','0','0','0','1'},
                        {'1','0','0','0','1','1','0','0','0','x'},
                        {'1','0','1','1','1','0','0','1','0','1'},
                        {'1','0','0','0','1','1','0','1','0','1'},
                        {'1','0','1','0','1','1','0','1','0','1'},
                        {'1','0','1','0','1','0','0','1','0','1'},
                        {'1','0','1','0','1','0','1','1','0','1'},
                        {'1','0','1','0','0','0','0','1','0','x'},
                        {'1','1','1','1','1','1','1','1','1','1'}};
    SearchExit(maze);
}

// 2. ���� �̷ο� Ż���ΰ� �� ���� �̻� �ִ� ���, ��� ��θ� ã�� ���α׷����� �����Ͻÿ�. 

void SearchExit2(char maze[][10]){
    Stack s;
    InitStack(&s);
    Matrix cur = {1,0};
    Matrix temp;
    int count = 0;
    // 1. x�� ������ ã�� ������ �� ������ŭ ã�� ���α׷�
    // 2. x�� ������ �� �� �ִ� ���� ���� ������ ���ư��� ���α׷�
    PusLocation(maze, &s, cur.row + 1, cur.column);
    PusLocation(maze, &s, cur.row , cur.column + 1);
    PusLocation(maze, &s, cur.row - 1, cur.column);
    PusLocation(maze, &s, cur.row, cur.column - 1);
    
    while(!SIsEmpty(&s)){
        while(maze[cur.row][cur.column] != 'x'){
            maze[cur.row][cur.column] = '.';
            PusLocation(maze, &s, cur.row + 1, cur.column);
            PusLocation(maze, &s, cur.row , cur.column + 1);
            PusLocation(maze, &s, cur.row - 1, cur.column);
            PusLocation(maze, &s, cur.row, cur.column - 1);
            if(SIsEmpty(&s)){
                printf("����\n");
                return;
            }
            else{
                cur = SPop(&s);
                printf("%d %d -> \n", cur.row, cur.column);
            }
        }   
        if(maze[cur.row][cur.column] == 'x'){
            printf("%d��° x ã�� ����\n", ++count);
            cur = SPop(&s);
        } 
    }
}

void Maze2(){
    char maze[10][10] = { {'1','1','1','1','1','1','1','1','1','1'},
                        {'0','0','0','0','1','0','0','0','0','1'},
                        {'1','0','0','0','1','1','0','0','0','x'},
                        {'1','0','1','1','1','0','0','1','0','1'},
                        {'1','0','0','0','1','1','0','1','0','1'},
                        {'1','0','1','0','1','1','0','1','0','1'},
                        {'1','0','1','0','1','0','0','1','0','1'},
                        {'1','0','1','0','1','0','1','1','0','1'},
                        {'1','0','1','0','0','0','0','1','0','x'},
                        {'1','1','1','1','1','1','1','1','1','1'}};
    SearchExit2(maze);
}


// ===============================����======================================

typedef int Data;

typedef struct {
    Data data[MAX_QUEUE];
    int front;
    int rear;
}Queue;

void InitQueue(Queue *q){
    q->front = 0;
    q->rear = 0;
}

int QIsEmpty(Queue *q){
    return (q->front == q->rear);
}

int QIsFull(Queue *q){
    return ((q->front + 1) % MAX_QUEUE == q->front);
}

void Error(char *message){
    fprintf(stderr, "%s\n", message);
    exit(1);
}

void PrintQueue(Queue *q){
    printf("QUEUE (front=%d rear=%d) = ", q->front, q->rear);
    if(!QIsEmpty(q)){
        int i = q->front;
        do{
            i = (i + 1) % MAX_QUEUE;
            printf("%d | ", q->data[i]);
            if(i == q->rear){
                break;
            }
        }
        while(i != q->front);
    }
    printf("\n");
}

void Enqueue(Queue *q, Data data){
    if(QIsFull(q)){
        Error("ť�� ��ȭ�����Դϴ�");
    }
    q->rear = (q->rear + 1) % MAX_QUEUE;
    q->data[q->rear] = data;
}

Data Dequeue(Queue *q){
    if(QIsEmpty(q)){
        Error("ť�� ��������Դϴ�");
    }
    q->front = (q->front + 1) % MAX_QUEUE;
    return q->data[q->front];
}

Data QPeek(Queue *q){
    if(QIsEmpty(q)){
        Error("ť�� ��������Դϴ�");
    }
    return q->data[(q->front + 1) % MAX_QUEUE];
}

// 3. ������ ���� �߰� ���α׷��� �ۼ��ϱ�� �Ѵ�. 
// �� ���� ���� ť�� ����ϸ�, ���� ���л��� ���л��� ��� ť�̴�. 
//  ���ο� ��(��)�л��� ����� �ϸ� ��(��)�л� ť���� �����Ͽ� ������ ����ȴ�. 
// ���� ��(��)�л� ť�� ����ϰ� �ִ� �л��� ������ ��(��)�л��� ť�� ���� ��ٸ���� �Ѵ�. 
// - �������� �߻��Ǵ� Ȧ���� ¦���� ���� �л��� �����ϱ�� �Ѵ�. 
// - ť���� �л��� �̸��� �Էµȴ�. 
// - ��ü 100���� �л�(���� ����)�� ���ؼ� ������ �߰��ϸ�, 
// - ������ ����� ������, ȭ�鿡 ������ ����Ѵ�. 
// (��) 
// ��1 ���� - ��� 
// ��2 ���� - ��� 
// ��3 ���� - ��� 
// ��1 ���� - ��1/��1 ��Ī 
// ��2 ���� - ��2/��2 ��Ī

void Meetting(){
    Queue man;
    Queue woman;
    InitQueue(&man);
    InitQueue(&woman);
    int man_idx = 1;
    int woman_idx = 1;
    for(int i = 0; i < 100; i++){
        int num = rand();
        if(num % 2 == 0){
            printf("��%d ���� - ", man_idx);
            Enqueue(&man, man_idx++);
            if(!QIsEmpty(&woman) && !QIsEmpty(&man)){
                printf("��%d/��%d ��Ī\n", Dequeue(&woman), Dequeue(&man));
            }
            else{
                printf("���\n");
            }
        }
        else{
            printf("��%d ���� - ", woman_idx);
            Enqueue(&woman, woman_idx++);
            if(!QIsEmpty(&woman) && !QIsEmpty(&man)){
                printf("��%d/��%d ��Ī\n", Dequeue(&woman), Dequeue(&man));
            }
            else{
                printf("���\n");
            }
        }
    }
}

// 4. ���� 170���� �������� �ذ��ϱ� 
// ������ �������α׷�5.5�� ������� 1���̶�� �����ϰ� �ִ�. 
// ������ â������� 2���� ���� �����ϰ�, ť�� ������ �̿��ؼ� ���� ������ ���̽ÿ�. 

typedef struct {
    int id;
    int arrival_time;
    int service_time;
}QueueElement;

typedef struct {
    QueueElement node[MAX_QUEUE];
    int front;
    int rear;
}Queue2;

void InitQueue2(Queue2 *q){
    q->front = 0;
    q->rear = 0;
}

int IsEmpty2(Queue2 *q){
    return (q->front == q->rear);
}

int IsFull2(Queue2 *q){
    return ((q->front + 1) % MAX_QUEUE == q->front);
}

void Error2(char *message){
    fprintf(stderr, "%s\n", message);
    exit(1);
}

void PrintQueue2(Queue2 *q){
    printf("QUEUE (front=%d rear=%d) = ", q->front, q->rear);
    if(!IsEmpty2(q)){
        int i = q->front;
        do{
            i = (i + 1) % MAX_QUEUE;
            printf("%d | ", q->node[i]);
            if(i == q->rear){
                break;
            }
        }
        while(i != q->front);
    }
    printf("\n");
}

void Enqueue2(Queue2 *q, QueueElement node){
    if(IsFull2(q)){
        Error2("ť�� ��ȭ�����Դϴ�");
    }
    q->rear = (q->rear + 1) % MAX_QUEUE;
    q->node[q->rear] = node;
}

QueueElement Dequeue2(Queue2 *q){
    if(IsEmpty2(q)){
        Error2("ť�� ��������Դϴ�");
    }
    q->front = (q->front + 1) % MAX_QUEUE;
    return q->node[q->front];
}

QueueElement Peek2(Queue2 *q){
    if(IsEmpty2(q)){
        Error2("ť�� ��������Դϴ�");
    }
    return q->node[(q->front + 1) % MAX_QUEUE] ;
}

void BankTeller(){
    Queue2 q;
    InitQueue2(&q);
    int minuts = 60;
    int customer_num = 1;
    int total_wait = 0;
    int service_time_1 = 0;
    int service_time_2 = 0;
    int service_customer_1 = 0;
    int service_customer_2 = 0;
    for(int clock = 0; clock < minuts; clock++){
        // 1. ���� ť�� �ִ´�
        // 2. 1�� ������ ���� �ϰ� ���� ������ 1�� �������� ���� �����ش�
        // 3. 1�� ������ ���� �ϰ� ������ 2�� �������� ���� �����ش�.
        // 4. 1�� ����, 2�� ���� ��� ���񽺸� �ϰ� ������ ���� ť�� ����Ų��
        if(rand() % 10 < 5){
            QueueElement temp;
            temp.id = customer_num;
            temp.arrival_time = clock;
            temp.service_time = rand() % 3 + 1;
            Enqueue2(&q, temp);
            printf("��%d�� %d�п� ���ɴϴ�. ����ó���ð�: %d��\n", temp.id, temp.arrival_time, temp.service_time);
        }
        if(service_time_1 > 0){
            printf("�����1�� ��%d�� ������ ó�����Դϴ�\n", service_customer_1);
            service_time_1--;
        }
        if(service_time_2 > 0){
            printf("�����2�� ��%d�� ������ ó�����Դϴ�\n", service_customer_2);
            service_time_2--;
        }
        if(!IsEmpty2(&q)){
            if(service_time_1 == 0){
                QueueElement temp = Dequeue2(&q);
                service_time_1 = temp.service_time;
                service_customer_1 = temp.id;
                printf("��%d�� ������ %d�п� �����մϴ�. ����ó���ð�: %d\n", service_customer_1, clock, clock - temp.arrival_time);
                total_wait += clock - temp.arrival_time;
            }
            else if(service_time_2 == 0){
                QueueElement temp = Dequeue2(&q);
                service_time_2 = temp.service_time;
                service_customer_2 = temp.id;
                printf("��%d�� ������ %d�п� �����մϴ�. �����ð�: %d\n", service_customer_2, clock, clock - temp.arrival_time);
                total_wait += clock - temp.arrival_time;
            }
        }
    }
    printf("��ü ��� �ð�: %d \n", total_wait);
}

void main(){
    // Maze();
    // Maze2();
    // Meetting();
    BankTeller();
}

