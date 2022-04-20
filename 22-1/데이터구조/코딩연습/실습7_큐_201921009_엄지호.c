#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_QUEUE_SIZE 100

typedef struct {
    int id;
    int arrival_time;
    int service_time;
}QueueElement;

typedef struct {
    QueueElement node[MAX_QUEUE_SIZE];
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
    return ((q->front + 1) % MAX_QUEUE_SIZE == q->front);
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
            i = (i + 1) % MAX_QUEUE_SIZE;
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
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
    q->node[q->rear] = node;
}

QueueElement Dequeue2(Queue2 *q){
    if(IsEmpty2(q)){
        Error2("큐가 공백상태입니다");
    }
    q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    return q->node[q->front];
}

QueueElement Peek2(Queue2 *q){
    if(IsEmpty2(q)){
        Error2("큐가 공백상태입니다");
    }
    return q->node[(q->front + 1) % MAX_QUEUE_SIZE] ;
}


typedef int Data;

typedef struct {
    Data data[MAX_QUEUE_SIZE];
    int front;
    int rear;
}Queue;

void InitQueue(Queue *q){
    q->front = 0;
    q->rear = 0;
}

int IsEmpty(Queue *q){
    return (q->front == q->rear);
}

int IsFull(Queue *q){
    return ((q->front + 1) % MAX_QUEUE_SIZE == q->front);
}

void Error(char *message){
    fprintf(stderr, "%s\n", message);
    exit(1);
}

void PrintQueue(Queue *q){
    printf("QUEUE (front=%d rear=%d) = ", q->front, q->rear);
    if(!IsEmpty(q)){
        int i = q->front;
        do{
            i = (i + 1) % MAX_QUEUE_SIZE;
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
    if(IsFull(q)){
        Error("큐가 포화상태입니다");
    }
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
    q->data[q->rear] = data;
}

Data Dequeue(Queue *q){
    if(IsEmpty(q)){
        Error("큐가 공백상태입니다");
    }
    q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    return q->data[q->front];
}

Data Peek(Queue *q){
    if(IsEmpty(q)){
        Error("큐가 공백상태입니다");
    }
    return q->data[(q->front + 1) % MAX_QUEUE_SIZE] ;
}

void Matching(){
    Queue man;
    Queue woman;
    int man_idx = 0;
    int woman_idx = 0;
    InitQueue(&man);
    InitQueue(&woman);
    int length = 0;
    while(length < 100){
        int num = rand() % 2;
        // 일단 입장 시키고 그 다음에 대기, 매칭 판단
        if(num == 1){
            Enqueue(&man, man_idx);
            printf("남%d 입장 - ", man_idx++);
            if(!IsEmpty(&man) && !IsEmpty(&woman)){
                printf("여%d/남%d 매칭\n", Dequeue(&woman), Dequeue(&man));
            }
            else{
                printf("대기\n");
            }
        }
        else{
            Enqueue(&woman, woman_idx);
            printf("여%d 입장 - ", woman_idx++);
            if(!IsEmpty(&man) && !IsEmpty(&woman)){
                printf("여%d/남%d 매칭\n", Dequeue(&woman), Dequeue(&man));
            }
            else{
                printf("대기\n");
            }
        }
        length++;
    }
    while(!IsEmpty(&man)){
        printf("매칭되지 못한 남자%d\n", Dequeue(&man));
    }
    while(!IsEmpty(&woman)){
        printf("매칭되지 못한 여자%d\n", Dequeue(&woman));
    }
}

void Bank(){
    Queue2 q;
    InitQueue2(&q);
    int minutes = 60;
    int total_wait = 0;
    int total_customer = 0;
    int service_time = 0;
    int service_time_q2 = 0;
    int service_customer;
    int service_customer_q2;
    for(int clock = 0; clock < minutes; clock++){
        printf("===========================================================\n");
        printf("현재시간: %d\n", clock);
        if(rand() % 10 < 7){
            QueueElement customer;
            customer.id = total_customer++;
            customer.arrival_time = clock;
            customer.service_time = rand() % 3+1;
                Enqueue2(&q, customer);
                printf("고객 %d이 %d분에 들어옵니다. 업무처리시간: %d분\n", customer.id, customer.arrival_time, customer.service_time);
        }
        if(service_time > 0){
            printf("은행원 1 고객%d 업무를 처리중입니다.\n", service_customer);
            service_time--;
        }
        if(service_time_q2 > 0){
            printf("은행원 2 고객%d 업무를 처리중입니다.\n", service_customer_q2);
            service_time_q2--;
        }
        if(!IsEmpty2(&q)){
            if(service_time == 0){
                QueueElement customer = Dequeue2(&q);
                service_customer = customer.id;
                service_time = customer.service_time;
                printf("고객 %d의 업무를 %d분에 시작합니다. 대기시간은 %d분이었습니다.\n",
                    customer.id, clock, clock-customer.arrival_time);
                
                total_wait += clock - customer.arrival_time;
            }
            else if(service_time_q2 == 0){
                QueueElement customer = Dequeue2(&q);
                service_customer_q2 = customer.id;
                service_time_q2 = customer.service_time;
                printf("고객 %d의 업무를 %d분에 시작합니다. 대기시간은 %d분이었습니다.\n",
                    customer.id, clock, clock-customer.arrival_time);
                
                total_wait += clock - customer.arrival_time;
            }
            
        }
    }
    printf("전체 대기 시간: %d분\n", total_wait);
}

int main(){
    int qurter;
    printf("1. 대기열 문제\n");
    printf("2. 매칭 문제\n");
    scanf("%d", &qurter);
    switch (qurter)
    {
    case 1:
        Bank();
        break;    
    case 2:
        Matching();
        break;
    }
}