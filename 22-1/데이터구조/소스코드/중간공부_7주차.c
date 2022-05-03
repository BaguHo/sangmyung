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
        fprintf(stderr, "데이터 없음 ERROR\n");
        exit(1);
    }
    else
    {
        return s->node[s->top];
    }
}

// 1. 미로의 크기를 10*10으로 만들고, 스택을 이용하는 미로찾기 문제를 수정해서 
// 탈출에 성공했을 때 입구부터 출구까지의 미로 경로를 출력하시오. 

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
            printf("실패\n");
            return;
        }
        else{
            cur = SPop(&s);
            printf("%d %d -> \n", cur.row, cur.column);
        }
    }
    printf("성공\n");
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

// 2. 만약 미로에 탈출경로가 두 가지 이상 있는 경우, 모든 경로를 찾는 프로그램으로 변경하시오. 

void SearchExit2(char maze[][10]){
    Stack s;
    InitStack(&s);
    Matrix cur = {1,0};
    Matrix temp;
    int count = 0;
    // 1. x의 개수를 찾은 다음에 그 개수만큼 찾는 프로그램
    // 2. x를 만나도 갈 수 있는 곳이 없을 때까지 돌아가는 프로그램
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
                printf("실패\n");
                return;
            }
            else{
                cur = SPop(&s);
                printf("%d %d -> \n", cur.row, cur.column);
            }
        }   
        if(maze[cur.row][cur.column] == 'x'){
            printf("%d번째 x 찾기 성공\n", ++count);
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


// ===============================스택======================================

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
        Error("큐가 포화상태입니다");
    }
    q->rear = (q->rear + 1) % MAX_QUEUE;
    q->data[q->rear] = data;
}

Data Dequeue(Queue *q){
    if(QIsEmpty(q)){
        Error("큐가 공백상태입니다");
    }
    q->front = (q->front + 1) % MAX_QUEUE;
    return q->data[q->front];
}

Data QPeek(Queue *q){
    if(QIsEmpty(q)){
        Error("큐가 공백상태입니다");
    }
    return q->data[(q->front + 1) % MAX_QUEUE];
}

// 3. 간단한 미팅 중개 프로그램을 작성하기로 한다. 
// 두 개의 원형 큐를 사용하며, 각각 남학생과 여학생의 대기 큐이다. 
//  새로운 남(여)학생이 등록을 하면 여(남)학생 큐에서 삭제하여 미팅이 성사된다. 
// 만약 여(남)학생 큐에 대기하고 있는 학생이 없으면 남(여)학생은 큐에 들어가서 기다리기로 한다. 
// - 랜덤으로 발생되는 홀수와 짝수로 남녀 학생을 구분하기로 한다. 
// - 큐에는 학생의 이름이 입력된다. 
// - 전체 100명의 학생(남녀 랜덤)에 대해서 미팅을 중개하며, 
// - 미팅이 성사될 때마다, 화면에 내용을 출력한다. 
// (예) 
// 남1 입장 - 대기 
// 남2 입장 - 대기 
// 남3 입장 - 대기 
// 여1 입장 - 여1/남1 매칭 
// 여2 입장 - 여2/남2 매칭

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
            printf("남%d 입장 - ", man_idx);
            Enqueue(&man, man_idx++);
            if(!QIsEmpty(&woman) && !QIsEmpty(&man)){
                printf("여%d/남%d 매칭\n", Dequeue(&woman), Dequeue(&man));
            }
            else{
                printf("대기\n");
            }
        }
        else{
            printf("여%d 입장 - ", woman_idx);
            Enqueue(&woman, woman_idx++);
            if(!QIsEmpty(&woman) && !QIsEmpty(&man)){
                printf("여%d/남%d 매칭\n", Dequeue(&woman), Dequeue(&man));
            }
            else{
                printf("대기\n");
            }
        }
    }
}

// 4. 교재 170쪽의 도전문제 해결하기 
// 교재의 예제프로그램5.5는 은행원이 1명이라고 가정하고 있다. 
// 은행의 창구행원이 2명인 경우로 변경하고, 큐의 동작을 이용해서 서비스 과정을 보이시오. 

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
        Error2("큐가 포화상태입니다");
    }
    q->rear = (q->rear + 1) % MAX_QUEUE;
    q->node[q->rear] = node;
}

QueueElement Dequeue2(Queue2 *q){
    if(IsEmpty2(q)){
        Error2("큐가 공백상태입니다");
    }
    q->front = (q->front + 1) % MAX_QUEUE;
    return q->node[q->front];
}

QueueElement Peek2(Queue2 *q){
    if(IsEmpty2(q)){
        Error2("큐가 공백상태입니다");
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
        // 1. 고객을 큐에 넣는다
        // 2. 1번 직원이 서비스 하고 있지 않으면 1번 직원에게 고객을 보내준다
        // 3. 1번 직원이 서비스 하고 있으면 2번 직원에게 고객을 보내준다.
        // 4. 1번 직원, 2번 직원 모두 서비스를 하고 있으면 고객을 큐에 대기시킨다
        if(rand() % 10 < 5){
            QueueElement temp;
            temp.id = customer_num;
            temp.arrival_time = clock;
            temp.service_time = rand() % 3 + 1;
            Enqueue2(&q, temp);
            printf("고객%d이 %d분에 들어옵니다. 업무처리시간: %d분\n", temp.id, temp.arrival_time, temp.service_time);
        }
        if(service_time_1 > 0){
            printf("은행원1이 고객%d의 업무를 처리중입니다\n", service_customer_1);
            service_time_1--;
        }
        if(service_time_2 > 0){
            printf("은행원2이 고객%d의 업무를 처리중입니다\n", service_customer_2);
            service_time_2--;
        }
        if(!IsEmpty2(&q)){
            if(service_time_1 == 0){
                QueueElement temp = Dequeue2(&q);
                service_time_1 = temp.service_time;
                service_customer_1 = temp.id;
                printf("고객%d의 업무를 %d분에 시작합니다. 예상처리시간: %d\n", service_customer_1, clock, clock - temp.arrival_time);
                total_wait += clock - temp.arrival_time;
            }
            else if(service_time_2 == 0){
                QueueElement temp = Dequeue2(&q);
                service_time_2 = temp.service_time;
                service_customer_2 = temp.id;
                printf("고객%d의 업무를 %d분에 시작합니다. 업무시간: %d\n", service_customer_2, clock, clock - temp.arrival_time);
                total_wait += clock - temp.arrival_time;
            }
        }
    }
    printf("전체 대기 시간: %d \n", total_wait);
}

void main(){
    // Maze();
    // Maze2();
    // Meetting();
    BankTeller();
}

